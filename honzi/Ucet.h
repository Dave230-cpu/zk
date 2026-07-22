#pragma once
#include <string>
#include <vector>
using namespace std;

class Ucet
{
protected:
    string cisloUctu;
    vector<double>historieTransakci;

private:
    static int pocetUctu;
public:
    Ucet(string cisloUctu);
    virtual ~Ucet();
    static int getpocetUctu();
    void pridejTransakci(double hodnota);
    void pridejTransakce(const vector<double>& hodnoty);
    vector<double>& getHistorieTransakci();
    void virtual analyzujUcet() const = 0;
    void virtual vypisInfo() const;
    
};


