#include "Airlines.h"

airlines::airlines(int id, string name, int TotalLine)
{
    this->id = id;
    this->name = name;
    this->TotalLine = TotalLine;
}

void airlines::print()
{
    cout << "Name of airline: " << this->name << "\n";
    cout << "Total of line: " << this->TotalLine << "\n";
}

void airlines::printNameOfAirline()
{
    cout << this->name;
    if (this->id == 2)
        cout << " (international & domestic)\n";
    else if (this->id == 1)
        cout << " (international)\n";
    else if (this->id == 0)
        cout << " (domestic)\n";
}