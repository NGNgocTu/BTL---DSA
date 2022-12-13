#include "Lines.h"

lines::lines(int id, string name, int totalLine, int idLine, int totalTrip, string from, string to) : airlines(id, name, totalLine)
{
    this->from = from;
    this->to = to;
    this->idLine = idLine;
}

void lines::print()
{
    this->airlines::print();
    cout << "Id of line: " << this->idLine;
    cout << "\nLine from " << this->from << " to " << this->to << "\n";
    cout << "Total of trip: " << this->totalTrip << "\n";
}

void lines::printOfLine()
{
    cout << "Line from " << this->from << " to " << this->to << "\n";
}