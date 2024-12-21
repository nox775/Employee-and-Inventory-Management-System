#include "../headers/angajat.h"

int Angajat::nr_angajati = 0;

Angajat::Angajat(string tip, int ID_var, time_t data_angajare_var, string nume_var, string prenume_var, string CNP_var) : Persoana(nume_var, prenume_var, CNP_var), ID(ID_var), tipAngajat(tip)
{
    try
    {
        if (this->getVarsta() < 18)
            throw std::invalid_argument("Persoana nu are 18 ani");
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Caught invalid_argument error: " << e.what() << std::endl;
    }

    data_angajare = data_angajare_var;
    nr_angajati++;
}

int Angajat::getVechime() const
{

    // Get the current time as a time_t
    std::time_t t = std::time(nullptr); // Get current time
    std::tm *now = std::localtime(&t);  // Convert time_t to std::tm (local time)

    int ziua_curenta = now->tm_mday;       // Current day
    int luna_curenta = now->tm_mon + 1;    // Current month (tm_mon is 0-based)
    int anul_curent = now->tm_year + 1900; // Current year (tm_year is years since 1900)

    // Convert data_angajare (time_t) to std::tm
    std::tm *hireDate = std::localtime(&data_angajare);

    // Extract hiring date components from hireDate (which is std::tm)
    int ziua_angajare = hireDate->tm_mday;
    int luna_angajare = hireDate->tm_mon + 1;     // Adjust 0-based month
    int anul_angajare = hireDate->tm_year + 1900; // Adjust year

    int vechime;

    // Calculate seniority
    if (anul_curent == anul_angajare)
    {
        return 0; // Same year as hiring, no seniority yet
    }
    else
    {
        if ((luna_curenta == luna_angajare && ziua_curenta < ziua_angajare) ||
            (luna_curenta < luna_angajare))
        {
            vechime = anul_curent - anul_angajare - 1;
        }
        else
        {
            vechime = anul_curent - anul_angajare;
        }
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

int Angajat::getID()
{
    return ID;
}