#include <fstream>
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

struct nodeClient
{
    ticket cdata;
    nodeClient *next;
    nodeClient *prev;
};

struct listClient
{
    nodeClient *head;
    nodeClient *tail;
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

void createEmptyClient(listClient &l)
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
                t = p->adata.getTotalLine();
                t1 += t;
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
                t = p->ldata.getTotalTrip();
                t1 += t;
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

int main()
{
    listAirline la;
    listLine ll;
    listTrip lt;
    listClient lc;
    int nla = 0, nll = 0, nlt = 0, nlc = 0;
    createEmptyAirline(la);
    createEmptyLine(ll);
    createEmptyTrip(lt);
    createEmptyClient(lc);
    readAirline(la, nla);
    // printAirline(la);
    readLine(ll, nll, la);
    // printLine(ll);
    readTrip(lt, nlt, ll);
    cout << "Ngu";
    printTrip(lt);
    return 0;
}