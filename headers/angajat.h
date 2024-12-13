
#include <iostream>
#include <string>
#include <cstring>
#include <exception>
#include "persoana.h"
#pragma once

using namespace std;

class Angajat : public Persoana
{
    string tipAngajat = "";
    int ID = 0;                       // trebuie sa fie unic
    int data_angajare[3] = {0, 0, 0}; // ZZ_LL_AAAA
public:
    static int nr_angajati;

    Angajat() = default;
    Angajat(string, int, int *, string, string, string);

    void afisare() const;

    void Demisie();
    int getSalariu() const; // returneaza salariul unui angajat
    int getVechime() const; // vechimea unui angajat in firma
    ~Angajat();
};