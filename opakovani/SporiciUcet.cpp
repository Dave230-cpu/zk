#include "SporiciUcet.h"
#include <iostream>
using namespace std;

SporiciUcet::SporiciUcet(string cisloUctu, double UrokovaSazba) : Ucet(cisloUctu)
{
    this->UrokovaSazba = UrokovaSazba;
}

void SporiciUcet::vypisInfo() const
{
    Ucet::vypisInfo();
    cout<<"Urokova sazba:"<<UrokovaSazba<<"%"<<endl;

}

void SporiciUcet::analyzujteUcet() const
{
    int pocetvklady = 0;
    double soucetvkladu = 0;
    double prumer = 0;
    for (int i = 0; i < historieTranskaci.size(); i++)
    {
        if (historieTranskaci[i]>0)
        {
            pocetvklady++;
            soucetvkladu = historieTranskaci[i] + soucetvkladu;
        }
        
    }
    prumer = soucetvkladu / pocetvklady;
    cout<<"Prumerna hodnota vkladu: "<<prumer<<endl;

}
