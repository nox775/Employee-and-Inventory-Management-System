#include "produs.h"

class Vestimentatie : public Produs
{
    string culoare = "";
    string marca = "";

public:
    Vestimentatie() = default;
    Vestimentatie(string, int, string, float, string, string);
    ~Vestimentatie();

    float getPret();
};