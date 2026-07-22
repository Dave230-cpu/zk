#pragma once
#include "Ucet.h"

class SporiciUcet : public Ucet
{
private:
    double UrokovaSazba;
public:
    SporiciUcet(string cisloUctu, double UrokovaSazba);
    void vypisInfo()const override;
    void analyzujteUcet() const override;
    
    
};


