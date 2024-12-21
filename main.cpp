#include <iostream>
#include "./headers/angajat.h"
// #include "./headers/comanda.h"
#include "./headers/functii_angajati.h"
#include <fstream>

using namespace std;

int main()
{
    // Citire date din fisier
    vector<Angajat> persoane;
    string fileName = "./data_in/info_angajati.in";
    initAngajati(persoane, fileName);

    // MENIU
    bool meniu_functionare = true;
    int optinune;

    while (meniu_functionare != false)
    {
        // MENIU PRINCIPAL
        cout << "Buna ziua!" << endl;
        cout << "Ce informatii doriti sa folositi?" << endl;
        cout << "--------------" << endl;
        cout << "1-Angajati" << endl;
        cout << "2-Comanda" << endl;
        cout << "3-Magazin" << endl;
        cout << "0-Iesire meniu prinicipal" << endl;
        cout << "--------------" << endl;

        cin >> optinune;
        if (optinune == 0)
        {
            cout << "Ati iesit din meniu principal" << endl;
            break;
        }
        if (optinune == 1) // MENIU GESTIONARE ANGAJATI
        {
            bool meniu_ang = false;
            while (meniu_ang == false)
            {
                // adăugare, ștergere, modificare, afișare date angajat, afișarea tuturor angajaților
                cout << "Ce doriti sa faceti?" << endl;
                cout << "--------------" << endl;
                cout << "Adaugare angajat(1)" << endl;
                cout << "Afisare date angajat(2)" << endl;
                cout << "Afisarea tuturor angjatilor(3)" << endl;
                cout << "Modificare datelor unui angjat(4)" << endl;
                cout << "Stergere Angajat(5)" << endl;
                cout << "--------------" << endl;
                cout << "Intoarcere MENIU PRINCIPAL(0)" << endl;
                cout << "--------------" << endl;
                int opt_ang;
                cin >> opt_ang;

                if (opt_ang == 0) // Iesire din meniu angajat
                    meniu_ang = true;

                if (opt_ang == 1) // Adaugare Angajat;
                {

                    addAngajat(persoane);
                }
                if (opt_ang == 2) // Afisare date angajat
                {
                    afisareAngajat(persoane);
                }
                if (opt_ang == 3) // Afisare datele tuturor angajatilor
                {
                    afisareALL_Angajat(persoane);
                }
                if (opt_ang == 4) // Schimbare nume angjat
                {
                    modif_date_angajat(persoane);
                }
                if (opt_ang == 5)
                {
                    stergereAngajat(persoane);
                }
            }
        }
    }

    return 0;
}