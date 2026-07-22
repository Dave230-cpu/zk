#include "SporiciUcet.h"
#include <iostream>
using namespace std;

SporiciUcet::SporiciUcet(string cisloUctu, double urokovaSazba) : Ucet(cisloUctu)
{
    this->urokovaSazba = urokovaSazba;
}

void SporiciUcet::vypisInfo() const
{
    Ucet::vypisInfo();
    cout<<" Typ: Sporici Sazba uroku: "<<urokovaSazba<<"%"<<endl;
}

void SporiciUcet::analyzujUcet() const
{
    double soucet = 0;
    int pocet = 0;
    double prum = 0;
    for (int i = 0; i < historieTransakci.size(); i++)
    {
        if (historieTransakci[i]>0)
        {
            pocet++;
            soucet = soucet + historieTransakci[i];
        }
       
        
    }
    prum = soucet / pocet;
    cout<<"Prumerna hodnota vkladu: "<<prum<<endl;
    
    

}
