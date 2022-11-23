#include "Trip.h"

class ticket : public trip
{
protected:
    day date;
    time boardingTime;
    int price;

public:
    ticket(int id, string name, int idLine, string from, string to, int idTrip, time departureTime, int seat, day date, time boardingTime, int price);
    void setDate(day date) { this->date = date; }
    void setBoardingTime(time boardingTime) { this->boardingTime = boardingTime; }
    void setPrice(int price) { this->price = price; }
    virtual void print();
};