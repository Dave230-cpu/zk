#pragma once
#include "Ucet.h"

class SporiciUcet : public Ucet
{
private:
    double urokovaSazba;
public:
    SporiciUcet(string cisloUctu, double urokovaSazba);
    virtual void vypisInfo() const override;
    void virtual analyzujUcet() const override;
};


