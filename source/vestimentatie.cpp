#include "../headers/vestimentatie.h"

Vestimentatie::Vestimentatie(string nume_var, int cantitate_var, string cod_var, float pret_baza_var,
                             string culoare_var, string marca_var) : Produs(nume_var, cantitate_var, cod_var, pret_baza_var),
                                                                     culoare(culoare_var), marca(marca_var) {}

Vestimentatie::~Vestimentatie() {};

float Vestimentatie::getPret()
{
    return pret_baza + 20;
}

void Vestimentatie::afisareInfo() const
{
    Produs::afisareInfo();
    cout << "Tip: Vestimentatie" << endl;
    cout << "Culoare: " << culoare << endl;
    cout << "Marca: " << marca << endl;
}
void Vestimentatie::PretFinal()
{
    cout << "Pret final (+livrare): " << (this)->getPret() << endl;
}