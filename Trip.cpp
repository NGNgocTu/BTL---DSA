#include "Trip.h"

trip::trip(int id, string name, int idLine, string from, string to, int idTrip, time departureTime, int seat) : lines(id, name, idLine, from, to)
{
    this->idTrip = idTrip;
    this->departureTime = departureTime;
    this->seat = seat;
}

void trip::print()
{
    this->lines::print();
    cout << "Id of trip: " << this->idTrip;
    cout << "\nDeparture time: " << this->departureTime.hour << ":" << this->departureTime.minute;
    cout << "\nTotal of seat: " << this->seat << "\n";
}