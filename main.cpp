#include <iostream>
#include "./headers/angajat.h"
#include "./headers/functii_angajati.h"
#include "./headers/functii_comenzi.h"
#include "./headers/functii_stoc.h"
#include <fstream>
#include <limits>

using namespace std;

int main()
{
    // Citire date din fisier intr-un vector de angajati
    vector<Angajat> angajati;
    vector<Operator> operatori;
    string fileName1 = "./data_in/info_angajati.in"; // Datele au fost generate cu AI
    initAngajati(angajati, operatori, fileName1);

    vector<Produs *> stoc;
    string fileName2 = "./data_in/info_stoc.in"; // Datele au fost generate cu AI
    initStoc(stoc, fileName2);

    // Citire date din fisier intr-un vector de comenzi
    vector<Comanda> comenzi;
    string fileName3 = "./data_in/info_comenzi.in"; // Datele au fost generate cu AI
    initComenzi(comenzi, fileName3);

    // startOperatori(comenzi, operatori, stoc);

    // MENIU
    bool meniu_functionare = true;
    int optiune = 0;

    while (meniu_functionare != false)
    {
        // MENIU PRINCIPAL
        cout << "Buna ziua!" << endl;
        cout << "Ce informatii doriti sa folositi?" << endl;
        cout << "--------------" << endl;
        cout << "1-Angajati" << endl;
        cout << "2-Stoc" << endl;
        cout << "3-Comanda" << endl;
        cout << "4-Raport" << endl;
        cout << "0-Iesire meniu prinicipal" << endl;
        cout << "--------------" << endl;

        cin >> optiune;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Optiune invalida! Te rog sa alegi o optiune valida." << endl;
            continue;
        }

        if (optiune == 0)
        {
            cout << "Ati iesit din meniu principal" << endl;
            meniu_functionare = false;
        }
        else if (optiune == 1) // MENIU GESTIONARE ANGAJATI
        {
            bool meniu = false;
            while (meniu == false)
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

                int optiune_secundara;
                cin >> optiune_secundara;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Optiune invalida! Te rog sa alegi o optiune valida." << endl;
                    continue;
                }

                if (optiune_secundara == 0) // Iesire din meniu angajat
                    meniu = true;
                else if (optiune_secundara == 1) // Adaugare Angajat;
                {

                    addAngajat(angajati);
                }
                else if (optiune_secundara == 2) // Afisare date angajat
                {
                    afisareAngajat(angajati);
                }
                else if (optiune_secundara == 3) // Afisare datele tuturor angajatilor
                {
                    afisareALL_Angajat(angajati);
                }
                else if (optiune_secundara == 4) // Schimbare nume angjat
                {
                    modif_date_angajat(angajati);
                }
                else if (optiune_secundara == 5) // scoatere din firma a unui angajat
                {
                    stergereAngajat(angajati);
                }
            }
        }
        else if (optiune == 2) // MENIU GESTUIONARE PRODUSE/STOC
        {

            bool meniu = false;
            while (meniu == false)
            {
                // adăugare, ștergere, modificare, afișare date produs, afișarea tuturor produselor din stoc
                cout << "--------------" << endl;
                cout << "Ce doriti sa faceti?" << endl;
                cout << "--------------" << endl;
                cout << "Adaugare produs(1)" << endl;
                cout << "Afisare date produs(2)" << endl;
                cout << "Afisarea tuturor produselor din stoc(3)" << endl;
                cout << "Modificarea stocului unui produs(4)" << endl;
                cout << "Stergere produs din stoc(5)" << endl;
                cout << "--------------" << endl;
                cout << "Intoarcere MENIU PRINCIPAL(0)" << endl;
                cout << "--------------" << endl;

                int optiune_secundara;
                cin >> optiune_secundara;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Optiune invalida! Te rog sa alegi o optiune valida." << endl;
                    continue;
                }

                if (optiune_secundara == 0) // Iesire din meniu stoc
                    meniu = true;

                else if (optiune_secundara == 1) // Adaugare Produs;
                {
                    addProdus(stoc);
                }
                else if (optiune_secundara == 2) // Afisare date produs
                {
                    afisareProdus(stoc);
                }
                else if (optiune_secundara == 3) // Afisare toate produsele din stoc
                {
                    afisareStoc(stoc);
                }
                else if (optiune_secundara == 4) // Modificare Stoc
                {
                    modificare_Stoc(stoc);
                }
                else if (optiune_secundara == 5) // Stergere produs din stoc;
                {
                    stergereProdus(stoc);
                }
            }
        }
        else if (optiune == 3) // MENIU GESTUIONARE COMENZI
        {

            bool meniu = false;
            while (meniu == false)
            {
                // adăugare, ștergere, modificare, afișare date produs, afișarea tuturor produselor din stoc
                cout << "--------------" << endl;
                cout << "Ce doriti sa faceti?" << endl;
                cout << "--------------" << endl;
                cout << "Afisare comenzi(1)" << endl;
                cout << "Start ziua de lucru(2)" << endl;
                cout << "--------------" << endl;
                cout << "Intoarcere MENIU PRINCIPAL(0)" << endl;
                cout << "--------------" << endl;

                int optiune_secundara;
                cin >> optiune_secundara;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Optiune invalida! Te rog sa alegi o optiune valida." << endl;
                    continue;
                }

                if (optiune_secundara == 0) // Iesire din meniu stoc
                    meniu = true;
                else if (optiune_secundara == 1) // Afisare comenzi
                {
                    afisareComenzi(comenzi);
                }
                else if (optiune_secundara == 2) // Incepe munca operatorilor
                {
                    startOperatori(comenzi, operatori, stoc);
                }
            }
        }
    }

    return 0;
}
