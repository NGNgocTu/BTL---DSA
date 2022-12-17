#include <fstream>
#include <cstring>
#include <limits>
#include <dos.h>
#include "Airlines.cpp"
#include "Lines.cpp"
#include "Trip.cpp"
#include "Ticket.cpp"

// Cấu trúc cho node máy bay
struct nodeAirline
{
    airlines adata;
    nodeAirline *next;
    nodeAirline *prev;
};

// Cấu trúc cho danh sách liên kết đôi cho máy bay
struct listAirline
{
    nodeAirline *head;
    nodeAirline *tail;
};

// Cấu trúc cho node cho tuyến bay
struct nodeLine
{
    lines ldata;
    nodeLine *next;
    nodeLine *prev;
};

// Cấu trúc cho danh sách liêm kết đôi cho tuyến bay
struct listLine
{
    nodeLine *head;
    nodeLine *tail;
};

// Cấu trúc cho node cho chuyến bay
struct nodeTrip
{
    trip tdata;
    nodeTrip *next;
    nodeTrip *prev;
};

// Cấu trúc cho danh sách liên kết đôi cho chuyến bay
struct listTrip
{
    nodeTrip *head;
    nodeTrip *tail;
};

// Cấu trúc cho node cho vé
struct nodeTicket
{
    ticket cdata;
    nodeTicket *next;
    nodeTicket *prev;
};

// Cấu trúc cho danh sách liên kết đôi cho vé
struct listTicket
{
    nodeTicket *head;
    nodeTicket *tail;
};

void createEmptyAirline(listAirline &l);
void createEmptyLine(listLine &l);
void createEmptyTrip(listTrip &l);
void createEmptyTicket(listTicket &l);
nodeAirline *createAirline(airlines a);
void addAirline(listAirline &la, nodeAirline *p);
void readAirline(listAirline &la, int &n);
void printAirline(listAirline la);
nodeLine *createLine(lines a);
void addLine(listLine &la, nodeLine *p);
void readLine(listLine &ll, int &n, listAirline la);
void printLine(listLine ll);
nodeTrip *createTrip(trip a);
void addTrip(listTrip &lt, nodeTrip *p);
void readTrip(listTrip &lt, int &n, listLine ll);
void printTrip(listTrip lt);
nodeTicket *createTicket(ticket a);
void addTicket(listTicket &lc, nodeTicket *p);
void insertTicket(listTicket &lc, nodeTicket *q, nodeTicket *p);
void readTicket(listTicket &lc, int &n, listTrip lt);
void inputTicket(listTicket &lc, int &n, listTrip lt, listLine ll, listAirline la);
void printTicket(listTicket lc);
nodeTicket *search(listTicket lc, string id);
void delBeforeTicket(listTicket &lc);
void delAfterTicket(listTicket &lc);
bool delTicket(listTicket &lc, string id);
void editTicket(listTicket &lc, string id, listTrip &lt);
void delAllTicket(listTicket &lc);
void exportTicket(listTicket lc);
void printTicketOfTrip(listTicket lc, listTrip lt, listLine ll, listAirline la);
void menu(listAirline &la, listLine &ll, listTrip &lt, listTicket &lc);
bool findEmptySeat(listTicket lc, nodeTicket *a, string s);
nodeTrip *findTrip(listTrip lt, listLine ll, listAirline la);
bool checkSeat(string s, int n);
string formatSeat(string s);
nodeTrip *chooseShip(listTrip lt);
void printOfShip(listTicket lc);
int getUserInputMenu();
void printMenu();
void printOfTicketShip(listTicket lc);
bool checkNum(string s);
int checkInput(int t);
bool checkName(string s);
bool checkID(listTicket &lc, string s);
bool checkPhone(listTicket &lc, string s);
string formatName(string s);

// Chương trình chính
int main()
{
    // Khai báo biến
    listAirline la;
    listLine ll;
    listTrip lt;
    listTicket lc;
    int nla = 0, nll = 0, nlt = 0, nlc = 0, t;
    // Tạo các danh sách liên kết đôi rỗng
    createEmptyAirline(la);
    createEmptyLine(ll);
    createEmptyTrip(lt);
    createEmptyTicket(lc);
    // Đọc dữ liệu máy bay, chuyến, tuyến
    readAirline(la, nla);
    readLine(ll, nll, la);
    readTrip(lt, nlt, ll);
    readTicket(lc, nlc, lt);
    // Bắt đầu điều hướng chương trình
    menu(la, ll, lt, lc);
    return 0;
}

// Khởi tạo danh sách máy bay rỗng
void createEmptyAirline(listAirline &l)
{
    l.head = NULL;
    l.tail = NULL;
}

// Khởi tạo danh sách đường bay rỗng
void createEmptyLine(listLine &l)
{
    l.head = NULL;
    l.tail = NULL;
}

// Khởi tạo danh sách chuyến bay rỗng
void createEmptyTrip(listTrip &l)
{
    l.head = NULL;
    l.tail = NULL;
}

