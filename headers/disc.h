#include "produs.h"
#pragma once

class Disc : public Produs
{
protected:
    string tip = "";
    string casa_de_discuri = "";
    time_t data_lansare = time(NULL); //->>lucreaza la asta
    string nume_trup = "";
    string nume_album = "";

public:
    Disc() = default;
    Disc(string, int, int, float, string, string, time_t, string, string);

    float getPret();

    void afisareInfo() const;
    void PretFinal();

    ~Disc();
};
