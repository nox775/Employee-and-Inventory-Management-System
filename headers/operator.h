#include "angajat.h"
#include "comanda.h"
#include <queue>
#pragma once

class Operator : public Angajat
{
    // queue<Comanda> c;

    queue<int> id_comenzi;
    int comenzi_procesate = 0;
    float valoare_comenzi_procesate = 0;
    int comenzi_in_lucru = 0;

public:
    Operator() = default;
    Operator(queue<int>, string, int, time_t, string, string, string, int, float, int);

    void afisare() const;
    int getSalariu() const;

    void solutionareComanda();

    void adaugaComanda(const Comanda &);
    int getComenzi_in_lucru() const;

    float getVal_comz_procesate() const;
    int getComenzi_procesate() const;

    friend ostream &operator<<(ostream &, const Operator &);

    ~Operator();
};