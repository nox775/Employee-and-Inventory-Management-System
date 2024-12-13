#include "disc.h"

class Disc_Vint : public Disc
{
    float raritate = 0.0;
    bool mint = false;

public:
    Disc_Vint() = default;
    Disc_Vint(string, int, string, float, string, string, string, string, string, float, bool);

    ~Disc_Vint();

    float getPret();
};