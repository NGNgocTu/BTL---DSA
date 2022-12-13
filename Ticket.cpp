#include "Ticket.h"

ticket::ticket(int id, string name, int totalLine, int idLine, int totalTrip, string from, string to, int idTrip, day date, time departureTime, int price, int seat, string nameOfClient, string idOfClient, string phone, string seatOfClient) : trip(id, name, totalLine, idLine, totalTrip, from, to, idTrip, date, departureTime, price, seat)
{
    this->nameOfClient = nameOfClient;
    this->seatOfClient = seatOfClient;
    this->idOfClient = idOfClient;
    this->phone = phone;
}

void ticket::print()
{
    // this->airlines::printNameOfAirline();
    // this->lines::printOfLine();
    // this->trip::printOfTrip();
    // cout << "Name of client: " << this->nameOfClient;
    // cout << "\nId of clinet: " << this->idOfClient;
    // cout << "\nPhone: " << this->phone;
    // cout << "\nSeat: " << this->seatOfClient;
    cout << "\t" << name << "\t\t" << from << "\t\t" << to << "\t\t";
    this->date.d < 10 ? cout << "0" << this->date.d << "/" : cout << this->date.d << "/";
    this->date.m < 10 ? cout << "0" << this->date.m << "/" : cout << this->date.m << "/";
    cout << this->date.y << "\t";
    this->departureTime.hour < 10 ? cout << "0" << this->departureTime.hour << ":" : cout << this->departureTime.hour << ":";
    this->departureTime.minute < 10 ? cout << "0" << this->departureTime.minute : cout << this->departureTime.minute;
    cout << "\t" << price << "\t" << nameOfClient << "\t" << idOfClient << "\t" << phone << "\t" << seatOfClient << "\n";
}