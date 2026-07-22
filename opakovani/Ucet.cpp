#include "Ucet.h"
#include <iostream>
using namespace std;

int Ucet:: pocet = 0;
Ucet::Ucet(string cisloUctu) : cisloUctu(cisloUctu)
{
    pocet++;
}
Ucet::~Ucet()
{
    pocet--;
}

int Ucet::getpocet()
{
    return pocet;
}

void Ucet::pridejTransakci(double hodnota)
{
    this->historieTranskaci.push_back(hodnota);
}

void Ucet::pridejtransakci(const vector<double> &hodnoty)
{
    for (int i = 0; i < historieTranskaci.size(); i++)
    {
        this->pridejTransakci(hodnoty[i]);
    }
    
}
vector<double> &Ucet::gethistorieTransakci()
{
    return this-> historieTranskaci;
}

void Ucet::vypisInfo() const
{
    cout<<"Cislo uctu:"<<this->cisloUctu<<"Transakce:"<<this->historieTranskaci.size();
}
