#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Staff
{
    string sName, sId, sPass;
};

struct nodeStaff
{
    Staff data;
    nodeStaff *next;
    nodeStaff *prev;
};

struct listStaff
{
    nodeStaff *head;
    nodeStaff *tail;
};

void createEmptyStaff(listStaff &l)
{
    l.head = l.tail = NULL;
}

nodeStaff *createStaff(Staff a)
{
    nodeStaff *p;
    p = new nodeStaff;
    if (p == NULL)
        exit(1);
    p->data = a;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void addStaff(listStaff &lc, nodeStaff *p)
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

void readStaff(listStaff &l)
{
    string s;
    Staff a;
    ifstream f("Staff.txt");
    while (!f.eof())
    {
        getline(f, s, ',');
        a.sName = s;
        getline(f, s, ',');
        a.sId = s;
        getline(f, s, '\n');
        a.sPass = s;
        addStaff(l, createStaff(a));
        if (f.eof())
            break;
    }
    f.close();
}

void printStaff(listStaff &l)
{
    nodeStaff *p = l.head;
    if (l.head == NULL)
        cout << "Empty staff\n";
    else
        while (p)
        {
            cout << setw(30) << left << p->data.sName << setw(10) << p->data.sId << "\n";
            p = p->next;
        }
}

nodeStaff *searchStaff(listStaff &l, string id)
{
    nodeStaff *p = l.head;
    if (l.head == NULL)
        cout << "Empty staff\n";
    else
        while (p)
        {
            if (p->data.sId == id)
                return p;
            p = p->next;
        }
    return NULL;
}

void delBeforeStaff(listStaff &lc)
{
    if (lc.head == NULL)
    {
        return;
    }
    else
    {
        nodeStaff *p = lc.head;
        lc.head = lc.head->next;
        lc.head->prev = NULL;
        delete p;
    }
}

void delAfterStaff(listStaff &lc)
{
    if (lc.head == NULL)
    {
        return;
    }
    else
    {
        nodeStaff *p = lc.tail;
        lc.tail = lc.tail->prev;
        lc.tail->next = NULL;
        delete p;
    }
}

bool delStaff(listStaff &lc, string id)
{
    bool flag = false;
    nodeStaff *p = searchStaff(lc, id);
    if (p != NULL)
    {
        flag = true;
        if (p->prev == NULL)
        {
            delBeforeStaff(lc);
            return flag;
        }
        if (p->next == NULL)
        {
            delAfterStaff(lc);
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

void inputStaff(listStaff &l)
{
    Staff a;
    cout << "Enter name: ";
    getline(cin, a.sName);
    cout << "Enter id: ";
    getline(cin, a.sId);
    cout << "Enter Pass: ";
    getline(cin, a.sPass);
    addStaff(l, createStaff(a));
}

void print()
{
    system("pause");
    system("cls");
    cout << "Hello World!!\n\n";
}

void managament()
{
    ifstream f("Managament.txt");
    string s1, s2;
    int t = 0;
    getline(f, s1);
    do
    {
        cout << "Input your password here: ";
        getline(cin, s2);
        if (s1 == s2)
        {
            cout << "Compelete!!\n";
            print();
            break;
        }

        else
            t++;
        if (t == 3)
            cout << "Error!!\n";
    } while (t < 3);
}

void staff()
{
    listStaff l;
    createEmptyStaff(l);
    readStaff(l);
    printStaff(l);
    cout << searchStaff(l, "215112")->data.sName << "\n";
    delStaff(l, "215112");
    inputStaff(l);
    printStaff(l);
}

int main()
{
    int t;
    // managament();
    staff();
    return 0;
}