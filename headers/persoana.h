
#include <iostream>
#include <string>
#include <cstring>
#include <exception>
#include <ctime>

using namespace std;

class Persoana
{
protected:
    string nume = ""; // 3-10 caractere
    string prenume = "";
    string CNP = ""; // S	AA	LL	ZZ	JJ	NNN	C
public:
    Persoana() = default;
    Persoana(string, string, string);

    virtual void afisare() const;

    int getVarsta() const;
    void setNume(string);
    int *getDataNasterii() const;

    string getNume() const;
    string getPrenume() const;
    string getCNP() const;

    friend ostream &operator<<(ostream &, const Persoana &);

    virtual ~Persoana();
};