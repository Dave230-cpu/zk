#include "BeznyUcet.h"
#include <iostream>
using namespace std;


BeznyUcet::BeznyUcet(string cisloUctu, double poplatek) : Ucet(cisloUctu)
{
    this->poplatek = poplatek;
}

void BeznyUcet::vypisInfo() const
{
    Ucet::vypisInfo();
    cout<<" Typ: Bezny Poplatek: "<<poplatek<<" Kc"<<endl;
}

void BeznyUcet::analyzujUcet() const
{
    int vybery = 0;
    for (int i = 0; i < historieTransakci.size(); i++)
    {
        if (historieTransakci[i]<0)
        {
            vybery++;
        }
        
    }
    cout<<"Vybery:"<<vybery<<endl;
}

bool BeznyUcet::operator==(const BeznyUcet &ucetDruhy)
{
    double poplatekPrvni = this->poplatek;
    double poplatekDruhy = ucetDruhy.poplatek;

    if (poplatekPrvni == poplatekDruhy) {
        return true;
    }
    return false;
}
// ucet += platba
void BeznyUcet::operator+=(double platba)
{
    this->pridejTransakci(platba);
}

ostream& operator<<(ostream& os, const BeznyUcet& mujUcet)
{
    os << "BeznyUcet["<<mujUcet.cisloUctu<<"], transakci: "<<mujUcet.historieTransakci.size();

    return os;
}
