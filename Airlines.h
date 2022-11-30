#pragma once

#include <iostream>
#include <string>

using namespace std;

struct time
{
    int hour, minute;
};

struct day
{
    int d, m, y;
};

class airlines
{
protected:
    int id, TotalLine;
    string name;

public:
    airlines(int id = -1, string name = "", int TotalLine = 0);
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setTotal(int TotalLine) { this->TotalLine = TotalLine; }
    int getId() const { return this->id; }
    string getName() const { return this->name; }
    int getTotalLine() const { return this->TotalLine; }
    virtual void print();
    void printNameOfAirline();
};