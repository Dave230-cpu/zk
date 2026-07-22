#pragma once
#include "Ucet.h"

class BeznyUcet : public Ucet
{
private:
    double poplatek;
public:
    BeznyUcet(string cisloUctu, double poplatek);
    void vypisInfo() const override;
    void analyzujUcet()const override;
    bool operator==(const BeznyUcet& ucetDruhy); 
    void operator+=(double platba); 
    friend std::ostream& operator<<(std::ostream& os, const BeznyUcet& mujUcet);
    // cout << BeznyUcet
    // Ucet A == Ucet B, Ucet A zavola tu funkci pretizeni operator== a ucet B je v tom pripade parametr
};


