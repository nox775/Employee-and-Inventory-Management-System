#pragma once
#include <iostream>
#include <string>
#include "disc.h"
#include "disc_vint.h"
#include "vestimentatie.h"
#include <typeinfo>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class Comanda
{
    int id_comanda = 0;
    time_t data_plasare = time(NULL);
    time_t durata_solutionare = 0;
    int nr_produse = 0;
    vector<Produs *> p;

public:
    static int nr_comenzi;
    Comanda() = default;
    Comanda(int, time_t, time_t, int, vector<Produs *>);
    Comanda(const Comanda &);
    Comanda &operator=(const Comanda &);
    ~Comanda();
    Comanda(Comanda &&) noexcept;
    Comanda &operator=(Comanda &&) noexcept;

    int valoareComanda() const;
    int getNrProduse() const;

    void printData_plasare() const;
    void printData_solutionare() const;

    void afisare() const;

    bool verificareStoc(vector<Produs *> &);
    int getID_comanda() const;
};
