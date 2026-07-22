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
    cout<<"Poplatek:"<<poplatek<<"Kc"<<endl;
}

void BeznyUcet::analyzujteUcet() const
{
    int pocetvyberu = 0;
    for (int i = 0; i < historieTranskaci.size(); i++)
    {
        if (historieTranskaci[i]<0)
        {
            pocetvyberu++;
        }
        
        
    }
    cout<<"Pocet vyberu: "<<pocetvyberu<<endl;
    
}

bool BeznyUcet::operator==(const BeznyUcet &DruhyUcet)
{

    double poplatekPrvni = this->poplatek;
    double poplatekDruhy = DruhyUcet.poplatek;
    if (poplatekPrvni == poplatekDruhy)
    {
        return true;
    }
    return false;
}

void BeznyUcet::operator+=(double platba)
{
    this->pridejTransakci(platba);
}
std::ostream &operator<<(std::ostream &os, const BeznyUcet &v)
{
    os << "Bezny Ucet:"<< v.cisloUctu<< ", Transakce: " << v.historieTranskaci.size()<<endl;
    for (double h : v.historieTranskaci)
    {
        os << h;
    }
    
    return os;
}