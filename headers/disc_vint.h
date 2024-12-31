#include "disc.h"
#pragma once

class Disc_Vint : public Disc
{
    float raritate = 0.0;
    bool mint = false;

public:
    Disc_Vint() = default;
    Disc_Vint(string, int, int, float, string, string, time_t, string, string, float, bool);

    void afisareInfo();
    void PretFinal();
    ~Disc_Vint();

    float getPret();
};