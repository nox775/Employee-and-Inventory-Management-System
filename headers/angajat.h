
#include <iostream>
#include <string>
#include <cstring>
#include <exception>
#include "persoana.h"
#include <ctime>
#pragma once

using namespace std;

class Angajat : public Persoana
{
    string tipAngajat = "";
    int ID = 0;                        // trebuie sa fie unic
    time_t data_angajare = time(NULL); // ZZ_LL_AAAA
public:
    static int nr_angajati;

    Angajat() = default;
    Angajat(string, int, time_t, string, string, string);

    void afisare() const;

    int getID();

    void Demisie();
    int getSalariu() const; // returneaza salariul unui angajat
    int getVechime() const; // vechimea unui angajat in firma
    ~Angajat();
};