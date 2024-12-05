#include "produs.h"
#pragma once

class Disc : public Produs
{
protected:
    string tip = "";
    string casa_de_discuri = "";
    time_t data_lansare;
    string nume_trupa;
    string nume_album;
};
