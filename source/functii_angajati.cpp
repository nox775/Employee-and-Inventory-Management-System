#include "../headers/functii_angajati.h"
#include <fstream>

bool verificare_functionare_magazin(vector<Angajat> employ)
{
    const string a = "Manager", b = "Asistent", c = "Operator";
    int count_a = 0, count_b = 0, count_c = 0;
    for (int i = 0; i < employ.size(); i++)
    {
        if (employ[i].getTip() == a)
            count_a++;
        else if (employ[i].getTip() == b)
            count_b++;
        else if (employ[i].getTip() == c)
            count_c++;
    }
    if (count_a == 1 && count_c >= 3 && count_b == 1)
    {

        return true;
    }
    else
    {
        try
        {
            throw std::invalid_argument("Dacă magazinul nu are: un manager, minim 3 operatori de comenzi, și un asistent, nu poate functiona.");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return false;
    }
}

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

void initAngajati(vector<Angajat> &persoane, string filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Fisiereul nu se poate deschide" << endl;
        return;
    }
    int nr_angajati;
    fin >> nr_angajati;

    for (int i = 0; i < nr_angajati; i++)
    {
        string nume, prenume;
        getline(fin >> std::ws, nume, ' ');
        getline(fin, prenume, ' ');

        string CNP, tip;
        int ID;
        string buffer_time;

        fin >> CNP >> tip >> ID;
        fin.ignore();
        getline(fin, buffer_time);

        time_t data_angajare = convertStringToTimeT(buffer_time);

        persoane.push_back(Angajat(tip, ID, data_angajare, nume, prenume, CNP));
    }
    bool ok = verificare_functionare_magazin(persoane);
    if (ok == false)
    {
        try
        {
            throw std::invalid_argument("Fisierul nu are o componenta buna");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

int getVarstaFromCNP(string CNP)
{
    int an, luna, zi;
    if (stoi(CNP.substr(0, 1)) == 1 || stoi(CNP.substr(0, 1)) == 2)
        an = 1900;
    else
        an = 2000;
    an = an + stoi(CNP.substr(1, 2));
    luna = stoi(CNP.substr(3, 2));
    zi = stoi(CNP.substr(5, 2));

    std::time_t t = std::time(nullptr); // Get current time
    std::tm *now = std::localtime(&t);  // Convert time_t to std::tm (local time)

    int ziua_curenta = now->tm_mday;    // Current day
    int luna_curenta = now->tm_mon + 1; // Current month (tm_mon is 0-based)
    int anul_curent = now->tm_year + 1900;

    int varsta;

    if (anul_curent == an)
        return 0;
    else
    {
        if ((luna_curenta == luna && ziua_curenta < zi) ||
            (luna_curenta < luna))
            varsta = anul_curent - an - 1;
        else
            varsta = anul_curent - an;
    }

    return varsta;
}

void addAngajat(vector<Angajat> &employ)
{
    cout << "Va rugam sa introduceti urmatoarele date pentru angajat" << endl;
    string nume, prenume;
    cout << "Nume: ", cin >> nume;
    cout << "Prenume: ", cin >> prenume;
    string CNP;
    cout << "CNP: ";
    cin >> CNP;
    if (getVarstaFromCNP(CNP) < 18)
    {
        cout << "Angajatul trebuie sa aiba 18" << endl;
        cout << "Angajatul nu poate fi ales. O zi buna" << endl;
        return;
    }

    string tip;
    cout << "Functie: ", cin >> tip;

    int ID = (employ.end() - 1)->getID() + 1; // Este automat atribuit;

    time_t data_angajare = time(nullptr);

    employ.push_back(Angajat(tip, ID, data_angajare, nume, prenume, CNP));
}

void afisareAngajat(vector<Angajat> employ)
{
    cout << "Scrie ID-ul angajatului caruia doresti sa afisezi datele" << endl;
    int ID;
    cin >> ID;
    for (int i = 0; i < Angajat::nr_angajati; i++)
    {
        if (employ[i].getID() == ID)
        {
            employ[i].afisare();
            break;
        }
    }
}

void afisareALL_Angajat(vector<Angajat> employ)
{
    for (int i = 0; i < Angajat::nr_angajati; i++)
        employ[i].afisare();
}

void modif_date_angajat(vector<Angajat> &employ)
{
    cout << "Scrie ID-ul angajatului caruie doresti sa-i modifici numele" << endl;
    int ID;
    cin >> ID;
    for (int i = 0; i < Angajat::nr_angajati; i++)
        if (ID == employ[i].getID())
        {
            cout << "Scrie nume nou" << endl;
            string nume;
            cin >> nume;
            employ[i].setNume(nume);
            break;
        }
}

void stergereAngajat(vector<Angajat> &employ)
{

    cout << "Scrie ID-ul angajatului care a demisionat s-au l-ai concediat" << endl;
    int ID;
    cin >> ID;
    for (int i = 0; i < Angajat::nr_angajati; i++)
        if (ID == employ[i].getID())
        {
            employ[i].Demisie();
            employ.erase(employ.begin() + i);
        }
    bool ok = verificare_functionare_magazin(employ);
    if (ok == false)
    {
        try
        {
            throw std::invalid_argument("Ai demisionat o persoana importanta => Magazinul nu  are destui angajati pentru a functiona");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}