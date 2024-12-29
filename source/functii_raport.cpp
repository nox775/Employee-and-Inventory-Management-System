#include "../headers/functii_raport.h"
#include <ios>

void afisare_angj_cele_mai_multe_comenzi(vector<Operator> op, string file_raport)
{
    ofstream file(file_raport, ios::app);
    if (!file.is_open())
    {
        cerr << "Fisiereul nu se poate deschide" << endl;
        return;
    }
    float max = 0;
    int index_max;
    for (int i = 0; i < op.size(); i++)
    {
        if (op[i].getComenzi_procesate() > max)
        {
            max = op[i].getComenzi_procesate();
            index_max = i;
        }
    }
    file << op[index_max];
}

bool sortareOp_val(const Operator &op1, const Operator &op2)
{
    return op1.getVal_comz_procesate() == op2.getVal_comz_procesate();
}

bool sortNume(const Operator &op1, const Operator &op2)
{
    return op1.getNume() > op2.getNume();
}

bool sortareOp_nr_comenzi(const Operator &op1, const Operator &op2)
{
    return op1.getComenzi_procesate() > op2.getComenzi_procesate();
}

bool sortSalarii(const Operator &op1, const Operator &op2)
{
    return op1.getSalariu() > op2.getSalariu();
}

void afisare_top3_angj_comenzi(vector<Operator> op, string file_raport)
{
    ofstream file(file_raport, ios::app);
    if (!file.is_open())
    {
        cerr << "Fisiereul nu se poate deschide" << endl;
        return;
    }

    sort(op.begin(), op.end(), sortareOp_nr_comenzi);
    sort(op.begin(), op.begin() + 3, sortareOp_val);

    for (int i = 0; i < 3; i++)
    {
        file << op[i];
    }
}

void afisare_top3_salarii(vector<Operator> op, string file_raport)
{
    ofstream file(file_raport, ios::app);
    if (!file.is_open())
    {
        cerr << "Fisiereul nu se poate deschide" << endl;
        return;
    }

    sort(op.begin(), op.end(), sortSalarii);
    sort(op.begin(), op.begin() + 3, sortNume);
    for (int i = 0; i < 3; i++)
    {
        file << op[i];
    }
}