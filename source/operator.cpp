#include "../headers/operator.h"

Operator::Operator(string tip, int ID_var, time_t data_angajare_var, string nume_var, string prenume_var, string CNP_var,
                   queue<Comanda> c_v,
                   int c_procesate, float val_com, int nr_in_lucru)
    : Angajat(tip, ID_var, data_angajare_var, nume_var, prenume_var, CNP_var),
      c(c_v), comenzi_in_lucru(nr_in_lucru),
      valoare_comenzi_procesate(val_com), comenzi_procesate(c_procesate)
{
    try
    {
        if (c_v.size() > 3)
            throw out_of_range("Operatorul a depasit numarul maxim de comenzi pe care poate sa le execute");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Operator::afisare() const
{
    cout << "Operatorul: " << ID << endl;
    cout << "Nume: " << nume << endl;
    cout << "Prenume: " << prenume << endl;
    cout << "Are de execuat " << comenzi_in_lucru << " comenzi." << endl;

    cout << "----------------" << endl;
    cout << "Continut comenzi: " << endl;
    cout << "----------------" << endl;

    queue<Comanda> temp = c;
    while (!temp.empty())
    {
        cout << "******************" << endl;
        temp.front().afisare();
        temp.pop();
        cout << "******************" << endl;
    }

    cout << "----------------" << endl;
}
int Operator::getSalariu() const
{
    return Angajat::getSalariu() + 0.05 * valoare_comenzi_procesate;
}

Operator::~Operator() {};

void Operator::solutionareComanda()
{
    c.pop();
    comenzi_in_lucru--;
}

void Operator::adaugaComanda(const Comanda &temp)
{
    try
    {
        if (comenzi_in_lucru >= 3)
            throw out_of_range("Operatorul a depasit numarul maxim de comenzi pe care poate sa le execute");

        valoare_comenzi_procesate = valoare_comenzi_procesate + temp.valoareComanda();
        comenzi_procesate++;
        comenzi_in_lucru++;

        c.push(temp);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool Operator::isLiber() const
{
    if (c.empty())
        return true;
    else
        return false;
}

int Operator::getComenzi_in_lucru() const
{
    return comenzi_in_lucru;
}
