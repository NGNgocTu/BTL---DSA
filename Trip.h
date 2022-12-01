#pragma once
#include "Lines.h"

day date1;
time time1;

class trip : public lines
{
protected:
    int idTrip, seat, price, seatOfRow;
    time departureTime;
    day date;

public:
    trip(int id = -1, string name = "", int totalLine = 0, int idLine = 0, int totalTrip = 0, string from = "", string to = "", int idTrip = 0, day date = date1, time departureTime = time1, int price = 0, int seat = 0);
    void setIdTrip(int idTrip) { this->idTrip = idTrip; }
    void setSeat(int seat) { this->seat = seat; }
    void setDepartureTime(time departureTime) { this->departureTime = departureTime; }
    void setDate(day date) { this->date = date; }
    void setPrice(int price) { this->price = price; }
    void setSeatOfRow(int seatOfRow) { this->seatOfRow = seatOfRow; }
    int getIdTrip() const { return this->idTrip; }
    int getSeat() const { return this->seat; }
    int getPrice() const { return this->price; }
    int getSeatOfRow() const { return this->seatOfRow; }
    time getDepartureTime() const { return this->departureTime; }
    day getDate() const { return this->date; }
    virtual void print();
    void printOfTrip();
};