#pragma once
#include <string>

using namespace std;

class security
{
private:
    string name, id, pass;

public:
    security(string name = "", string id = "", string pass = "");
    ~security();
};