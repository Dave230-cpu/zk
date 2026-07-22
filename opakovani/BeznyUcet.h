#pragma once
#include "Ucet.h"
class BeznyUcet : public Ucet
{
private:
    double poplatek;
public:
    BeznyUcet(string cisloUctu, double poplatek);
    void vypisInfo() const override;
    void analyzujteUcet() const override;
    bool operator==(const BeznyUcet& DruhyUcet);
    void operator+= (double platba);
    friend std::ostream& operator<<(std::ostream& os, const BeznyUcet& v);
};


