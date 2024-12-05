#include <iostream>
#include "./headers/angajat.h"

using namespace std;

int main()
{
    int ID = 536;         // trebuie sa fie unic
    string nume = "Alin"; // 3-10 caractere
    string prenume = "Dobre";
    char CNP[14] = "1861003013477";       // CNP valid
    int data_angajare[3] = {21, 3, 2020}; // ZZ_LL_AAAA
    string tip = "Manager";
    Angajat a(tip, ID, nume, prenume, CNP, data_angajare);
    a.afisare();

    return 0;
}