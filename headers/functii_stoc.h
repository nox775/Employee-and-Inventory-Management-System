#include "disc.h"
#include "disc_vint.h"
#include "produs.h"
#include "vestimentatie.h"
#include <vector>

#pragma once

static time_t convertStringToTimeT(const string &);
void initStoc(vector<Produs *> &, string);
void addProdus(vector<Produs *> &);
void afisareProdus(vector<Produs *>);
void afisareStoc(vector<Produs *>);
void modificare_Stoc(vector<Produs *> &);
void stergereProdus(vector<Produs *> &);