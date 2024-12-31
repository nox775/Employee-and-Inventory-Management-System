#include <string>
#include <ctime>
#include <exception>
#include <iostream>
#pragma once
using namespace std;

class Produs
{
protected:
    string nume = "";
    int cantiate = 0;
    int cod = 0;
    float pret_baza = 0.0;

public:
    static int nr_produse_stoc;
    Produs() = default;
    Produs(string, int, int, float);

    virtual void afisareInfo();
    void setCantitate(int);
    // stergere ? - mai vedem

    virtual float getPret() = 0;
    float getPret_de_baza();

    virtual void PretFinal();
    int getCod() const;

    friend bool operator==(const Produs &, const Produs &);
    int getCantitate() const;

    virtual ~Produs();
};