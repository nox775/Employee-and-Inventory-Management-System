#include "../headers/disc_vint.h"
#include <exception>
using namespace std;

Disc_Vint::Disc_Vint(string nume_var, int cantitate_var, int cod_var, float pret_baza_var,
                     string tip_var, string casa_de_discuri_var, time_t data_lansare_var,
                     string nume_trup_var, string nume_album_var, float raritate_var, bool mint_var)
    : Disc(nume_var, cantitate_var, cod_var, pret_baza_var, tip_var, casa_de_discuri_var,
           data_lansare_var, nume_trup_var, nume_album_var),
      raritate(raritate_var), mint(mint_var)
{
    try
    {
        if (raritate < 1 || raritate > 5)
        {
            throw std::out_of_range("Raritatea trebuie sa fie cuprinsa intre 1 si 5");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
};

Disc_Vint::~Disc_Vint() {};

float Disc_Vint::getPret()
{
    int pret = pret_baza + raritate * 15 + 5;
    return pret;
}

void Disc_Vint::afisareInfo() const
{
    Disc::afisareInfo();
    cout << "Raritate: " << raritate << endl;
    if (mint == true)
        cout << "Discul este mint" << endl;
    else
        cout << "Discul nu este mint" << endl;
}
void Disc_Vint::PretFinal()
{
    cout << "Pret final (+livrare): " << (this)->getPret() << endl;
}