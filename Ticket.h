#pragma once
#include "Trip.h"

class ticket : public trip
{
protected:
    string nameOfClient, idOfClient, phone, seatOfClient;

public:
    ticket(int id = -1, string name = "", int totalLine = 0, int idLine = 0, int totalTrip = 0, string from = "", string to = "", int idTrip = 0, day date = date1, time departureTime = time1, int price = 0, int seat = 0, string nameOfClient = "", string idOfClient = "", string phone = "", string seatOfClient = "");
    void setNameOfClient(string nameOfClient) { this->nameOfClient = nameOfClient; }
    void setIdOfClient(string idOfClient) { this->idOfClient = idOfClient; }
    void setPhone(string phone) { this->phone = phone; }
    void setSeatOfClient(string seatOfClient) { this->seatOfClient = seatOfClient; }
    string getIdOfClient() const {return this->idOfClient;}
    virtual void print();
};