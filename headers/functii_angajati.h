#pragma once
#include <vector>
#include "../headers/angajat.h"
#include <string>
#include <sstream>

using namespace std;

static time_t convertStringToTimeT(const string &);
void initAngajati(vector<Angajat> &, string);
void addAngajat(vector<Angajat> &);
int getVarstaFromCNP(string);
void afisareAngajat(vector<Angajat>);

void afisareALL_Angajat(vector<Angajat>);
void modif_date_angajat(vector<Angajat> &);
void stergereAngajat(vector<Angajat> &);