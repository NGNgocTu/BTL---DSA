#pragma once
#include "Lines.h"
#include <iomanip>

dayFly date1;
timeFly time1;

class trip : public lines
{
protected:
    int idTrip, seat, price, seatOfRow, totalWeight, pricePerKilo;
    timeFly departureTimeFly;
    dayFly date;

public:
    trip(int id = -1, string name = "", int totalLine = 0, int idLine = 0, int totalTrip = 0, string from = "", string to = "", int idTrip = 0, dayFly date = date1, timeFly departureTimeFly = time1, int price = 0, int seatOfRow = 0, int totalWeight = 0, int pricePerKilo = 0);
    void setIdTrip(int idTrip) { this->idTrip = idTrip; }
    void setSeat(int seat) { this->seat = seat; }
    void setDepartureTimeFly(timeFly departuretimeFly) { this->departureTimeFly = departuretimeFly; }
    void setDate(dayFly date) { this->date = date; }
    void setPrice(int price) { this->price = price; }
    void setSeatOfRow(int seatOfRow) { this->seatOfRow = seatOfRow; }
    void setTotalWeight(int totalWeight) { this->totalWeight = totalWeight; }
    void setPricePerKilo(int pricePerKilo) { this->pricePerKilo = pricePerKilo; }
    int getTotalWeight() const { return this->totalWeight; }
    int getPricePerKilo() const { return this->pricePerKilo; }
    int getIdTrip() const { return this->idTrip; }
    int getSeat() const { return this->seat; }
    int getPrice() const { return this->price; }
    int getSeatOfRow() const { return this->seatOfRow; }
    timeFly getDepartureTimeFly() const { return this->departureTimeFly; }
    dayFly getDate() const { return this->date; }
    int getDayFly() const { return this->date.d; }
    int getMonth() const { return this->date.m; }
    int getYear() const { return this->date.y; }
    int getHour() const { return this->departureTimeFly.hour; }
    int getMinute() const { return this->departureTimeFly.minute; }
    virtual void print();
    void printOfTrip();
    void printOfShip();
};