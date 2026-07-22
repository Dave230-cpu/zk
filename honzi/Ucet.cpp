#include "Ucet.h"
#include <iostream>
using namespace std;
int Ucet:: pocetUctu = 0;

Ucet::Ucet(string cisloUctu) : cisloUctu(cisloUctu)
{
    pocetUctu++;
}

Ucet::~Ucet()
{
    pocetUctu--;
}

int Ucet::getpocetUctu()
{
    return pocetUctu;
}

void Ucet::pridejTransakci(double hodnota)
{
    this->historieTransakci.push_back(hodnota);
}

void Ucet::pridejTransakce(const vector<double>& hodnoty)
{
    for (double hodnota : hodnoty) {
        this->pridejTransakci(hodnota);
    }
}

vector<double>& Ucet::getHistorieTransakci()
{
    return this-> historieTransakci;
}
void Ucet::vypisInfo() const
{
    cout<<"Cislo uctu: "<<cisloUctu<<" Transkace pocet: "<<this->historieTransakci.size();
}
