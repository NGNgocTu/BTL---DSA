#pragma once
#include "Airlines.h"

class lines : public airlines
{
protected:
    int idLine, totalTrip;
    string from, to;

public:
    lines(int id = -1, string name = "", int totalLine = 0, int idLine = 0, int totalTrip = 0, string from = "", string to = "");
    void setIdLine(int idLine) { this->idLine = idLine; }
    void setFrom(string from) { this->from = from; }
    void setTo(string to) { this->to = to; }
    void setTotalTrip(int totalTrip) { this->totalTrip = totalTrip; }
    int getIdLine() const { return this->idLine; }
    int getTotalTrip() const { return this->totalTrip; }
    string getFrom() const { return this->from; }
    string getTo() const { return this->to; }
    virtual void print();
    void printOfLine();
};