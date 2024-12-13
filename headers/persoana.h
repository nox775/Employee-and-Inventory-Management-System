
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

    virtual ~Persoana();
};