#include "../headers/produs.h"

Produs::Produs(string nume_var, int cantitate_var, string cod_var, float pret_baza_var) : nume(nume_var), cantiate(cantitate_var), cod(cod_var), pret_baza(pret_baza_var) {};

Produs::~Produs() {};

void Produs::afisareInfo() const
{
    cout << "------------------------" << endl;
    cout << "Nume produs: " << nume << endl;
    cout << "Cantitate: " << cantiate << endl;
    cout << "Cod identificare: " << cod << endl;
    cout << "Pret de baza: " << pret_baza << endl;
}

void Produs::setCantitate(string cod_identificare, int cantitate_nou)
{
    if (cod == cod_identificare)
    {
        cantiate = cantitate_nou;
    }
    // mai avem de lucru - posibil nu am inteles cum trebuie;
}

void Produs::PretFinal()
{
    cout << "Pret final (+livrare) " << pret_baza << endl;
}

float Produs::getPret_de_baza()
{
    return pret_baza;
}