#include "../headers/functii_stoc.h"
#include <fstream>
#include <sstream>

time_t convertStringToTimeT(const std::string &dateStr)
{
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> tm.tm_mday >> tm.tm_mon >> tm.tm_year;

    if (ss.fail() || tm.tm_mday < 1 || tm.tm_mday > 31 || tm.tm_mon < 1 || tm.tm_mon > 12 || tm.tm_year < 1900)
    {
        throw std::invalid_argument("Invalid date format or values: " + dateStr);
    }

    tm.tm_mon -= 1;
    tm.tm_year -= 1900;
    return std::mktime(&tm);
}

void initStoc(vector<Produs *> &stoc, string filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Fișierul nu s-a putut deschide: " << filename << endl;
        return;
    }

    int nr_produse_stoc;
    fin >> nr_produse_stoc;
    fin.ignore(); // Ignoră newline-ul după numărul de produse

    Produs::nr_produse_stoc = nr_produse_stoc;
    int count_disc = 0, count_disc_vint = 0, count_vest = 0;

    for (int i = 0; i < nr_produse_stoc; i++)
    {
        string line;
        getline(fin, line);
        stringstream ss(line);

        string nume;
        getline(ss, nume, ',');

        int cantitate, cod;
        float pret_baza;
        ss >> cantitate;
        ss.ignore(1, ',');
        ss >> pret_baza;
        ss.ignore(1, ',');
        ss >> cod;
        ss.ignore(1, ',');

        if (nume == "Disc" || nume == "Disc_Vint")
        {
            string tip, casa_de_discuri, buffer, nume_trup, nume_album;
            time_t data_lansare;

            getline(ss, tip, ',');
            getline(ss, casa_de_discuri, ',');
            getline(ss, buffer, ',');
            data_lansare = convertStringToTimeT(buffer);
            getline(ss, nume_trup, ',');

            if (nume == "Disc")
            {
                getline(ss, nume_album);
                count_disc++;
                stoc.push_back(new Disc(nume, cantitate, cod, pret_baza, tip, casa_de_discuri, data_lansare, nume_trup, nume_album));
            }
            else if (nume == "Disc_Vint")
            {
                getline(ss, nume_album, ',');
                float raritate;
                bool mint;
                ss >> raritate;
                ss.ignore(1, ',');
                ss >> mint;
                count_disc_vint++;
                stoc.push_back(new Disc_Vint(nume, cantitate, cod, pret_baza, tip, casa_de_discuri, data_lansare, nume_trup, nume_album, raritate, mint));
            }
        }
        else if (nume == "Vestimentatie")
        {
            string culoare, marca, tip;
            getline(ss, culoare, ',');
            getline(ss, marca, ',');
            getline(ss, tip);
            count_vest++;
            stoc.push_back(new Vestimentatie(nume, cantitate, cod, pret_baza, culoare, marca, tip));
        }
    }

    try
    {
        if (count_disc < 2 || count_disc_vint < 2 || count_vest < 2)
        {
            throw std::out_of_range("Nu sunt destule produse din fiecare tip în stoc");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Eroare: " << e.what() << '\n';
    }
}

void addProdus(vector<Produs *> &stoc)
{
    string nume;
    int cantitate, cod;
    float pret_baza;

    cout << "Ce tip de produs vreti sa adaugati? ";
    cin >> nume;
    cin.ignore();
    cout << endl;

    cout << "Ce cantiate?: ";
    cin >> cantitate;
    cin.ignore();
    cout << endl;

    cout << "Care este pretul de baza?: ";
    cin >> pret_baza;
    cin.ignore();
    cout << endl;

    cod = stoc.back()->getCod() + 1;
    if (nume == "Disc" || nume == "Disc_Vint")
    {
        string tip, casa_de_discuri, nume_trup, nume_album;
        time_t data_lansare;

        cout << "Ce gen de muzica este albumul: ";
        getline(cin, tip);
        cout << endl;

        cout << "Ce casa de discuri: ";
        getline(cin, casa_de_discuri);
        cout << endl;

        string data;

        cout << "Cand s-a lansat albumul: " << endl;
        getline(cin, data);
        data_lansare = convertStringToTimeT(data);
        cin.ignore();

        cout << "Nume trupa: ";
        getline(cin, nume_trup);
        cout << endl;

        cout << "Nume album: ";
        getline(cin, nume_album);
        cout << endl;

        if (nume == "Disc")
        {

            stoc.push_back(new Disc(nume, cantitate, cod, pret_baza, tip, casa_de_discuri, data_lansare, nume_trup, nume_album));
        }
        else if (nume == "Disc_Vint")
        {
            float raritate;
            cout << "Ce rariate are discul: ";
            cin >> raritate;
            cout << endl;

            bool mint;
            cout << "Este niscul mint DA(1) , NU(0)? : ";
            cin >> mint;
            cout << endl;

            stoc.push_back(new Disc_Vint(nume, cantitate, cod, pret_baza, tip, casa_de_discuri, data_lansare, nume_trup, nume_album, raritate, mint));
        }
    }
    else if (nume == "Vestimentatie")
    {
        string culoare, marca, tip;
        cout << "Ce culoare este articolul: ";
        getline(cin, culoare);
        cout << endl;

        cout << "Ce marca este articolul: ";
        getline(cin, marca);
        cout << endl;

        cout << "Ce tip este articolul: ";
        getline(cin, tip);
        cout << endl;

        stoc.push_back(new Vestimentatie(nume, cantitate, cod, pret_baza, culoare, marca, tip));
    }
}

void afisareProdus(vector<Produs *> stoc)
{
    int cod_cautat;
    cout << "Care este codul produsului caruia vreti sa-i afisati datele: ", cin >> cod_cautat, cout << endl;
    for (int i = 0; i < stoc.size(); i++)
    {
        if (cod_cautat == (stoc[i])->getCod())
        {
            stoc[i]->afisareInfo();
        }
    }
}

void afisareStoc(vector<Produs *> stoc)
{
    for (int i = 0; i < stoc.size(); i++)
    {
        stoc[i]->afisareInfo();
    }
}

void modificare_Stoc(vector<Produs *> &stoc)
{
    int cod_cautat;
    cout << "Care este codul produsului caruia vreti sa modificati cantitatea: ", cin >> cod_cautat, cout << endl;
    for (int i = 0; i < stoc.size(); i++)
    {
        if (cod_cautat == (stoc[i])->getCod())
        {
            int cantitate_nou;
            cout << "Produsul a fost gasit. Ce cantitate vreti sa aiba: ";
            cin >> cantitate_nou;
            cout << endl;
            stoc[i]->setCantitate(cantitate_nou);
        }
    }
}

void stergereProdus(vector<Produs *> &stoc)
{
    int cod_cautat;
    cout << "Care este codul produsului pe care doriti sa-l stergeti: ", cin >> cod_cautat, cout << endl;
    for (int i = 0; i < stoc.size(); i++)
    {
        if (cod_cautat == (stoc[i])->getCod())
        {

            cout << "Produsul a fost gasit. Ce cantitate vreti sa aiba: ";
            delete stoc[i];
            stoc.erase(stoc.begin() + i);
        }
    }
}