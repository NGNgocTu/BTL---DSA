#include "Airlines.h"

airlines::airlines(int id, string name)
{
    this->id = id;
    this->name = name;
}

void airlines::print()
{
    cout << "Name of airline: " << this->name << "\n";
}