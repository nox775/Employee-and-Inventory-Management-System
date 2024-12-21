#pragma once;
#include <iostream>
#include <string>
#include "disc.h"
#include "disc_vint.h"
#include "vestimentatie.h"
#include <typeinfo>
#include <ctime>
#include <vector>

using namespace std;

class Comanda
{
    time_t data_plasare = time(NULL); // trebuie sa folosesti librarie speciala;
    int durata_solutionare = 0;
    int nr_produse = 0;
    vector<Produs *> p;

public:
    Comanda() = default;
    Comanda(time_t, int, int, vector<Produs *>);
    Comanda(const Comanda &);
    Comanda &operator=(const Comanda &);
    ~Comanda();
};
