#include <fstream>
#include <cstring>
#include "Airlines.cpp"
#include "Lines.cpp"
#include "Trip.cpp"
#include "Ticket.cpp"

struct nodeAirline
{
    airlines adata;
    nodeAirline *next;
    nodeAirline *prev;
};

struct listAirline
{
    nodeAirline *head;
    nodeAirline *tail;
};

struct nodeLine
{
    lines ldata;
    nodeLine *next;
    nodeLine *prev;
};

struct listLine
{
    nodeLine *head;
    nodeLine *tail;
};

struct nodeTrip
{
    trip tdata;
    nodeTrip *next;
    nodeTrip *prev;
};

struct listTrip
{
    nodeTrip *head;
    nodeTrip *tail;
};

struct nodeTicket
{
    ticket cdata;
    nodeTicket *next;
    nodeTicket *prev;
};

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
void readTicket(listTicket &lc, int &n, listTrip lt);
void inputTicket(listTicket &lc, int &n, listTrip lt, listLine ll, listAirline la);
void printTicket(listTicket lc);
nodeTicket *search(listTicket lc, string id);
void delBeforeTicket(listTicket &lc);
void delAfterTicket(listTicket &lc);
bool delTicket(listTicket &lc, string id);
void editTicket(listTicket &lc, string id);
void delAllTicket(listTicket &lc);
void exportTicket(listTicket lc);
void printTicketOfTrip(listTicket lc, listTrip lt, listLine ll, listAirline la);
void menu(listAirline &la, listLine &ll, listTrip &lt, listTicket &lc);
bool findEmptySeat(listTicket lc, nodeTicket *a, string s);
nodeTrip *findTrip(listTrip lt, listLine ll, listAirline la);
bool checkSeat(string s, int n);
string formatSeat(string s);

int main()
{
    listAirline la;
    listLine ll;
    listTrip lt;
    listTicket lc;
    int nla = 0, nll = 0, nlt = 0, nlc = 0;
    createEmptyAirline(la);
    createEmptyLine(ll);
    createEmptyTrip(lt);
    createEmptyTicket(lc);
    readAirline(la, nla);
    readLine(ll, nll, la);
    readTrip(lt, nlt, ll);
    menu(la, ll, lt, lc);
    return 0;
}

void createEmptyAirline(listAirline &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void createEmptyLine(listLine &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void createEmptyTrip(listTrip &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void createEmptyTicket(listTicket &l)
{
    l.head = NULL;
    l.tail = NULL;
}

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
        a.setSeat(a.getSeatOfRow() * 6);
        addTrip(lt, createTrip(a));
        if (f.eof())
            break;
        else
            n++;
    }
    f.close();
}

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

void readTicket(listTicket &lc, int &n, listTrip lt)
{
    int t;
    timeFly t3;
    dayFly t2;
    string s;
    char ch;
    ticket a;
    nodeTrip *p;
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
        getline(f, s, '\n');
        a.setSeatOfClient(s);
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
        addTicket(lc, createTicket(a));
        n++;
        if (f.eof())
            break;
    }
    f.close();
}

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
    cin >> t;
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
    cin >> t;
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
    cin >> t;
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

void inputTicket(listTicket &lc, int &n, listTrip lt, listLine ll, listAirline la)
{
    ticket a;
    string s;
    nodeTrip *pt;
    nodeTicket *p;
    cout << "Input name: ";
    getline(cin, s);
    a.setNameOfClient(s);
    do
    {
        cout << "Input id (has 9 digits): ";
        getline(cin, s);
    } while (s.length() < 9 || s.length() > 9);
    a.setIdOfClient(s);
    do
    {
        cout << "Input phone (has 10 digits): ";
        getline(cin, s);
    } while (s.length() < 10 || s.length() > 10);
    a.setPhone(s);
    do
    {
        pt = findTrip(lt, ll, la);
        if (pt->tdata.getSeat() == 0)
            cout << "The tickets were sold out!!\nPlease choose again\n\n";
    } while (pt->tdata.getSeat() <= 0);
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
}

void printTicket(listTicket lc)
{
    nodeTicket *p;
    int i = 1;
    if (lc.head == NULL)
        cout << "Empty ticket\n";
    else
    {
        p = lc.head;
        cout << "|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
        cout << "| No |   Name of Airline          |  From                |  To             |  Day         |  Time   |  Price   |  Name of customer            |  ID         |  Phone       |  Seat |\n";
        cout << "|==================================================================================================================================================================================|\n";
        while (p)
        {
            cout << "| " << i++ << " ";
            p->cdata.print();
            p = p->next;
        }
    }
}

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

