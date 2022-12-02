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

void createEmptyAirline(listAirline &l)
{
    l.head = NULL;
    l.tail = NULL;
}

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

void createEmptyLine(listLine &l)
{
    l.head = NULL;
    l.tail = NULL;
}

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

void createEmptyTrip(listTrip &l)
{
    l.head = NULL;
    l.tail = NULL;
}

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

void createEmptyClient(listClient &l)
{
    l.head = NULL;
    l.tail = NULL;
}

nodeAirline *CreateAirline(airlines a)
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

void inputAirline(listAirline &la, int &n)
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
        cout << n << "\n";
        addAirline(la, CreateAirline(a));
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
    inputAirline(la, nla);
    printAirline(la);
    return 0;
}