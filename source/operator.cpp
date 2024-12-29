#include "../headers/operator.h"
#include <iostream>
#include <stdexcept>

using namespace std; // To avoid using std:: for every standard component

Operator::Operator(queue<int> id_comenzi_v, string tip, int ID_var, time_t data_angajare_var, string nume_var, string prenume_var, string CNP_var,

                   int c_procesate, float val_com, int nr_in_lucru)
    : Angajat(tip, ID_var, data_angajare_var, nume_var, prenume_var, CNP_var),
      comenzi_in_lucru(nr_in_lucru),
      valoare_comenzi_procesate(val_com), comenzi_procesate(c_procesate), id_comenzi(id_comenzi_v)
{
    if (comenzi_in_lucru >= 4)
    {
        cerr << "Operatorul a depasit numarul maxim de comenzi pe care poate sa le execute" << endl;
    }
    Angajat::nr_angajati--;
}

void Operator::afisare() const
{
    cout << "Operatorul ID: " << ID << endl
         << "Nume: " << nume << endl
         << "Prenume: " << prenume << endl
         << "Comenzi in lucru: " << comenzi_in_lucru << endl
         << endl;

    cout << "ID-ul comenzilor pe care operatorul le proceseaza: ";

    if (comenzi_in_lucru == 0)
    {
        cout << "Operatorul nu are comenzi in lucru." << endl;
        return;
    }

    queue<int> temp = id_comenzi;
    cout << "----------------" << endl;

    while (!temp.empty())
    {
        cout << temp.front();
        temp.pop();
        cout << "******************" << endl;
    }
    cout << "----------------" << endl;
}

int Operator::getSalariu() const
{
    return Angajat::getSalariu() + (0.05 * valoare_comenzi_procesate);
}

Operator::~Operator() {}

void Operator::solutionareComanda()
{
    if (comenzi_in_lucru > 0)
    {
        int id = id_comenzi.front();
        cout << "COMANDA CU ID-ul: " << id << " A FOST SOLUTIONATA";
        cout << "---- de catre operatorul : " << ID << endl;
        time_t now = time(NULL);
        cout << "Momentul solutionarii: " << ctime(&now);

        id_comenzi.pop();
        comenzi_in_lucru--;
    }
    else
    {
        cerr << "Nu exista comenzi pentru solutionare!" << endl;
    }
}

void Operator::adaugaComanda(const Comanda &temp)
{

    if (comenzi_in_lucru < 3)
    {
        //  c.push(temp);
        id_comenzi.push(temp.getID_comanda());
        valoare_comenzi_procesate += temp.valoareComanda();
        comenzi_procesate++;
        comenzi_in_lucru++;
    }
    else
    {
        cerr << "Operatorul a atins numarul maxim de comenzi (3). Nu poate accepta comenzi noi." << endl;
    }
}

int Operator::getComenzi_in_lucru() const
{
    return comenzi_in_lucru;
}

float Operator::getVal_comz_procesate() const
{
    return valoare_comenzi_procesate;
}
int Operator::getComenzi_procesate() const
{
    return comenzi_procesate;
}
ostream &operator<<(ostream &out, const Operator &other)
{
    out << other.ID << ",";
    out << other.nume << ",";
    out << other.prenume << ",";
    out << ctime(&other.data_angajare) << ",";
    out << other.getSalariu() << ",";
    out << other.comenzi_procesate << ",";
    out << other.valoare_comenzi_procesate << endl;
    return out;
}