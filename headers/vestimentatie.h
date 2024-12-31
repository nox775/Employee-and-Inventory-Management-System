#include "produs.h"
#pragma once

class Vestimentatie : public Produs
{
    string culoare = "";
    string marca = "";
    string tip = "";

public:
    Vestimentatie() = default;
    Vestimentatie(string, int, int, float, string, string, string);
    ~Vestimentatie();

    void afisareInfo();
    void PretFinal();

    float getPret();
};