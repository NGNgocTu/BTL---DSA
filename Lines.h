#include "Airlines.h"

class lines : public airlines
{
protected:
    int idLine;
    string from, to;

public:
    lines(int id, string name, int idLine, string from, string to);
    void setIdLine(int idLine) { this->idLine = idLine; }
    void setFrom(string from) { this->from = from; }
    void setTo(string to) { this->to = to; }
    virtual void print();
};