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
    int id;
    string name;

public:
    airlines(int id, string name);
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    virtual void print();
};