#include "../headers/angajat.h"

int Angajat::nr_angajati = 0;

Angajat::Angajat(string tip, int ID_var, int *data_angajare_var, string nume_var, string prenume_var, string CNP_var) : Persoana(nume_var, prenume_var, CNP_var), ID(ID_var), tipAngajat(tip)
{
    if (this->getVarsta() < 18)
        throw std::invalid_argument("Persoana nu are 18 ani");

    for (int i = 0; i < 3; i++)
        data_angajare[i] = data_angajare_var[i];
    nr_angajati++;
}

int Angajat::getVechime() const
{
    // poate fi templete

    int ziua_curenta = 5, luna_curenta = 12, anul_curent = 2024;
    int vechime;

    if (anul_curent == data_angajare[2])
        return 0;
    else
    {
        if ((luna_curenta == data_angajare[1] && ziua_curenta < data_angajare[0]) ||
            (luna_curenta < data_angajare[1]))
            vechime = anul_curent - data_angajare[2] - 1;
        else
            vechime = anul_curent - data_angajare[2];
    }

    return vechime;
}

int Angajat::getSalariu() const
{
    int salariu = 3500;
    salariu = salariu + 100 * (this)->getVechime();

    if (tipAngajat == "Manager")
    {
        salariu = salariu * 1.25;
    }
    if (tipAngajat == "Asistent")
    {
        salariu = salariu * 0.75;
        //  if()
    }
    if (tipAngajat == "Operator")
    {
        salariu = salariu * 0.75;
    }
    // mai este de lucrat aici

    return salariu;
}

void Angajat::afisare() const
{
    cout << "--------------" << endl;
    Persoana::afisare();
    cout << "Functie: " << tipAngajat << endl;
    cout << "ID angajat: " << ID << endl;

    cout << "Salariu: " << (this)->getSalariu() << endl;
    cout << "--------------" << endl;
}

void Angajat::Demisie()
{
    cout << "Angajatul cu ID " << ID << " a demisionat." << endl;
    nr_angajati--;
}

Angajat::~Angajat() {};