#pragma once
#include <string>
#include <vector>
using namespace std;
class Ucet
{
protected:
string cisloUctu;
vector<double> historieTranskaci;
private:
static int pocet;
    
public:
    Ucet(string cisloUctu);
    virtual~Ucet();
    static int getpocet();
    void pridejTransakci(double hodnota);
    void pridejtransakci(const vector<double>& hodnoty);
    vector<double>& gethistorieTransakci();
    virtual void analyzujteUcet() const = 0;
    virtual void vypisInfo() const;
};


