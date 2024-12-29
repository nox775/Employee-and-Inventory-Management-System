#pragma once
#include <vector>
#include "../headers/angajat.h"
#include <string>
#include <sstream>
#include "operator.h"

using namespace std;

bool verificare_functionare_magazin(vector<Angajat>);
static time_t convertStringToTimeT(const string &);
void initAngajati(vector<Angajat> &, vector<Operator> &, string);
void addAngajat(vector<Angajat> &);
int getVarstaFromCNP(string);
void afisareAngajat(vector<Angajat>);

void afisareALL_Angajat(vector<Angajat>);
void modif_date_angajat(vector<Angajat> &);
void stergereAngajat(vector<Angajat> &);