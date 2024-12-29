#include "operator.h"
#include <fstream>
#pragma once
#include <algorithm>

bool sortareOp_val(const Operator &, const Operator &);
bool sortNume(const Operator &, const Operator &);
bool sortareOp_nr_comenzi(const Operator &, const Operator &);
bool sortSalarii(const Operator &, const Operator &);

void afisare_angj_cele_mai_multe_comenzi(vector<Operator>, string);
void afisare_top3_angj_comenzi(vector<Operator>, string);
void afisare_top3_salarii(vector<Operator>, string);