#include "Lines.h"

lines::lines(int id, string name, int idLine, string from, string to) : airlines(id, name)
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
}