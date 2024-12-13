#include <string>
#include <ctime>
#include <exception>
#include <iostream>
using namespace std;

class Produs
{
protected:
    string nume = "";
    int cantiate = 0;
    string cod = ""; // unic - inca nu este unic!!
    float pret_baza = 0.0;

public:
    Produs() = default;
    Produs(string, int, string, float);

    virtual float getPret() = 0;

    virtual ~Produs();
};