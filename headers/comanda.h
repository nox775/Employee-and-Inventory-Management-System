#pragma once;
#include <iostream>
#include <string>
#include "disc.h"
#include "disc_vint.h"
#include "vestimentatie.h"
#include <typeinfo>

using namespace std;

class Comanda
{
    string data_plasare = ""; // trebuie sa folosesti librarie speciala;
    int durata_solutionare = 0;
    int nr_produse = 0;
    Produs **p = NULL;

public:
    Comanda() = default;
    Comanda(string, int, int, Produs **);
    Comanda(const Comanda &);
    Comanda &operator=(const Comanda &);
    ~Comanda();
};
