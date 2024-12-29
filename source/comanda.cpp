#include "../headers/comanda.h"

int Comanda::nr_comenzi = 0;

Comanda::Comanda(time_t data_plasare_v, time_t durata_solutionare_v, int nr_produse_v, vector<Produs *> p_v)
    : durata_solutionare(durata_solutionare_v), nr_produse(nr_produse_v), data_plasare(data_plasare_v)
{
    id_comanda++;
    nr_comenzi++;
    int nr_disc = 0, nr_vestim = 0;
    float val_comanda = 0;
    bool cerinte_respectate = true;

    try
    {
        for (int i = 0; i < nr_produse; i++)
        {
            if (typeid(*p_v[i]).name() == typeid(Vestimentatie).name())
            {
                nr_vestim++;
            }
            if (typeid(*p_v[i]).name() == typeid(Disc).name() || typeid(*p_v[i]).name() == typeid(Disc_Vint).name())
            {
                nr_disc++;
            }
            if (nr_disc >= 4 || nr_vestim >= 6)
            {
                cerinte_respectate = false;
                throw std::invalid_argument("Numarul maxim de obiecte depasit.");
            }
            val_comanda += p_v[i]->getPret_de_baza();
        }

        if (val_comanda < 100)
        {
            throw std::invalid_argument("Valoarea comenzii este sub limita minima de 100.");
        }
        if (difftime(time(NULL), data_plasare_v) > durata_solutionare)
        {
            throw std::invalid_argument("Durata de solutionare a fost depasita.");
        }
        for (int i = 0; i < nr_produse; i++)
        {
            p.push_back(p_v[i]);
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Eroare: " << e.what() << std::endl;
    }
    id_comanda++;
}

Comanda::Comanda(const Comanda &other)
{
    data_plasare = other.data_plasare;
    durata_solutionare = other.durata_solutionare;
    nr_produse = other.nr_produse;

    for (int i = 0; i < nr_produse; i++)
        p.push_back(other.p[i]);
    id_comanda++;
}
Comanda &Comanda::operator=(const Comanda &other)
{
    if (this != &other)
    {
        id_comanda++;
        if (!p.empty())
        {
            for (int i = 0; i < p.size(); i++)
                if (p[i] != nullptr)
                    delete p[i];
            p.clear();
        }
        durata_solutionare = other.durata_solutionare;
        nr_produse = other.nr_produse;

        for (int i = 0; i < nr_produse; i++)
        {
            p.push_back(other.p[i]);
        }
    }
    return *this;
}
Comanda::~Comanda()
{
    for (int i = 0; i < p.size(); i++)
        delete p[i];
    p.clear();
    nr_comenzi--;
}

void Comanda::afisare() const
{
    cout << endl
         << "=====================" << endl
         << "Data plasare a comenzii: " << ctime(&data_plasare) << endl;
    cout << "Data finalizare a comenzii: " << ctime(&durata_solutionare) << endl;

    for (int i = 0; i < p.size(); i++)
    {
        p[i]->afisareInfo();
    }
    cout << "=====================";
}

Comanda::Comanda(Comanda &&other) noexcept
    : data_plasare(other.data_plasare),
      durata_solutionare(other.durata_solutionare),
      nr_produse(other.nr_produse),
      p(std::move(other.p))
{

    other.data_plasare = 0;
    other.durata_solutionare = 0;
    other.nr_produse = 0;
    nr_comenzi++;
}

Comanda &Comanda::operator=(Comanda &&other) noexcept
{
    if (this != &other)
    {
        if (!p.empty())
        {
            for (int i = 0; i < p.size(); i++)
                if (p[i] != nullptr)
                    delete p[i];
            p.clear();
        }

        data_plasare = other.data_plasare;
        durata_solutionare = other.durata_solutionare;
        nr_produse = other.nr_produse;
        p = std::move(other.p);

        other.data_plasare = 0;
        other.durata_solutionare = 0;
        other.nr_produse = 0;
    }
    return *this;
}

int Comanda::valoareComanda() const
{
    int valoare = 0;
    bool vest = false, disc = true;

    for (int i = 0; i < p.size(); i++)
    {
        valoare = valoare + p[i]->getPret();
        if (typeid(*p[i]).name() == typeid(Vestimentatie).name() && vest == false)
        {
            vest = true;
            valoare = valoare + 20;
        }
        if ((typeid(*p[i]).name() == typeid(Disc).name() || typeid(*p[i]).name() == typeid(Disc_Vint).name()) && disc == false)
        {
            disc = true;
            valoare = valoare + 5;
        }
    }
    return valoare;
}

int Comanda::getNrProduse() const
{
    return nr_produse;
}

bool Comanda::verificareStoc(vector<Produs *> &stoc)
{
    int produse_gasite = 0;

    for (int i = 0; i < nr_produse; i++)
    {
        bool gasit = false;

        for (int j = 0; j < stoc.size(); j++) // Explicit indexing for the second loop
        {
            if (*stoc[j] == *p[i]) // Compare dereferenced pointers
            {
                if (stoc[j]->getCantitate() > 0)
                {
                    stoc[j]->setCantitate(stoc[j]->getCantitate() - 1);
                    produse_gasite++;
                    gasit = true;
                    break; // Stop searching after finding the product
                }
            }
        }

        if (!gasit) // If a product wasn't found, stop searching for the rest
        {
            return false;
        }
    }

    return produse_gasite == nr_produse;
}

int Comanda::getID_comanda() const
{
    return id_comanda;
}