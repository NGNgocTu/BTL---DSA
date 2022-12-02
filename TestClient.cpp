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

void readAirline(airlines a[], int &n)
{
    int t;
    string s;
    char ch;
    ifstream f("InputAirlines.txt");
    while (!f.eof())
    {
        f >> t;
        a[n].setId(t);
        f.get(ch);
        getline(f, s, ',');
        a[n].setName(s);
        f >> t;
        a[n].setTotal(t);
        if (f.eof())
            break;
        else
            n++;
    }
    f.close();
}

void writeAirline(airlines a[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << "The " << i + 1 << " airline:\n";
        a[i].print();
        cout << "\n";
    }
}

void readLine(lines a[], int &n, airlines la[], int nla)
{
    int t, i = 0, t1 = la[i].getTotalLine();
    string s;
    char ch;
    ifstream f("InputLines.txt");
    while (!f.eof())
    {
        if (n < t1)
        {
            a[n].setId(la[i].getId());
            a[n].setTotal(la[i].getTotalLine());
            a[n].setName(la[i].getName());

            if (n == t1 - 1)
            {
                i++;
                t = la[i].getTotalLine();
                t1 += t;
            }
        }
        f >> t;
        a[n].setIdLine(t);
        f.get(ch);
        f >> t;
        a[n].setTotalTrip(t);
        f.get(ch);
        getline(f, s, ',');
        a[n].setFrom(s);
        getline(f, s);
        a[n].setTo(s);
        if (f.eof())
            break;
        else
            n++;
    }
    f.close();
}

void writeLine(lines a[], int n)
{
    for (int i = 0; i <= n; i++)
    {

        cout << "The line " << i + 1 << ":\n";
        a[i].print();
        cout << "\n";
    }
}

void readTrip(trip a[], int &n, lines ll[], int nll)
{
    int t, i = 0, t1 = ll[i].getTotalTrip();
    time t3;
    day t2;
    char ch;
    ifstream f("InputTrip.txt");
    while (!f.eof())
    {
        if (n < t1)
        {
            a[n].setId(ll[i].getId());
            a[n].setTotal(ll[i].getTotalLine());
            a[n].setName(ll[i].getName());
            a[n].setIdLine(ll[i].getIdLine());
            a[n].setFrom(ll[i].getFrom());
            a[n].setTotalTrip(ll[i].getTotalTrip());
            a[n].setTo(ll[i].getTo());
            if (n == t1 - 1)
            {
                i++;
                t = ll[i].getTotalTrip();
                t1 += t;
            }
        }
        f >> t;
        a[n].setIdTrip(t);
        f.get(ch);
        f >> t2.d;
        f.get(ch);
        f >> t2.m;
        f.get(ch);
        f >> t2.y;
        f.get(ch);
        a[n].setDate(t2);
        f >> t3.hour;
        f.get(ch);
        f >> t3.minute;
        f.get(ch);
        a[n].setDepartureTime(t3);
        f >> t;
        a[n].setPrice(t);
        f.get(ch);
        f >> t;
        a[n].setSeatOfRow(t);
        f.get(ch);
        a[n].setSeat(a[n].getSeatOfRow() * 6);
        if (f.eof())
            break;
        else
            n++;
    }
    f.close();
}

void writeTrip(trip a[], int n)
{
    for (int i = 0; i <= n; i++)
    {

        cout << "The trip " << i + 1 << ":\n";
        a[i].print();
        cout << "\n";
    }
}

