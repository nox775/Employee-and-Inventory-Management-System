#include "../headers/comanda.h"

Comanda::Comanda(string data_plasare_v, int durata_solutionare_v, int nr_produse_v, Produs **p_v) : data_plasare(data_plasare_v),
                                                                                                    durata_solutionare(durata_solutionare_v), nr_produse(nr_produse_v)
{
    int nr_disc = 0, nr_vestim = 0;
    float val_comanda = 0;
    bool cerinte_respectate = true;

    for (int i = 0; i < nr_produse; i++) // Verific daca comanda poate fi procesata;
    {
        if (typeid(p_v[i]).name() == "Vestimentatie")
            nr_vestim++;
        if (typeid(p_v[i]).name() == "Disc" || typeid(p_v[i]).name() == "Disc_Vint")
        {
            nr_disc++;
        }
        if (nr_disc >= 4 || nr_vestim >= 6)
        {
            cout << "Comanda nu poate fi plasata" << endl;
            cout << "---Numarul maxim de obiecte depasit---" << endl;
            cerinte_respectate = false;
            break;
        }
        val_comanda = val_comanda + (p_v[i])->getPret_de_baza();
        if (val_comanda > 100)
        {
            cout << "Comanda nu poate fi plasata" << endl;
            cout << "---Valaore comanda a fost depasit (100)---" << endl;
            cerinte_respectate = false;
            break;
        }
    }

    /// mai lucreaza aici;
}
Comanda::Comanda(const Comanda &)
{
}
Comanda &Comanda::operator=(const Comanda &)
{
}
Comanda::~Comanda()
{
    delete[] p;
}