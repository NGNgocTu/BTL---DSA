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
    this->airlines::printNameOfAirline();
    this->lines::printOfLine();
    this->trip::printOfTrip();
    cout << "Name of client: " << this->nameOfClient;
    cout << "\nId of clinet: " << this->idOfClient;
    cout << "\nPhone: " << this->phone;
    cout << "\nSeat: " << this->seatOfClient;
}