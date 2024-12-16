#include "../headers/disc.h"

Disc::Disc(string nume_var, int cantitate_var, string cod_var, float pret_baza_var,
           string tip_var,
           string casa_de_discuri_var,
           string data_lansare_var,
           string nume_trup_var,
           string nume_album_var) : Produs(nume_var, cantitate_var, cod_var, pret_baza_var),
                                    tip(tip_var), casa_de_discuri(casa_de_discuri_var),
                                    data_lansare(data_lansare_var), nume_trup(nume_trup_var),
                                    nume_album(nume_album_var)
{
}

Disc::~Disc() {};

float Disc::getPret()
{
    int pret = pret_baza;
    pret = pret + 5;
    return pret;
}

void Disc::afisareInfo() const
{
    Produs::afisareInfo();
    cout << "Tip Produs: Disc" << endl;
    cout << "Tip Disc: " << tip << endl;
    cout << "Nume trupa: " << nume_trup << endl;
    cout << "Nume album: " << nume_album << endl;
    cout << "Data de lansare: " << data_lansare << endl;
    cout << "Casa de discuri: " << casa_de_discuri << endl;
}
void Disc::PretFinal()
{
    cout << "Pret final (+livrare): " << (this)->getPret() << endl;
}