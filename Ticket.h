#pragma once
#include "Trip.h"
#include <iomanip>

class ticket : public trip
{
protected:
    string nameOfClient, idOfClient, phone, seatOfClient;
    int priceOfPackage;
    double weight;

public:
    ticket(int id = -1, string name = "", int totalLine = 0, int idLine = 0, int totalTrip = 0, string from = "", string to = "", int idTrip = 0, dayFly date = date1, timeFly departureTime = time1, int price = 0, int seatOfRow = 0, int totalWeight = 0, int pricePerKilo = 0, string nameOfClient = "", string idOfClient = "", string phone = "", string seatOfClient = "", double weight = 0, int priceOfPackage = 0);
    void setNameOfClient(string nameOfClient) { this->nameOfClient = nameOfClient; }
    void setIdOfClient(string idOfClient) { this->idOfClient = idOfClient; }
    void setPhone(string phone) { this->phone = phone; }
    void setSeatOfClient(string seatOfClient) { this->seatOfClient = seatOfClient; }
    void setWeight(double weight) { this->weight = weight; }
    void setPriceOfPackage(int priceOfPackage) { this->priceOfPackage = priceOfPackage; }
    double getWeight() const { return this->weight; }
    int getPriceOfPackage() const { return this->priceOfPackage; }
    string getIdOfClient() const { return this->idOfClient; }
    string getNameOfClient() const { return this->nameOfClient; }
    string getPhone() const { return this->phone; }
    string getSeatOfClient() const { return this->seatOfClient; }
    virtual void print();
    void printTicketOfShip();
};