void editTicket(listTicket &lc, string id)
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
            cout << "\nSelect the information you want to edit ";
            cout << "\n1. Name";
            cout << "\n2. ID";
            cout << "\n3. Phone number";
            cout << "\n4. Seat";
            cout << "\n5. Exit edit\n";
            cin >> choose;
            switch (choose)
            {
            case 1:
                cout << p->cdata.getNameOfClient() << endl;
                cout << "Input your name: ";
                cin.ignore();
                getline(cin, s);
                p->cdata.setNameOfClient(s);
                break;
            case 2:
                cout << p->cdata.getIdOfClient() << endl;
                do
                {
                    cout << "Input id (has 9 digits): ";
                    getline(cin, s);
                } while (s.length() < 9 || s.length() > 9);
                p->cdata.setIdOfClient(s);
                break;
            case 3:
                cout << p->cdata.getPhone() << endl;
                do
                {
                    cout << "Input phone (has 10 digits): ";
                    getline(cin, s);
                } while (s.length() < 10 || s.length() > 10);
                p->cdata.setPhone(s);
                break;
            case 4:
                cout << p->cdata.getSeatOfClient() << endl;
                do
                {
                    cout << "The trip have 6 rows of seat (A,B,C,D,F,G), each row have " << p->cdata.getSeatOfRow() << " seats.\n";
                    cout << "Empty " << p->cdata.getSeat() << " seats.\n";
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
                cout << "\nPlease select again";
                editTicket(lc, id);
                break;
            }
        } while (flag == false);
    cout << "Saved change!!\n";
}

void delAllTicket(listTicket &lc)
{
    nodeTicket *k = new nodeTicket;
    while (lc.head != NULL)
    {
        k = lc.head;
        lc.head = lc.head->next;
        delete k;
    }
}

void exportTicket(listTicket lc)
{
    ofstream f("TicketManagement.txt");
    nodeTicket *p = lc.head;
    while (p)
    {

        f << p->cdata.getName() << "," << p->cdata.getFrom() << "," << p->cdata.getTo() << "," << p->cdata.getDayFly() << "," << p->cdata.getMonth() << "," << p->cdata.getYear() << ","
          << p->cdata.getHour() << "," << p->cdata.getMinute() << "," << p->cdata.getNameOfClient() << "," << p->cdata.getIdOfClient() << "," << p->cdata.getPhone() << "," << p->cdata.getSeatOfClient();
        p = p->next;
        if (p)
            f << "\n";
    }
    f.close();
}

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
            if (pt->tdata.getFrom() == a->cdata.getFrom() && pt->tdata.getTo() == a->cdata.getTo())
            {
                cout << "The ticket " << i++ << ":\n";
                a->cdata.print();
                cout << "\n";
                flag = true;
            }
        a = a->next;
    }
    if (flag == false)
        cout << "Empty ticket!!\n";
}

void menu(listAirline &la, listLine &ll, listTrip &lt, listTicket &lc)
{
    int choice;
    int nlc = 0;
    while (true)
    {
        system("cls");
        cout << "\n\n#-#-#   -- Management Ticket --   #-#-#\n";
        cout << "#                                     #";
        cout << "\n#           1. Book Ticket            #";
        cout << "\n#     2. Get Ticket list from file    #";
        cout << "\n#           3. Cancel ticket          #";
        cout << "\n#           4. Edit ticket            #";
        cout << "\n#           5. Find ticket            #";
        cout << "\n#    6. Export Ticket list to file    #";
        cout << "\n#        7. Print booked ticket       #";
        cout << "\n#       8. Print ticket of trip       #";
        cout << "\n#         9. Clear all tickets        #";
        cout << "\n#              0. Exit                #";
        cout << "\n#                                     #";
        cout << "\n#-#-#-#-#-#    -- END --    #-#-#-#-#-#";
        cout << "\n\nEnter request: ";
        cin >> choice;
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
            editTicket(lc, id);
            system("pause");
        }
        else if (choice == 5)
        {
            cout << "\nEnter id to find: ";
            cin.ignore();
            string id;
            getline(cin, id);
            nodeTicket *p = search(lc, id);
            p->cdata.print();
            cout << "\n";
            system("pause");
        }
        else if (choice == 6)
        {
            exportTicket(lc);
            cout << "Completed!!\n";
            system("pause");
        }
        else if (choice == 7)
        {
            printTicket(lc);
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

string formatSeat(string s)
{
    if (s.length() < 3)
        s = "0" + s;
    if (s[2] >= 'a' && s[2] <= 'f')
        s[2] -= 32;
    return s;
}

bool checkSeat(string s, int n)
{
    s = formatSeat(s);
    if (s[2] == 'E' || s[2] > 'F')
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
