#include "../headers/persoana.h"

Persoana::Persoana(string nume_var, string prenume_var, string CNP_var)
{
    if (nume_var.length() <= 3 || nume_var.length() >= 30)
        throw std::out_of_range("Nume are trebuie sa aibaa intre 3 si 30 de caractere");
    if (prenume_var.length() <= 3 || prenume_var.length() >= 30)
        throw std::out_of_range("Prenume are trebuie sa aibaa intre 3 si 30 de caractere");

    nume = nume_var;
    prenume = prenume_var;

    if (CNP_var.length() != 13)
        throw std::invalid_argument("CNP trebuie sa aiba 13 caracter si sa fie de forma S AA LL	ZZ JJ NNN C");

    CNP = CNP_var;
}

int *Persoana::getDataNasterii() const
{

    int an, luna, zi;
    if (stoi(CNP.substr(0, 1)) == 1 || stoi(CNP.substr(0, 1)) == 2)
        an = 1900;
    else
        an = 2000;
    an = an + stoi(CNP.substr(1, 2));
    luna = stoi(CNP.substr(3, 2));
    zi = stoi(CNP.substr(5, 2));

    int *data_nasterii = new int[3];
    data_nasterii[0] = zi;
    data_nasterii[1] = luna;
    data_nasterii[2] = an;
    return data_nasterii;
}

void Persoana::setNume(string nume_nou)
{
    nume = nume_nou;
}

int Persoana::getVarsta() const
{
    // poate fi templete
    int *data_nasterii = (this)->getDataNasterii();
    int ziua_curenta = 5, luna_curenta = 12, anul_curent = 2024;
    int varsta;

    if (anul_curent == data_nasterii[2])
        return 0;
    else
    {
        if ((luna_curenta == data_nasterii[1] && ziua_curenta < data_nasterii[0]) ||
            (luna_curenta < data_nasterii[1]))
            varsta = anul_curent - data_nasterii[2] - 1;
        else
            varsta = anul_curent - data_nasterii[2];
    }

    return varsta;
}

Persoana::~Persoana() {};

void Persoana::afisare() const
{
    cout << "Nume: " << nume << endl;
    cout << "Prenume: " << prenume << endl;
    cout << "CNP: " << CNP << endl;
}