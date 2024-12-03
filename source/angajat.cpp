#include "../headers/angajat.h"

Angajat::Angajat(int ID_var, string nume_var, string prenume_var, char *CNP_var,
                 int *data_angajare_var)
{
    nume = nume_var;
    prenume = prenume_var;
    for (int i = 0; i < 3; i++)
        data_angajare[i] = data_angajare_var[i];
}

int Angajat::getVechime()
{
    int ziua_curenta, luna_curenta, anul_curent;
    cout << "Scrie data de astazi in format ZZ LL AAA" << endl;
    cin >> ziua_curenta >> luna_curenta >> anul_curent;
}

int Angajat::getSalariu()
{
    int salariu = 3500;
}