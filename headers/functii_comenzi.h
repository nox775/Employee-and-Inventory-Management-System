#pragma once
#include "comanda.h"
#include "angajat.h"
#include <algorithm>
#include "operator.h"
#include <queue>

time_t stringToTimeT(const std::string &);
void initComenzi(vector<Comanda> &, string);
time_t convertStringToTimeT(const std::string &);
void afisareComenzi(vector<Comanda>);

int solicitare_eliberare(vector<Operator>);
int cauta_op_ocupare_min(vector<Operator>);
void startOperatori(vector<Comanda>, vector<Operator> &, vector<Produs *>);
