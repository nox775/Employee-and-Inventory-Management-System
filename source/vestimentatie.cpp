#include "../headers/vestimentatie.h"

Vestimentatie::Vestimentatie(string nume_var, int cantitate_var, int cod_var, float pret_baza_var,
                             string culoare_var, string marca_var, string tip_v) : Produs(nume_var, cantitate_var, cod_var, pret_baza_var),
                                                                                   culoare(culoare_var), marca(marca_var), tip(tip_v) {}

Vestimentatie::~Vestimentatie() {};

float Vestimentatie::getPret()
{
    return pret_baza + 20;
}

void Vestimentatie::PretFinal()
{
    cout << "Pret final (+livrare): " << (this)->getPret() << endl;
}

void Vestimentatie::afisareInfo()
{
    Produs::afisareInfo();
    cout << "Tip: Vestimentatie" << endl;
    cout << "Tip Articol: " << tip << endl;
    cout << "Culoare: " << culoare << endl;
    cout << "Marca: " << marca << endl;
    PretFinal();
}
