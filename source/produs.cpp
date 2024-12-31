#include "../headers/produs.h"

int Produs::nr_produse_stoc = 0;

Produs::Produs(string nume_var, int cantitate_var, int cod_var, float pret_baza_var) : nume(nume_var), cantiate(cantitate_var), cod(cod_var), pret_baza(pret_baza_var) { nr_produse_stoc++; };

Produs::~Produs() {};

void Produs::afisareInfo()
{
    cout << "------------------------" << endl;
    cout << "Nume produs: " << nume << endl;
    cout << "Cantitate: " << cantiate << endl;
    cout << "Cod identificare: " << cod << endl;
    cout << "Pret de baza: " << pret_baza << endl;
}

void Produs::setCantitate(int cantitate_nou)
{
    try
    {
        if (cantitate_nou >= 0)
            cantiate = cantitate_nou;
        else
            throw std::invalid_argument("Cantiatea trebuie sa fie pozitiva");
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}

void Produs::PretFinal()
{
    cout << "Pret final (+livrare) " << pret_baza << endl;
}

float Produs::getPret_de_baza()
{
    return pret_baza;
}

int Produs::getCod() const
{
    return cod;
}

bool operator==(const Produs &p1, const Produs &p2)
{
    if (p1.cod == p2.cod)
        return true;
    else
        return false;
}

int Produs::getCantitate() const
{
    return cantiate;
}