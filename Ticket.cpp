#include "Ticket.h"

ticket::ticket(int id, string name, int idLine, string from, string to, int idTrip, time departureTime, int seat, day date, time boardingTime, int price) : trip(id, name, idLine, from, to, idTrip, departureTime, seat)
{
    this->date = date;
    this->boardingTime = boardingTime;
    this->price = price;
}

void ticket::print()
{
    this->trip::print();
    cout << "Date: " << this->date.d << "/" << this->date.m << "/" << this->date.y << "\n";
    cout << "Boarding time: " << this->boardingTime.hour << ":" << this->boardingTime.minute << "\n";
    cout << "Price is: " << this->price << "\n";
}