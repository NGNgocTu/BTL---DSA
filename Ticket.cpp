#include "Ticket.h"

ticket::ticket(int id, string name, int totalLine, int idLine, int totalTrip, string from, string to, int idTrip, dayFly date, timeFly departureTimeFly, int price, int seatOfRow, int totalWeight, int pricePerKilo, string nameOfClient, string idOfClient, string phone, string seatOfClient, double weight, int priceOfPackage) : trip(id, name, totalLine, idLine, totalTrip, from, to, idTrip, date, departureTimeFly, price, seatOfRow, totalWeight, pricePerKilo)
{
    this->nameOfClient = nameOfClient;
    this->seatOfClient = seatOfClient;
    this->idOfClient = idOfClient;
    this->phone = phone;
    this->priceOfPackage = priceOfPackage;
    this->weight = weight;
}

void ticket::print()
{
    cout << setw(5) << left << "|" << setw(25) << name << "|  " << setw(20) << from << "|  " << setw(15) << to << "|  ";
    this->date.d < 10 ? cout << "0" << this->date.d << "/" : cout << this->date.d << "/";
    this->date.m < 10 ? cout << "0" << this->date.m << "/" : cout << this->date.m << "/";
    cout << setw(6) << this->date.y << "|  ";
    this->departureTimeFly.hour < 10 ? cout << "0" << this->departureTimeFly.hour << ":" : cout << this->departureTimeFly.hour << ":";
    this->departureTimeFly.minute < 10 ? cout << "0" << setw(3) << this->departureTimeFly.minute : cout << setw(4) << this->departureTimeFly.minute;
    cout << "|  " << setw(8) << price << "|  " << setw(28) << nameOfClient << "|  " << setw(11) << idOfClient << "|  " << setw(12) << phone << "|  " << setw(5) << seatOfClient << "|\n";
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
}

void ticket::printTicketOfShip()
{
    cout << setw(5) << left << "|" << setw(25) << name << "|  " << setw(20) << from << "|  " << setw(15) << to << "|  ";
    this->date.d < 10 ? cout << "0" << this->date.d << "/" : cout << this->date.d << "/";
    this->date.m < 10 ? cout << "0" << this->date.m << "/" : cout << this->date.m << "/";
    cout << setw(6) << this->date.y << "|  ";
    this->departureTimeFly.hour < 10 ? cout << "0" << this->departureTimeFly.hour << ":" : cout << this->departureTimeFly.hour << ":";
    this->departureTimeFly.minute < 10 ? cout << "0" << setw(3) << this->departureTimeFly.minute : cout << setw(4) << this->departureTimeFly.minute;
    cout << "|  " << setw(8) << price << "|  " << setw(28) << nameOfClient << "|  " << setw(11) << idOfClient << "|  " << setw(12) << phone << "|  " << setw(12) << weight << "|  " << setw(15) << priceOfPackage << "|\n";
    cout << "|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
}