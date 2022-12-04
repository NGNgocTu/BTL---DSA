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
    time t3;
    day t2;
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
        a.setDepartureTime(t3);
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
            cout << "\n";
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
    time t3;
    day t2;
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
        a.setDepartureTime(t3);
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

void inputTicket(listTicket &lc, int &n, listTrip lt, listLine ll, listAirline la)
{
    ticket a;
    string s;
    int t, t1, t2, i;
    nodeAirline *pa;
    nodeLine *pl;
    nodeTrip *pt;
    cout << "Input name: ";
    getline(cin, s);
    a.setNameOfClient(s);
    cout << "Input id: ";
    getline(cin, s);
    a.setIdOfClient(s);
    cout << "Input phone: ";
    getline(cin, s);
    a.setPhone(s);
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
    a.setId(pt->tdata.getId());
    a.setName(pt->tdata.getName());
    a.setTotal(pt->tdata.getTotalLine());
    a.setIdLine(pt->tdata.getIdLine());
    a.setTotalTrip(pt->tdata.getTotalTrip());
    a.setFrom(pt->tdata.getFrom());
    a.setTo(pt->tdata.getTo());
    a.setIdTrip(pt->tdata.getIdTrip());
    a.setDate(pt->tdata.getDate());
    a.setDepartureTime(pt->tdata.getDepartureTime());
    a.setPrice(pt->tdata.getPrice());
    a.setSeat(pt->tdata.getSeat());
    cout << "The trip have 6 rows of seat (A,B,C,D,F,G), each row have " << pt->tdata.getSeatOfRow() << " seats.\n";
    cout << "Choose seat: ";
    getline(cin, s);
    a.setSeatOfClient(s);
    addTicket(lc, createTicket(a));
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
        while (p)
        {
            cout << "The ticket " << i++ << ":\n";
            p->cdata.print();
            cout << "\n";
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

void delTicket(listTicket &lc, string id)
{
    nodeTicket *p = search(lc, id);
    if (p != NULL)
    {
        if (p->prev == NULL)
        {
            delBeforeTicket(lc);
            return;
        }
        if (p->next == NULL)
        {
            delAfterTicket(lc);
            return;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL;
        p->next = NULL;
        delete p;
    }
}

void editTicket(listTicket &lc, string id)
{
    nodeTicket *p = search(lc, id);
    int choose;
    string s;
    bool flag = false;
    if (p == NULL)
    {
        cout << "Ticket does not exist";
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
                cout << "Input your id: ";
                cin.ignore();
                getline(cin, s);
                p->cdata.setIdOfClient(s);
                break;
            case 3:
                cout << p->cdata.getPhone() << endl;
                cout << "Input your phone: ";
                cin.ignore();
                getline(cin, s);
                p->cdata.setPhone(s);
                break;
            case 4:
                cout << p->cdata.getSeatOfClient() << endl;
                cout << "Input your seat: ";
                cin.ignore();
                getline(cin, s);
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
}

void delAllTicket(listTicket &lc)
{
    nodeTicket *k = new nodeTicket;
    while (lc.head != NULL)
    {
        k = lc.head;
        lc.head = lc.head->next;
        lc.head->prev = NULL;
        delete k;
    }
}

void exportTicket(listTicket lc)
{
    ofstream f("TicketManagement.txt");
    nodeTicket *p = lc.head;
    while (p)
    {

        f << p->cdata.getName() << "," << p->cdata.getFrom() << "," << p->cdata.getTo() << "," << p->cdata.getDay() << "," << p->cdata.getMonth() << "," << p->cdata.getYear() << ","
          << p->cdata.getHour() << "," << p->cdata.getMinute() << "," << p->cdata.getNameOfClient() << "," << p->cdata.getIdOfClient() << "," << p->cdata.getPhone() << "," << p->cdata.getSeatOfClient();
        p = p->next;
        if (p)
            f << "\n";
    }
    f.close();
}

void menu(listAirline &la, listLine &ll, listTrip &lt, listTicket &lc)
{
    int choice;
    int nlc = 0;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t========== Management Ticket ==========";
        cout << "\n\t1. Book Ticket";
        cout << "\n\t2. Print booked ticket";
        cout << "\n\t3. Cancel ticket";
        cout << "\n\t4. Get Ticket list from file";
        cout << "\n\t5. Find ticket";
        cout << "\n\t6. Export Ticket list to file";
        cout << "\n\t7. Clear all tickets";
        cout << "\n\t0. Exit";
        cout << "\n\n\t\t========== END ==========";

        cout << "\nEnter request: ";
        cin >> choice;
        if (choice < 0 || choice > 7)
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
            printTicket(lc);
            system("pause");
        }
        else if (choice == 3)
        {
            cin.ignore();
            cout << "\nEnter id to delete: ";
            string id;
            getline(cin, id);
            delTicket(lc, id);
            cout << "Completed delete ticket!!\n";
            system("pause");
        }
        else if (choice == 4)
        {
            readTicket(lc, nlc, lt);
            cout << "Completed get ticket from file!!\n";
            system("pause");
        }
        else if (choice == 5)
        {
            cout << "\nEnter id to edit: ";
            string id;
            getline(cin, id);
            editTicket(lc, id);
            cout << "Saved change!!\n";
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