// Khởi tạo danh sách vé rỗng
void createEmptyTicket(listTicket &l)
{
    l.head = NULL;
    l.tail = NULL;
}

// Tạo một máy bay
nodeAirline *createAirline(airlines a)
{
    nodeAirline *p;
    p = new nodeAirline;
    if (p == NULL)
        exit(1);
    p->adata = a;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

// Thêm một máy bay vào danh sách
void addAirline(listAirline &la, nodeAirline *p)
{
    if (la.head == NULL)
    {
        la.head = p;
        la.tail = la.head;
    }
    else
    {
        la.tail->next = p;
        p->prev = la.tail;
        la.tail = p;
    }
}

// Đọc danh sách máy bay từ file InputAirlines.txt vào danh sách
void readAirline(listAirline &la, int &n)
{
    int t;
    string s;
    char ch;
    airlines a;
    ifstream f("InputAirlines.txt");
    while (!f.eof())
    {
        f >> t;
        a.setId(t);
        f.get(ch);
        getline(f, s, ',');
        a.setName(s);
        f >> t;
        a.setTotal(t);
        addAirline(la, createAirline(a));
        if (f.eof())
            break;
        else
            n++;
    }
    f.close();
}

// Xuất thông tin máy bay ra màn hình (Chuẩn bị cho phân quyền cao hơn)
void printAirline(listAirline la)
{
    nodeAirline *p;
    int i = 1;
    if (la.head == NULL)
        cout << "Empty airline\n";
    else
    {
        p = la.head;
        while (p)
        {
            cout << "The " << i++ << " airline:\n";
            p->adata.print();
            cout << "\n";
            p = p->next;
        }
    }
}

// Tạo một tuyến bay
nodeLine *createLine(lines a)
{
    nodeLine *p;
    p = new nodeLine;
    if (p == NULL)
        exit(1);
    p->ldata = a;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

// Thêm một tuyến bay vào danh sách
void addLine(listLine &la, nodeLine *p)
{
    if (la.head == NULL)
    {
        la.head = p;
        la.tail = la.head;
    }
    else
    {
        la.tail->next = p;
        p->prev = la.tail;
        la.tail = p;
    }
}

// Đọc danh sách tuyến bay từ file InputLines.txt vào danh sách
void readLine(listLine &ll, int &n, listAirline la)
{
    lines a;
    nodeAirline *p = la.head;
    int t, t1 = p->adata.getTotalLine();
    string s;
    char ch;
    ifstream f("InputLines.txt");
    while (!f.eof())
    {
        if (n < t1)
        {
            a.setId(p->adata.getId());
            a.setTotal(p->adata.getTotalLine());
            a.setName(p->adata.getName());

            if (n == t1 - 1)
            {
                p = p->next;
                if (p != NULL)
                {
                    t = p->adata.getTotalLine();
                    t1 += t;
                }
            }
        }
        f >> t;
        a.setIdLine(t);
        f.get(ch);
        f >> t;
        a.setTotalTrip(t);
        f.get(ch);
        getline(f, s, ',');
        a.setFrom(s);
        getline(f, s);
        a.setTo(s);
        addLine(ll, createLine(a));
        if (f.eof())
            break;
        else
            n++;
    }
    f.close();
}

// Xuất thông tin tuyến bay ra màn hình (Chuẩn bị cho phân quyền cao hơn)
void printLine(listLine ll)
{
    nodeLine *p;
    int i = 1;
    if (ll.head == NULL)
        cout << "Empty line\n";
    else
    {
        p = ll.head;
        while (p)
        {
            cout << "The " << i++ << " line:\n";
            p->ldata.print();
            cout << "\n";
            p = p->next;
        }
    }
}

// Tạo một chuyến bay
nodeTrip *createTrip(trip a)
{
    nodeTrip *p;
    p = new nodeTrip;
    if (p == NULL)
        exit(1);
    p->tdata = a;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

// Thêm một chuyến bay vào danh sách
void addTrip(listTrip &lt, nodeTrip *p)
{
    if (lt.head == NULL)
    {
        lt.head = p;
        lt.tail = lt.head;
    }
    else
    {
        lt.tail->next = p;
        p->prev = lt.tail;
        lt.tail = p;
    }
}

// Đọc danh sách chuyến bay từ file InputTrip.txt vào danh sách
void readTrip(listTrip &lt, int &n, listLine ll)
{
    trip a;
    nodeLine *p = ll.head;
    int t, t1 = p->ldata.getTotalTrip();
    timeFly t3;
    dayFly t2;
    char ch;
    ifstream f("InputTrip.txt");
    while (!f.eof())
    {
        if (n < t1)
        {
            a.setId(p->ldata.getId());
            a.setTotal(p->ldata.getTotalLine());
            a.setName(p->ldata.getName());
            a.setIdLine(p->ldata.getIdLine());
            a.setFrom(p->ldata.getFrom());
            a.setTotalTrip(p->ldata.getTotalTrip());
            a.setTo(p->ldata.getTo());
            if (n == t1 - 1)
            {
                p = p->next;
                if (p != NULL)
                {
                    t = p->ldata.getTotalTrip();
                    t1 += t;
                }
            }
        }

        f >> t;
        a.setIdTrip(t);
        f.get(ch);
        f >> t2.d;
        f.get(ch);
        f >> t2.m;
        f.get(ch);
        f >> t2.y;
        f.get(ch);
        a.setDate(t2);
        f >> t3.hour;
        f.get(ch);
        f >> t3.minute;
        f.get(ch);
        a.setDepartureTimeFly(t3);
        f >> t;
        a.setPrice(t);
        f.get(ch);
        f >> t;
        a.setSeatOfRow(t);
        f.get(ch);
        f >> t;
        a.setTotalWeight(t);
        f.get(ch);
        f >> t;
        a.setPricePerKilo(t);
        f.get(ch);
        a.setSeat(a.getSeatOfRow() * 6);
        addTrip(lt, createTrip(a));
        if (f.eof())
            break;
        else
            n++;
    }
    f.close();
}

// Xuất thông tin chuyến bay ra màn hình (Chuẩn bị cho phân quyền cao hơn)
void printTrip(listTrip lt)
{
    nodeTrip *p;
    int i = 1;
    if (lt.head == NULL)
        cout << "Empty trip\n";
    else
    {
        p = lt.head;
        while (p)
        {
            cout << "The " << i++ << " trip:\n";
            p->tdata.print();
            cout << "\n\n";
            p = p->next;
        }
    }
}

// Tạo một vé
nodeTicket *createTicket(ticket a)
{
    nodeTicket *p;
    p = new nodeTicket;
    if (p == NULL)
        exit(1);
    p->cdata = a;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

// Thêm một vé vào cuối danh sách
void addTicket(listTicket &lc, nodeTicket *p)
{
    if (lc.head == NULL)
    {
        lc.head = p;
        lc.tail = lc.head;
    }
    else
    {
        lc.tail->next = p;
        p->prev = lc.tail;
        lc.tail = p;
    }
}

// Thêm một vé vào sau vé bất kì
void insertTicket(listTicket &lc, nodeTicket *q, nodeTicket *p)
{
    if (q == lc.tail)
        addTicket(lc, p);
    else
    {
        p->next = q->next;
        q->next->prev = p;
        q->next = p;
        p->prev = q;
    }
}

// Đọc danh sách vé từ file TicketManagement.txt vào danh sách
void readTicket(listTicket &lc, int &n, listTrip lt)
{
    int t;
    timeFly t3;
    dayFly t2;
    string s;
    char ch;
    ticket a;
    nodeTrip *p;
    nodeTicket *nt = lc.head;
    ifstream f("TicketManagement.txt");
    while (!f.eof())
    {

        getline(f, s, ',');
        a.setName(s);
        getline(f, s, ',');
        a.setFrom(s);
        getline(f, s, ',');
        a.setTo(s);
        f >> t2.d;
        f.get(ch);
        f >> t2.m;
        f.get(ch);
        f >> t2.y;
        f.get(ch);
        a.setDate(t2);
        f >> t3.hour;
        f.get(ch);
        f >> t3.minute;
        f.get(ch);
        a.setDepartureTimeFly(t3);
        getline(f, s, ',');
        a.setNameOfClient(s);
        getline(f, s, ',');
        a.setIdOfClient(s);
        getline(f, s, ',');
        a.setPhone(s);
        getline(f, s, ',');
        a.setSeatOfClient(s);
        f >> t;
        a.setWeight(t);
        f.get(ch);
        f >> t;
        a.setPriceOfPackage(t);
        f.get(ch);
        p = lt.head;
        while (p)
        {
            if (a.getName() == p->tdata.getName())
                if (a.getFrom() == p->tdata.getFrom() && a.getTo() == p->tdata.getTo())
                {
                    a.setPrice(p->tdata.getPrice());
                    a.setId(p->tdata.getId());
                    p->tdata.setSeat(p->tdata.getSeat() - 1);
                    a.setSeatOfRow(p->tdata.getSeatOfRow());
                    break;
                }
            p = p->next;
        }
        if (search(lc, a.getIdOfClient()) == NULL)
            insertTicket(lc, nt, createTicket(a));
        nt = search(lc, a.getIdOfClient());
        n++;
        if (f.eof())
            break;
    }
    f.close();
}

// Tìm thông tin cho một chuyến bay
nodeTrip *findTrip(listTrip lt, listLine ll, listAirline la)
{
    int t, i, t1, t2;
    nodeAirline *pa;
    nodeLine *pl;
    nodeTrip *pt;
    cout << "\nChoose airline: \n\n";
    pa = la.head;
    i = 0;
    while (pa)
    {
        cout << i + 1 << " ";
        pa->adata.printNameOfAirline();
        cout << "\n";
        pa = pa->next;
        i++;
    }
    t = checkInput(i);
    pa = la.head;
    i = 0;
    while (i < t - 1)
    {
        pa = pa->next;
        i++;
    }
    cout << "\nChoose line: \n\n";
    pl = ll.head;
    t1 = 0;
    if (t - 1 != 0)
    {
        i = 0;
        pa = la.head;
        while (i < t - 1)
        {
            t2 = pa->adata.getTotalLine();
            t1 += t2;
            i++;
            pa = pa->next;
        }
    }
    t2 = pa->adata.getTotalLine() + t1;
    i = 0;
    while (i < t1)
    {
        pl = pl->next;
        i++;
    }
    while (i < t2)
    {
        cout << i + 1 - t1 << " ";
        pl->ldata.printOfLine();
        cout << "\n";
        i++;
        pl = pl->next;
    }
    t = checkInput(i - t1);
    t += t1;
    cout << "\nChoose Trip: \n\n";
    t1 = 0;
    if (t - 1 != 0)
    {
        i = 0;
        pl = ll.head;
        while (i < t - 1)
        {
            t2 = pl->ldata.getTotalTrip();
            t1 += t2;
            i++;
            pl = pl->next;
        }
    }
    t2 = pl->ldata.getTotalTrip() + t1;
    i = 0;
    pt = lt.head;
    while (i < t1)
    {
        pt = pt->next;
        i++;
    }
    while (i < t2)
    {
        cout << i + 1 - t1 << " ";
        pt->tdata.printOfTrip();
        cout << "\n";
        i++;
        pt = pt->next;
    }
    t = checkInput(i - t1);
    cin.ignore();
    cout << "\n";
    t = t - 1 + t1;
    i = 0;
    pt = lt.head;
    while (i < t)
    {
        pt = pt->next;
        i++;
    }
    return pt;
}

// Tìm thông tin chở hàng
nodeTrip *chooseShip(listTrip lt)
{
    int t, i = 0;
    nodeTrip *pt = lt.head;
    cout << "\nChoose Trip: \n\n";
    cout << "|----------------------------------------------------------------------------------------------------------------------------------------------|\n";
    cout << "| No |   Name of Airline           |  From                |  To             |  Day         |  Time   |  Total weight(kg)  | Price per kilogram |\n";
    cout << "|==============================================================================================================================================|\n";
    while (pt)
    {
        if (pt->tdata.getPricePerKilo() != 0)
        {
            i + 1 < 10 ? cout << "| 0" << i + 1 << " " : cout << "| " << i + 1 << " ";
            pt->tdata.printOfShip();
            i++;
        }
        pt = pt->next;
    }
    t = checkInput(i);
    cin.ignore();
    cout << "\n";
    t = t - 1;
    i = -1;
    pt = lt.head;
    while (i < t)
    {
        if (pt->tdata.getPricePerKilo() != 0)
            i++;
        if (i == t)
            return pt;
        pt = pt->next;
    }
    return NULL;
}

// Nhập thông tin vé từ bàn phím
void inputTicket(listTicket &lc, int &n, listTrip lt, listLine ll, listAirline la)
{
    ticket a;
    string s;
    int t, ch;
    double weight;
    nodeTrip *pt;
    nodeTicket *p;
    do
    {
        cout << "Input name: ";
        getline(cin, s);
        s = formatName(s);
    } while (checkName(s) == false);
    a.setNameOfClient(s);
    do
    {
        cout << "Input id (has 9 digits): ";
        getline(cin, s);
    } while (s.length() < 9 || s.length() > 9 || checkNum(s) == false || checkID(lc, s) == false);
    a.setIdOfClient(s);
    do
    {
        cout << "Input phone (has 10 digits): ";
        getline(cin, s);
    } while (s.length() < 10 || s.length() > 10 || checkNum(s) == false || checkPhone(lc, s) == false);
    a.setPhone(s);
    cout << "Choose you option:\n - 1 - Book a ticket\n - 2 - Ship a package\n";
    ch = checkInput(2);
    if (ch == 1)
    {
        do
        {
            pt = findTrip(lt, ll, la);
            if (pt->tdata.getSeat() == 0)
                cout << "The tickets were sold out!!\nPlease choose again\n\n";
        } while (pt->tdata.getSeat() <= 0);
    }
    else
    {
        cout << "Input the weight of package from 1 to 10.000 kg: ";
        weight = checkInput(10000);
        a.setWeight(weight);
        pt = chooseShip(lt);
        int sum = 0;
        if (a.getWeight() <= 1)
            sum = pt->tdata.getPricePerKilo();
        else if (a.getWeight() <= 2)
            sum = pt->tdata.getPricePerKilo() * (0.15 * a.getWeight() + 0.85);
        else
            sum = pt->tdata.getPricePerKilo() * (1.05 + 0.1 * a.getWeight());
        a.setPriceOfPackage(sum);
        a.setTotalWeight(pt->tdata.getTotalWeight());
        pt->tdata.setTotalWeight(pt->tdata.getTotalWeight() - weight);
        a.setPricePerKilo(pt->tdata.getPricePerKilo());
    }
    a.setId(pt->tdata.getId());
    a.setName(pt->tdata.getName());
    a.setTotal(pt->tdata.getTotalLine());
    a.setIdLine(pt->tdata.getIdLine());
    a.setTotalTrip(pt->tdata.getTotalTrip());
    a.setFrom(pt->tdata.getFrom());
    a.setTo(pt->tdata.getTo());
    a.setIdTrip(pt->tdata.getIdTrip());
    a.setDate(pt->tdata.getDate());
    a.setDepartureTimeFly(pt->tdata.getDepartureTimeFly());
    a.setPrice(pt->tdata.getPrice());
    a.setSeat(pt->tdata.getSeat());
    a.setSeatOfRow(pt->tdata.getSeatOfRow());
    p = createTicket(a);
    if (ch == 1)
        do
        {
            cout << "The trip have 6 rows of seat (A,B,C,D,F,G), each row have " << pt->tdata.getSeatOfRow() << " seats.\n";
            cout << "Empty " << p->cdata.getSeat() << " seats.\n";
            cout << "Example choose is 02C or 10F ...\n";
            cout << "Choose seat: ";
            getline(cin, s);
            cout << "\n";
            s = formatSeat(s);
            p->cdata.setSeatOfClient(s);
        } while (findEmptySeat(lc, p, s) == false || checkSeat(s, pt->tdata.getSeatOfRow()) == false);
    addTicket(lc, p);
    pt->tdata.setSeat(pt->tdata.getSeat() - 1);
    n++;
    exportTicket(lc);
}

// Xuất thông tin vé ra màn hình
void printTicket(listTicket lc)
{
    nodeTicket *p;
    int i = 1;
    if (lc.head == NULL)
        cout << "Empty ticket\n";
    else
    {
        p = lc.head;
        cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
        cout << "| No |   Name of Airline           |  From                |  To             |  Day         |  Time   |  Price   |  Name of customer            |  ID         |  Phone       |  Seat |\n";
        cout << "|===================================================================================================================================================================================|\n";
        while (p)
        {
            if (p->cdata.getPriceOfPackage() == 0)
            {
                i < 10 ? cout << "| 0" << i++ << " " : cout << "| " << i++ << " ";
                p->cdata.print();
            }
            p = p->next;
        }
    }
}

// Tìm vé theo mã định danh
nodeTicket *search(listTicket lc, string id)
{
    nodeTicket *p;
    p = lc.head;
    while ((p != NULL) && (p->cdata.getIdOfClient().compare(id) != 0))
    {
        p = p->next;
    }
    return p;
}

// Xóa một vé ở đầu danh sách
void delBeforeTicket(listTicket &lc)
{
    if (lc.head == NULL)
    {
        return;
    }
    else
    {
        nodeTicket *p = lc.head;
        lc.head = lc.head->next;
        lc.head->prev = NULL;
        delete p;
    }
}

// Xóa một vé ở cuối danh sách
void delAfterTicket(listTicket &lc)
{
    if (lc.head == NULL)
    {
        return;
    }
    else
    {
        nodeTicket *p = lc.tail;
        lc.tail = lc.tail->prev;
        lc.tail->next = NULL;
        delete p;
    }
}

// Xóa một vé theo mã định danh
bool delTicket(listTicket &lc, string id)
{
    bool flag = false;
    nodeTicket *p = search(lc, id);
    if (p != NULL)
    {
        flag = true;
        if (p->prev == NULL)
        {
            delBeforeTicket(lc);
            return flag;
        }
        if (p->next == NULL)
        {
            delAfterTicket(lc);
            return flag;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL;
        p->next = NULL;
        delete p;
    }
    return flag;
}

// Chỉnh sửa thông tin vé theo mã định danh
void editTicket(listTicket &lc, string id, listTrip &lt)
{
    nodeTicket *p = search(lc, id);
    int choose;
    string s;
    bool flag = false;
    if (p == NULL)
    {
        cout << "Ticket does not exist\n";
        return;
    }
    else
        do
        {
            if (p->cdata.getWeight() == 0)
            {
                cout << "\nSelect the information you want to edit ";
                cout << "\n1. Name";
                cout << "\n2. ID";
                cout << "\n3. Phone number";
                cout << "\n4. Seat";
                cout << "\n5. Exit edit\n";
                cin >> choose;
            }
            else
            {
                cout << "\nSelect the information you want to edit ";
                cout << "\n1. Name";
                cout << "\n2. ID";
                cout << "\n3. Phone number";
                cout << "\n4. Exit edit\n";
                cin >> choose;
                if (choose == 4)
                    choose = 5;
            }

            switch (choose)
            {
            case 1:
                cout << p->cdata.getNameOfClient() << endl;
                do
                {
                    cout << "Input name: ";
                    getline(cin, s);
                    s = formatName(s);
                } while (checkName(s) == false);
                p->cdata.setNameOfClient(s);
                break;
            case 2:
                cout << p->cdata.getIdOfClient() << endl;
                do
                {
                    cout << "Input id (has 9 digits): ";
                    getline(cin, s);
                } while (s.length() < 9 || s.length() > 9 || checkNum(s) == false || checkID(lc, s) == false);
                p->cdata.setIdOfClient(s);
                break;
            case 3:
                cout << p->cdata.getPhone() << endl;
                do
                {
                    cout << "Input phone (has 10 digits): ";
                    getline(cin, s);
                } while (s.length() < 10 || s.length() > 10 || checkNum(s) == false || checkPhone(lc, s) == false);
                p->cdata.setPhone(s);
                break;
            case 4:
                cout << p->cdata.getSeatOfClient() << endl;
                nodeTrip *pt;
                pt = lt.head;
                while (pt)
                {
                    if (p->cdata.getName() == pt->tdata.getName())
                        if (p->cdata.getFrom() == pt->tdata.getFrom() && p->cdata.getTo() == pt->tdata.getTo())
                            break;
                    pt = pt->next;
                }
                do
                {
                    cout << "The trip have 6 rows of seat (A,B,C,D,F,G), each row have " << p->cdata.getSeatOfRow() << " seats.\n";
                    cout << "Empty " << pt->tdata.getSeat() << " seats.\n";
                    cout << "Example choose is 02C or 10F ...\n";
                    cout << "Choose seat: ";
                    cin.ignore();
                    getline(cin, s);
                    cout << "\n";
                    s = formatSeat(s);
                    if (s == p->cdata.getSeatOfClient())
                        break;
                } while (findEmptySeat(lc, p, s) == false || checkSeat(s, p->cdata.getSeatOfRow()) == false);
                p->cdata.setSeatOfClient(s);
                break;
            case 5:
                flag = true;
                break;
            default:
                bool error_detected;
                cout << "\nError. Choose again.\n";
                do
                {
                    error_detected = false;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<int>::max(), '\n');
                        continue;
                    }
                } while (error_detected);
            }
        } while (flag == false);
    cout << "Saved change!!\n";
    exportTicket(lc);
}

// Xóa tất cả vé
void delAllTicket(listTicket &lc)
{
    nodeTicket *k = new nodeTicket;
    while (lc.head != NULL)
    {
        k = lc.head;
        lc.head = lc.head->next;
        delete k;
    }
    createEmptyTicket(lc);
}

// Xuất thông tin vé ra file TicketManagement.txt
void exportTicket(listTicket lc)
{
    ofstream f("TicketManagement.txt");
    nodeTicket *p = lc.head;
    while (p)
    {

        f << p->cdata.getName() << "," << p->cdata.getFrom() << "," << p->cdata.getTo() << "," << p->cdata.getDayFly() << "," << p->cdata.getMonth() << "," << p->cdata.getYear() << ","
          << p->cdata.getHour() << "," << p->cdata.getMinute() << "," << p->cdata.getNameOfClient() << "," << p->cdata.getIdOfClient() << "," << p->cdata.getPhone() << "," << p->cdata.getSeatOfClient()
          << "," << p->cdata.getWeight() << "," << p->cdata.getPriceOfPackage();
        p = p->next;
        if (p)
            f << "\n";
    }
    f.close();
}

// Xuất thông tin vé theo một chuyến ra màn hình
void printTicketOfTrip(listTicket lc, listTrip lt, listLine ll, listAirline la)
{
    nodeTicket *a;
    string s;
    int i;
    nodeTrip *pt;
    bool flag = false;
    pt = findTrip(lt, ll, la);
    i = 1;
    a = lc.head;
    while (a)
    {
        if (pt->tdata.getName() == a->cdata.getName())
            if (pt->tdata.getFrom() == a->cdata.getFrom() && pt->tdata.getTo() == a->cdata.getTo() && pt->tdata.getDepartureTimeFly().hour == a->cdata.getDepartureTimeFly().hour && pt->tdata.getDepartureTimeFly().minute == a->cdata.getDepartureTimeFly().minute)
                if (a->cdata.getSeatOfClient() != "")
                {
                    if (flag == false)
                    {
                        cout << "List of customer:\n";
                        cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
                        cout << "| No |   Name of Airline           |  From                |  To             |  Day         |  Time   |  Price   |  Name of customer            |  ID         |  Phone       |  Seat |\n";
                        cout << "|===================================================================================================================================================================================|\n";
                        flag = true;
                    }
                    i < 10 ? cout << "| 0" << i++ << " " : cout << "| " << i++ << " ";
                    a->cdata.print();
                }
        a = a->next;
    }
    flag = false;
    a = lc.head;
    while (a)
    {
        if (pt->tdata.getName() == a->cdata.getName())
            if (pt->tdata.getFrom() == a->cdata.getFrom() && pt->tdata.getTo() == a->cdata.getTo() && pt->tdata.getDepartureTimeFly().hour == a->cdata.getDepartureTimeFly().hour && pt->tdata.getDepartureTimeFly().minute == a->cdata.getDepartureTimeFly().minute)
                if (a->cdata.getWeight() != 0)
                {
                    if (flag == false)
                    {
                        cout << "List of package:\n";
                        cout << "|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
                        cout << "| No |   Name of Airline           |  From                |  To             |  Day         |  Time   |  Price   |  Name of customer            |  ID         |  Phone       |  weight(kg)  |  Price          |\n";
                        cout << "|============================================================================================================================================================================================================|\n";
                        flag = true;
                    }
                    i < 10 ? cout << "| 0" << i++ << " " : cout << "| " << i++ << " ";
                    a->cdata.printTicketOfShip();
                }
        a = a->next;
    }
    if (lc.head == lc.tail)
        cout << "Empty ticket!!\n";
}

// Menu điều hướng cho toàn chương trình
void menu(listAirline &la, listLine &ll, listTrip &lt, listTicket &lc)
{
    int choice;
    int nlc = 0;
    while (true)
    {
        printMenu();
        choice = getUserInputMenu();
        if (choice < 0 || choice > 9)
        {
            cout << "\nYour request is not valid, please re-enter\n";
            system("pause");
        }
        else if (choice == 1)
        {
            int nlc;
            cin.ignore();
            inputTicket(lc, nlc, lt, ll, la);
            cout << "Completed book ticket!!\n";
            system("pause");
        }
        else if (choice == 2)
        {
            readTicket(lc, nlc, lt);
            cout << "Completed get ticket from file!!\n";
            system("pause");
        }
        else if (choice == 3)
        {
            cin.ignore();
            cout << "\nEnter id to delete: ";
            string id;
            getline(cin, id);
            if (delTicket(lc, id))
                cout << "Completed delete ticket!!\n";
            else
                cout << "Id is not found! Can't delete!\n";
            system("pause");
        }
        else if (choice == 4)
        {
            cout << "\nEnter id to edit: ";
            cin.ignore();
            string id;
            getline(cin, id);
            editTicket(lc, id, lt);
            system("pause");
        }
        else if (choice == 5)
        {
            cout << "\nEnter id to find: ";
            cin.ignore();
            string id;
            getline(cin, id);
            nodeTicket *p = search(lc, id);
            if (p != NULL)
            {
                if (p->cdata.getSeatOfClient() != "")
                {
                    cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
                    cout << "| No |   Name of Airline           |  From                |  To             |  Day         |  Time   |  Price   |  Name of customer            |  ID         |  Phone       |  Seat |\n";
                    cout << "|===================================================================================================================================================================================|\n";
                    cout << "| 01 ";
                    p->cdata.print();
                }
                if (p->cdata.getWeight() != 0)
                {
                    cout << "|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
                    cout << "| No |   Name of Airline           |  From                |  To             |  Day         |  Time   |  Price   |  Name of customer            |  ID         |  Phone       |  weight(kg)  |  Price          |\n";
                    cout << "|============================================================================================================================================================================================================|\n";
                    cout << "| 01 ";
                    p->cdata.printTicketOfShip();
                }
            }
            else
                cout << "Not Found!!";
            cout << "\n";
            system("pause");
        }
        else if (choice == 6)
        {
            printTicket(lc);
            system("pause");
        }
        else if (choice == 7)
        {
            printOfTicketShip(lc);
            system("pause");
        }
        else if (choice == 8)
        {
            printTicketOfTrip(lc, lt, ll, la);
            system("pause");
        }
        else if (choice == 9)
        {
            delAllTicket(lc);
            cout << "All tickets cleared!!\n";
            system("pause");
        }
        else
        {
            break;
        }
    }
}

// Xuất thông báo menu
void printMenu()
{
    system("cls");
    cout << "\n\n#-#-#   -- Management Ticket --   #-#-#\n";
    cout << "#                                     #";
    cout << "\n#           1. Book Ticket            #";
    cout << "\n#     2. Get Ticket list from file    #";
    cout << "\n#           3. Cancel ticket          #";
    cout << "\n#           4. Edit ticket            #";
    cout << "\n#           5. Find ticket            #";
    cout << "\n#        6. Print booked ticket       #";
    cout << "\n#         7. Print booked ship        #";
    cout << "\n#       8. Print ticket of trip       #";
    cout << "\n#        9. Clear all tickets         #";
    cout << "\n#              0. Exit                #";
    cout << "\n#                                     #";
    cout << "\n#-#-#-#-#-#    -- END --    #-#-#-#-#-#";
    cout << "\n\nEnter request: ";
}

// Kiểm tra ghế còn trống không
bool findEmptySeat(listTicket lc, nodeTicket *a, string s)
{
    nodeTicket *p = lc.head;
    while (p)
    {
        if (p->cdata.getSeatOfClient() == s && p->cdata.getFrom() == a->cdata.getFrom() && p->cdata.getTo() == a->cdata.getTo() && p->cdata.getName() == a->cdata.getName() && p->cdata.getDepartureTimeFly().hour == a->cdata.getDepartureTimeFly().hour && p->cdata.getDepartureTimeFly().minute == a->cdata.getDepartureTimeFly().minute)
            return false;
        p = p->next;
    }
    return true;
}

// Định dạng thông tin ghế
string formatSeat(string s)
{
    if (s.length() < 3)
        s = "0" + s;
    if (s[2] >= 'a' && s[2] <= 'g')
        s[2] -= 32;
    return s;
}

// Kiểm tra thông tin ghế nhập vào đúng hay không
bool checkSeat(string s, int n)
{
    s = formatSeat(s);
    if (s[2] == 'E' || s[2] > 'G' || s[2] < 'A')
        return false;
    string s1 = to_string(n), s2 = "00";
    if (s1.length() < 2)
        s1 = "0" + s1;
    s1 = s1 + s[2];
    s2 = s2 + s[2];
    if (s > s1 || s2 >= s)
        return false;
    return true;
}

// xuất thông tin chuyến hàng hóa
void printOfShip(listTicket lc)
{
    int i = 0;
    bool flag = false;
    nodeTicket *p = lc.head;
    while (p)
    {
        if (p->cdata.getWeight() != 0)
        {
            if (flag == false)
            {
                cout << "|----------------------------------------------------------------------------------------------------------------------------------------------|\n";
                cout << "| No |   Name of Airline           |  From                |  To             |  Day         |  Time   |  Total weight(kg)  | Price per kilogram |\n";
                cout << "|==============================================================================================================================================|\n";
                flag = true;
            }
            i + 1 < 10 ? cout << "| 0" << i + 1 << " " : cout << "| " << i + 1 << " ";
            p->cdata.printOfShip();
            i++;
        }
        p = p->next;
    }
    if (flag == false)
        cout << "Empty package!!\n";
}

// Xuất thông tin vé hàng hóa
void printOfTicketShip(listTicket lc)
{
    int i = 0;
    bool flag = false;
    nodeTicket *p = lc.head;
    while (p)
    {
        if (p->cdata.getWeight() != 0)
        {
            if (flag == false)
            {
                cout << "|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
                cout << "| No |   Name of Airline           |  From                |  To             |  Day         |  Time   |  Price   |  Name of customer            |  ID         |  Phone       |  weight(kg)  |  Price          |\n";
                cout << "|============================================================================================================================================================================================================|\n";
                flag = true;
            }
            i + 1 < 10 ? cout << "| 0" << i + 1 << " " : cout << "| " << i + 1 << " ";
            p->cdata.printTicketOfShip();
            i++;
        }
        p = p->next;
    }
    if (flag == false)
        cout << "Empty package!!\n";
}

// Lấy thông tin nhập từ người dùng menu
int getUserInputMenu()
{
    int user_data;
    bool error_detected;
    do
    {
        error_detected = false;
        cin >> user_data;

        if (cin.fail())
        {
            cout << "\nError. Re input.\n";
            system("pause");
            cin.clear();
            printMenu();
            cin.ignore(numeric_limits<int>::max(), '\n');
            error_detected = true;
            continue;
        }
    } while (error_detected);

    return user_data;
}

// Kiểm tra sdt, id
bool checkNum(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

// Kiểm tra nhập lựa chọn
int checkInput(int t)
{
    bool error_detected;
    int s;
    do
    {
        error_detected = false;
        cin >> s;
        if (cin.fail() || s < 1 || s > t)
        {
            cout << "\nError. Re choose.\n";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            error_detected = true;
        }
    } while (error_detected);
    return s;
}

// Kiểm tra tên
bool checkName(string s)
{
    for (int i = 0; i < s.length(); i++)
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] < 'Z') || s[i] == ' ')
            continue;
        else
            return false;
    return true;
}

// kiểm tra mã định danh
bool checkID(listTicket &lc, string s)
{
    nodeTicket *p = lc.head;
    while (p)
    {
        if (p->cdata.getIdOfClient() == s)
            return false;
        p = p->next;
    }
    return true;
}

// Kiểm tra số điện thoại
bool checkPhone(listTicket &lc, string s)
{
    nodeTicket *p = lc.head;
    while (p)
    {
        if (p->cdata.getPhone() == s)
            return false;
        p = p->next;
    }
    return true;
}

// Format name
string formatName(string s)
{
    int t = s.length(), i = 0;
    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] -= 32;
    for (int i = 0; i < t; i++)
    {
        if (s[i] == ' ' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
            s[i + 1] -= 32;
    }
    t = s.length();
    while (s[i] == ' ')
        i++;
    s = s.substr(i, t - i);
    t = s.length();
    i = t - 1;
    while (s[i] == ' ')
        i--;
    s = s.substr(0, i + 1);
    while (s.find("  ") < s.length())
        s = s.erase(s.find("  "), 1);
    return s;
}