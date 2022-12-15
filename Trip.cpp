#include "Trip.h"

trip::trip(int id, string name, int totalLine, int idLine, int totalTrip, string from, string to, int idTrip, dayFly date, timeFly departureTimeFly, int price, int seatOfRow, int totalWeight, int pricePerKilo) : lines(id, name, totalLine, idLine, totalTrip, from, to)
{
    this->idTrip = idTrip;
    this->departureTimeFly = departureTimeFly;
    this->seatOfRow = seatOfRow;
    this->totalWeight = totalWeight;
    this->pricePerKilo = pricePerKilo;
}

void trip::print()
{
    this->lines::print();
    cout << "Id of trip: " << this->idTrip;
    cout << "\nDeparture date: ";
    this->date.d < 10 ? cout << "0" << this->date.d << "/" : cout << this->date.d << "/";
    this->date.m < 10 ? cout << "0" << this->date.m << "/" : cout << this->date.m << "/";
    cout << this->date.y;
    cout << "\nDeparture timeFly: ";
    this->departureTimeFly.hour < 10 ? cout << "0" << this->departureTimeFly.hour << ":" : cout << this->departureTimeFly.hour << ":";
    this->departureTimeFly.minute < 10 ? cout << "0" << this->departureTimeFly.minute : cout << this->departureTimeFly.minute;
    cout << "\nThe price is: " << this->price;
    cout << "\nTotal of seat: " << this->seat << "\n";
    cout << "The total weight (kg): " << this->totalWeight << "\n";
    cout << "The price per kilogram: " << this->pricePerKilo << "\n";
}

void trip::printOfTrip()
{
    cout << "Departure date: ";
    this->date.d < 10 ? cout << "0" << this->date.d << "/" : cout << this->date.d << "/";
    this->date.m < 10 ? cout << "0" << this->date.m << "/" : cout << this->date.m << "/";
    cout << this->date.y;
    cout << "\nDeparture time: ";
    this->departureTimeFly.hour < 10 ? cout << "0" << this->departureTimeFly.hour << ":" : cout << this->departureTimeFly.hour << ":";
    this->departureTimeFly.minute < 10 ? cout << "0" << this->departureTimeFly.minute : cout << this->departureTimeFly.minute;
    cout << "\nThe price is: " << this->price << "\n";
}