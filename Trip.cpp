#include "Trip.h"

trip::trip(int id, string name, int totalLine, int idLine, int totalTrip, string from, string to, int idTrip, day date, time departureTime, int price, int seatOfRow) : lines(id, name, totalLine, idLine, totalTrip, from, to)
{
    this->idTrip = idTrip;
    this->departureTime = departureTime;
    this->seatOfRow = seatOfRow;
}

void trip::print()
{
    this->lines::print();
    cout << "Id of trip: " << this->idTrip;
    cout << "\nDeparture date: ";
    this->date.d < 10 ? cout << "0" << this->date.d << "/" : cout << this->date.d << "/";
    this->date.m < 10 ? cout << "0" << this->date.m << "/" : cout << this->date.m << "/";
    cout << this->date.y;
    cout << "\nDeparture time: ";
    this->departureTime.hour < 10 ? cout << "0" << this->departureTime.hour << ":" : cout << this->departureTime.hour << ":";
    this->departureTime.minute < 10 ? cout << "0" << this->departureTime.minute : cout << this->departureTime.minute;
    cout << "\nThe price is: " << this->price;
    cout << "\nTotal of seat: " << this->seat << "\n";
}

void trip::printOfTrip()
{
    cout << "Departure date: ";
    this->date.d < 10 ? cout << "0" << this->date.d << "/" : cout << this->date.d << "/";
    this->date.m < 10 ? cout << "0" << this->date.m << "/" : cout << this->date.m << "/";
    cout << this->date.y;
    cout << "\nDeparture time: ";
    this->departureTime.hour < 10 ? cout << "0" << this->departureTime.hour << ":" : cout << this->departureTime.hour << ":";
    this->departureTime.minute < 10 ? cout << "0" << this->departureTime.minute : cout << this->departureTime.minute;
    cout << "\nThe price is: " << this->price << "\n";
}