#include "angajat.h"
#include "comanda.h"
#include <queue>
#pragma once

class Operator : public Angajat
{
    queue<Comanda> c;

    int comenzi_procesate = 0;
    float valoare_comenzi_procesate = 0;
    int comenzi_in_lucru = 0;

public:
    Operator() = default;
    Operator(string, int, time_t, string, string, string, queue<Comanda>, int, float, int);

    void afisare() const;
    int getSalariu() const;

    void solutionareComanda();

    void adaugaComanda(const Comanda &);
    bool isLiber() const;
    int getComenzi_in_lucru() const;

    ~Operator();
};