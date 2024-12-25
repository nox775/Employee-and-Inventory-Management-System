#include "../headers/comanda.h"

int Comanda::nr_comenzi = 0;

Comanda::Comanda(time_t data_plasare_v, time_t durata_solutionare_v, int nr_produse_v, vector<Produs *> p_v) : durata_solutionare(durata_solutionare_v), nr_produse(nr_produse_v)
{
    nr_comenzi++;
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
    try
    {
        if (cerinte_respectate == false)
        {
            cout << "Comanda nu a putu fi alocata" << endl;

            throw std::invalid_argument("Comenzile nu respecta cerintele necesare");
        }

        else
        {
            for (int i = 0; i < nr_produse; i++)
            {
                p.push_back(p_v[i]);
            }
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Caught invalid_argument error: " << e.what() << std::endl;
    }
    if (difftime(time(NULL), data_plasare_v) > durata_solutionare)
    {
        cout << "Comanda a depasit durata de solutionare" << endl;
        throw std::invalid_argument("Timp prea lung");
    }
    else
    {
        data_plasare = data_plasare_v;
    }

    /// mai lucreaza aici;
}
Comanda::Comanda(const Comanda &other)
{
    data_plasare = other.data_plasare;
    durata_solutionare = other.durata_solutionare;
    nr_produse = other.nr_produse;

    for (int i = 0; i < nr_produse; i++)
        p.push_back(other.p[i]);
}
Comanda &Comanda::operator=(const Comanda &other)
{
    if (this != &other)
    {
        int nr_disc = 0, nr_vestim = 0;
        float val_comanda = 0;
        bool cerinte_respectate = true;
        durata_solutionare = other.durata_solutionare;
        nr_produse = other.nr_produse;

        for (int i = 0; i < nr_produse; i++) // Verific daca comanda poate fi procesata;
        {
            if (typeid(other.p[i]).name() == "Vestimentatie")
                nr_vestim++;
            if (typeid(other.p[i]).name() == "Disc" || typeid(other.p[i]).name() == "Disc_Vint")
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
            val_comanda = val_comanda + (other.p[i])->getPret_de_baza();
            if (val_comanda > 100)
            {
                cout << "Comanda nu poate fi plasata" << endl;
                cout << "---Valaore comanda a fost depasit (100)---" << endl;
                cerinte_respectate = false;
                break;
            }
        }
        try
        {
            if (cerinte_respectate == false)
            {
                cout << "Comanda nu a putu fi alocata" << endl;

                throw std::invalid_argument("Comenzile nu respecta cerintele necesare");
            }

            else
            {
                for (int i = 0; i < nr_produse; i++)
                {
                    p.push_back(other.p[i]);
                }
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Caught invalid_argument error: " << e.what() << std::endl;
        }
        if (difftime(time(NULL), other.data_plasare) > durata_solutionare)
        {
            cout << "Comanda a depasit durata de solutionare" << endl;
            throw std::invalid_argument("Timp prea lung");
        }
        else
        {
            data_plasare = other.data_plasare;
        }
    }
    return *this;
}
Comanda::~Comanda()
{
    for (Produs *produs : p)
    {
        delete produs;
    }
    nr_comenzi--;
}