void inputTicket(ticket a[], int &n, trip lt[], lines ll[], airlines la[], int nla)
{
    string s;
    int t, t1, t2;
    // cout << "Welcome to air ticket agency\n";
    cout << "Input name: ";
    getline(cin, s);
    a[n].setNameOfClient(s);
    cout << "Input id: ";
    getline(cin, s);
    a[n].setIdOfClient(s);
    cout << "Input phone: ";
    getline(cin, s);
    a[n].setPhone(s);
    cout << "\nChoose airline: \n\n";
    for (int i = 0; i <= nla; i++)
    {
        cout << i + 1 << " ";
        la[i].printNameOfAirline();
        cout << "\n";
    }
    cin >> t;
    s = la[t - 1].getName();
    cout << "\nChoose line: \n\n";
    if (t - 1 == 0)
        t1 = 0;
    else
    {
        t1 = 0;
        for (int i = 0; i < t - 1; i++)
        {
            t2 = la[i].getTotalLine();
            t1 += t2;
        }
    }
    t2 = la[t - 1].getTotalLine() + t1;
    for (int i = t1; i < t2; i++)
    {
        cout << i + 1 << " ";
        ll[i].printOfLine();
        cout << "\n";
    }
    cin >> t;
    cout << "\nChoose Trip: \n\n";
    if (t - 1 == 0)
        t1 = 0;
    else
    {
        t1 = 0;
        for (int i = 0; i < t - 1; i++)
        {
            t2 = ll[i].getTotalTrip();
            t1 += t2;
        }
    }
    t2 = ll[t - 1].getTotalTrip() + t1;
    for (int i = t1; i < t2; i++)
    {
        cout << i + 1 - t1 << "\n";
        lt[i].printOfTrip();
        cout << "\n";
    }
    cin >> t;
    cin.ignore();
    cout << "\n";
    t = t - 1 + t1;
    a[n].setId(lt[t].getId());
    a[n].setName(lt[t].getName());
    a[n].setTotal(lt[t].getTotalLine());
    a[n].setIdLine(lt[t].getIdLine());
    a[n].setTotalTrip(lt[t].getTotalTrip());
    a[n].setFrom(lt[t].getFrom());
    a[n].setTo(lt[t].getTo());
    a[n].setIdTrip(lt[t].getIdTrip());
    a[n].setDate(lt[t].getDate());
    a[n].setDepartureTime(lt[t].getDepartureTime());
    a[n].setPrice(lt[t].getPrice());
    a[n].setSeat(lt[t].getSeat());
    cout << "The trip have 6 rows of seat (A,B,C,D,F,G), each row have " << lt[t].getSeatOfRow() << " seats.\n";
    cout << "Choose seat: ";
    getline(cin, s);
    a[n].setSeatOfClient(s);
    n++;
}

void writeTicket(ticket a[], int n)
{
    for (int i = 0; i < n; i++)
    {

        cout << "Client " << i + 1 << ":\n";
        a[i].print();
        cout << "\n\n";
    }
}

void readTicket(ticket a[], int &n, trip lt[], int nlt)
{
    int t;
    time t3;
    day t2;
    string s;
    char ch;
    ifstream f("TicketManagement.txt");
    while (!f.eof())
    {
        getline(f, s, ',');
        a[n].setName(s);
        getline(f, s, ',');
        a[n].setFrom(s);
        getline(f, s, ',');
        a[n].setTo(s);
        f >> t2.d;
        f.get(ch);
        f >> t2.m;
        f.get(ch);
        f >> t2.y;
        f.get(ch);
        a[n].setDate(t2);
        f >> t3.hour;
        f.get(ch);
        f >> t3.minute;
        f.get(ch);
        a[n].setDepartureTime(t3);
        getline(f, s, ',');
        a[n].setNameOfClient(s);
        getline(f, s, ',');
        a[n].setIdOfClient(s);
        getline(f, s, ',');
        a[n].setPhone(s);
        getline(f, s, '\n');
        a[n].setSeatOfClient(s);
        for (int i = 0; i <= nlt; i++)
            if (a[n].getName() == lt[i].getName())
                if (a[n].getFrom() == lt[i].getFrom() && a[n].getTo() == lt[i].getTo())
                {
                    a[n].setPrice(lt[i].getPrice());
                    a[n].setId(lt[i].getId());
                    break;
                }
        if (f.eof())
        {
            n++;
            break;
        }
        else
            n++;
    }
    f.close();
}

int main()
{
    // listAirline la;
    // createEmptyAirline(la);
    airlines la[10];
    lines ll[10];
    trip lt[10];
    ticket lc[10];
    int nla = 0, nll = 0, nlt = 0, nlc = 0;
    readAirline(la, nla);
    // writeAirline(la, nla);
    // cout << "=====---=====\n";
    readLine(ll, nll, la, nla);
    // writeLine(ll, nll);
    // cout << "=====---=====\n";
    readTrip(lt, nlt, ll, nll);
    writeTrip(lt, nlt);

    // readTicket(lc, nlc, lt, nlt);
    // inputTicket(lc, nlc, lt, ll, la, nla);
    // writeTicket(lc, nlc);
    return 0;
}