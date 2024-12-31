#include "../headers/angajat.h"

int Angajat::nr_angajati = 0;
int Angajat::nr_opeatori = 0;

Angajat::Angajat(string tip, int ID_var, time_t data_angajare_var, string nume_var, string prenume_var, string CNP_var) : Persoana(nume_var, prenume_var, CNP_var), ID(ID_var), tipAngajat(tip)
{
    try
    {
        if (this->getVarsta() < 18)
            throw std::invalid_argument("Persoana nu are 18 ani");
        data_angajare = data_angajare_var;
        if (tip == "Operator")
            nr_opeatori++;
        nr_angajati++;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Caught invalid_argument error: " << e.what() << std::endl;
    }
}

int Angajat::getVechime() const
{

    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    int ziua_curenta = now->tm_mday;
    int luna_curenta = now->tm_mon + 1;
    int anul_curent = now->tm_year + 1900;

    std::tm *hireDate = std::localtime(&data_angajare);

    int ziua_angajare = hireDate->tm_mday;
    int luna_angajare = hireDate->tm_mon + 1;
    int anul_angajare = hireDate->tm_year + 1900;

    int vechime;

    if (anul_curent == anul_angajare)
    {
        return 0; //
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
    cout << "Angajatul cu ID " << ID << " a parasit compania." << endl;
    nr_angajati--;
    if (tipAngajat == "Operator")
    {
        nr_opeatori--;
    }
}

Angajat::~Angajat() {};

int Angajat::getID()
{
    return ID;
}

string Angajat::getTip() const
{
    return tipAngajat;
}

ostream &operator<<(ostream &out, const Angajat &other)
{
    out << "--------------" << endl;
    out << (Persoana)other;
    out << "Functie: " << other.tipAngajat << endl;
    out << "ID angajat: " << other.ID << endl;

    out << "Salariu: " << other.getSalariu() << endl;
    out << "--------------" << endl;

    return out;
}
