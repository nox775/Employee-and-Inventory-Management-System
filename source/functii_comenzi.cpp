#include "../headers/comanda.h"
#include <fstream>

time_t stringToTimeT(const std::string &dateStr)
{
    struct tm timeStruct = {};

    strptime(dateStr.c_str(), "%Y-%m-%d %H:%M:%S", &timeStruct);

    return mktime(&timeStruct);
}

void initComenzi(vector<Comanda> &c, string filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Fisiereul nu se poate deschide" << endl;
        return;
    }
    int nr_comenzi;
    fin >> nr_comenzi;
    Comanda::nr_comenzi = nr_comenzi;
    for (int i = 0; i < nr_comenzi; i++)
    {
        string buffer;
        getline(fin, buffer);
        time_t data_plasare = stringToTimeT(buffer);
        getline(fin, buffer);
        time_t durata_solutionare = stringToTimeT(buffer);
        int nr_produse;
        fin >> nr_produse;
        vector<Produs *> p;
        for (int j = 0; j < nr_produse; j++)
        {
            string tip, nume;
            int cantitate;
            float pret_baza;
            getline(fin, tip, ',');
            string nume = "";

            if (tip == "Disc")
            {
            }
        }
    }
}