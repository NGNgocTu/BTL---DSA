#include "Lines.h"

class trip : public lines
{
protected:
    int idTrip, seat;
    time departureTime;

public:
    trip(int id, string name, int idLine, string from, string to, int idTrip, time departureTime, int seat);
    void setIdTrip(int idTrip) { this->idTrip = idTrip; }
    void setSeat(int seat) { this->seat = seat; }
    void setDepartureTime(time departureTime) { this->departureTime = departureTime; }
    virtual void print();
};