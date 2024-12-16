#include "produs.h"
#pragma once

class Disc : public Produs
{
protected:
    string tip = "";
    string casa_de_discuri = "";
    string data_lansare = ""; //->>lucreaza la asta
    string nume_trup = "";
    string nume_album = "";

public:
    Disc() = default;
    Disc(string, int, string, float, string, string, string, string, string);

    float getPret();

    void afisareInfo() const;
    void PretFinal();

    ~Disc();
};
