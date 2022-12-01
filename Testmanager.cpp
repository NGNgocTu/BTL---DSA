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

// void printAirline(listAirline &l)
// {
//     nodeAirline p;
// }

int main()
{
    listAirline la;
    createEmptyAirline(la);
    listLine ll;
    listTrip lt;
    listClient lc;
    return 0;
}