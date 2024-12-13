#include "../headers/disc_vint.h"
#include <exception>
using namespace std;
Disc_Vint::Disc_Vint(string nume_var, int cantitate_var, string cod_var, float pret_baza_var,
                     string tip_var,
                     string casa_de_discuri_var,
                     string data_lansare_var,
                     string nume_trup_var,
                     string nume_album_var,
                     float raritate_var, bool mint_var) : Disc(nume_var, cantitate_var, cod_var, pret_baza_var,
                                                               tip_var,
                                                               casa_de_discuri_var,
                                                               data_lansare_var,
                                                               nume_trup_var,
                                                               nume_album_var),
                                                          mint(mint_var), raritate(raritate_var)
{
    if (raritate > 5 || raritate < 1)
        throw std::out_of_range("Raritatea trebuie sa fie cuprinsa intre 1 si 5");
}

Disc_Vint::~Disc_Vint() {};

float Disc_Vint::getPret()
{
    int pret = pret_baza + raritate * 15 + 5;
    return pret;
}