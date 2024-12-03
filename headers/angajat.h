
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Angajat
{
    int ID = "";      // trebuie sa fie unic
    string nume = ""; // 3-10 caractere
    string prenume = "";
    char CNP[13] = "";         // CNP valid
    int data_angajare[3] = ""; // ZZ_LL_AAAA
public:
    static int nr_angajati = 0;

    Angajat() = default;
    Angajat(int, string, string, char *, int *);

    int getSalariu(); // returneaza salariul unui angajat
    int getVechime(); // vechimea unui angajat in firma
}