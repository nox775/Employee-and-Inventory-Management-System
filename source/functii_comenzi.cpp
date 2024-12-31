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
    int id_comanda = 99;

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
        id_comanda++;

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

        Comanda temp = Comanda(id_comanda, data_plasare, durata_solutionare, nr_produse, p);

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

void startOperatori(vector<Comanda> &c, vector<Operator> &op, vector<Produs *> &stoc)
{
    if (op.empty())
    {
        cout << "Nu exista operatori disponibili pentru procesarea comenzilor.\n";
        return;
    }
    //   int comenzi_procesate = 0;

    for (int i = 0; i < c.size(); i++)
    {

        if (c[i].verificareStoc(stoc))
        {
            bool comanda_efectuata = false;

            while (!comanda_efectuata)
            {
                int index_min = cauta_op_ocupare_min(op);

                if (op[index_min].getComenzi_in_lucru() == 3)
                {
                    cout << "Toti operatorii sunt ocupati in acest moment. Comanda este in asteptare." << endl;

                    bool solutionare = false;
                    while (!solutionare)
                    {
                        cout << "Exista operatori liberi? DA(1) NU(0): ";
                        cin >> solutionare;

                        if (solutionare)
                        {
                            int index_liber = solicitare_eliberare(op);
                            if (index_liber >= 0 && index_liber < op.size())
                            {
                                op[index_liber].solutionareComanda();
                                solutionare = true;
                                break;
                            }
                            else
                            {
                                cout << "Index invalid. Verificati ID-ul operatorului." << endl;
                            }
                        }
                    }
                }
                else
                {
                    op[index_min].adaugaComanda(c[i]);
                    cout << endl
                         << "=====================" << endl;

                    c[i].printData_plasare();
                    c[i].printData_solutionare();

                    cout << "ID COMANDA: " << c[i].getID_comanda() << endl
                         << "Valoare comanda: " << c[i].valoareComanda() << endl
                         << " A FOST ASIGNATA CATRE OPERATORUL CU ID: "
                         << op[index_min].getID() << endl;
                    cout << endl
                         << "=====================" << endl;

                    comanda_efectuata = true;
                }
            }
        }
        else
        {
            cout << "Comanda cu ID " << c[i].getID_comanda() << " nu s-a putut efectua. Produsele nu sunt in stoc." << endl;
        }
    }
    for (int i = 0; i < op.size(); i++) // finalizam comenziile
    {
        while (op[i].getComenzi_in_lucru() != 0)
        {
            cout << endl
                 << "=====================" << endl;
            op[i].solutionareComanda();
        }
    }
}
