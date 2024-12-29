#include "../headers/comanda.h"
#include "../headers/functii_comenzi.h"
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

time_t stringToTimeT(const std::string &dateStr)
{
    struct tm timeStruct = {};
    strptime(dateStr.c_str(), "%d %m %Y %H:%M:%S", &timeStruct);

    return mktime(&timeStruct);
}

int solicitare_eliberare(vector<Operator> op)
{ // returneaza index-ul operatorlui care este liber

    cout << "Scrie ID-ul operatorului care este disponibil: " << endl;
    int id_op, index;
    bool ok = false;
    while (ok == false)
    {
        cin >> id_op;
        for (int i = 0; i < op.size(); i++)
            if (op[i].getID() == id_op)
            {
                index = i;
                ok = true;
                break;
            }
        if (ok == false)
            cout << "Nu s-a gasit operatorul cu ID-ul transmis.Mai inceraca odata! " << endl;
    }
    return index;
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
    fin.ignore();
    Comanda::nr_comenzi = nr_comenzi;

    for (int k = 0; k < nr_comenzi; k++)
    {
        string buffer;
        getline(fin, buffer);
        time_t data_plasare = stringToTimeT(buffer);

        getline(fin, buffer);
        time_t durata_solutionare = stringToTimeT(buffer);

        int nr_produse;
        fin >> nr_produse;
        fin.ignore();

        vector<Produs *> p;
        for (int i = 0; i < nr_produse; i++)
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

                    p.push_back(new Disc(nume, cantitate, cod, pret_baza, tip, casa_de_discuri, data_lansare, nume_trup, nume_album));
                }
                else if (nume == "Disc_Vint")
                {
                    getline(ss, nume_album, ',');
                    float raritate;
                    bool mint;
                    ss >> raritate;
                    ss.ignore(1, ',');
                    ss >> mint;

                    p.push_back(new Disc_Vint(nume, cantitate, cod, pret_baza, tip, casa_de_discuri, data_lansare, nume_trup, nume_album, raritate, mint));
                }
            }
            else if (nume == "Vestimentatie")
            {
                string culoare, marca, tip;
                getline(ss, culoare, ',');
                getline(ss, marca, ',');
                getline(ss, tip);

                p.push_back(new Vestimentatie(nume, cantitate, cod, pret_baza, culoare, marca, tip));
            }
        }

        Comanda temp = Comanda(data_plasare, durata_solutionare, nr_produse, p);

        c.push_back(move(temp));
    }
}

void afisareComenzi(vector<Comanda> c)
{
    for (int i = 0; i < c.size(); i++)
        c[i].afisare();
}

int cauta_op_ocupare_min(vector<Operator> op)
{
    int min = 4;
    int index_min = 0;

    for (int i = 0; i < op.size(); i++)
    {
        if (op[i].getComenzi_in_lucru() <= min)
        {
            min = op[i].getComenzi_in_lucru();
            index_min = i;

            if (min == 0)
            {
                return i;
            }
        }
    }

    return index_min;
}

void startOperatori(vector<Comanda> c, vector<Operator> &op, vector<Produs *> stoc)
{
    int index_min = 0;

    for (int i = 0; i < c.size(); i++) // itereaza prin comenzi
    {
        bool disponibilitate = c[i].verificareStoc(stoc); // verifica daca produsele din comanda sunt in stoc

        cout << "PROCESARE COMANDA CU NUMARUL: " << i << endl;

        if (disponibilitate == true) // daca sunt in stoc produsele se executa
        {
            bool comanda_efectuata = false;

            while (comanda_efectuata == false)
            {
                cout << "INX" << endl;
                index_min = cauta_op_ocupare_min(op); // cauta operatorul care este cel mai liber

                cout << "INCEPUT-----COMANDA CU NR:  " << index_min << endl;

                if (op[index_min].getComenzi_in_lucru() == 3) // toti operatorii sunt ocupati
                {
                    cout << "Toti operatorii sunt ocupati in acest moment.Comanda va fi pus in asteptare." << endl;

                    bool solutionare = false;
                    while (solutionare == false) // asteapta ca operatorii sa fie disponibili
                    {
                        cout << "Exista operatori liberi? DA(1) NU(0): " << endl;
                        cin >> solutionare;

                        if (solutionare == true)
                        {
                            int index_liber = solicitare_eliberare(op);
                            op[index_liber].solutionareComanda();
                        }
                    }
                }
                else
                {
                    op[index_min].adaugaComanda(c[i]);
                    //
                    comanda_efectuata = true;
                    cout << "Schimbat comanda" << endl;
                }
                cout << "Am terminat" << endl;
            }
        }
        else
        {
            cout << "Comanda nu s-a putute efectua. Produsele nu sunt in stoc. ID comanda: " << c[i].getID_comanda() << endl;
        }

        //  op[i].afisare();

        cout << "Am iesit din bula" << endl;
    }
}