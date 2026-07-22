#include <iostream>
#include "Ucet.h"
#include "BeznyUcet.h"
#include "SporiciUcet.h"
using namespace std;

using namespace std;
void nejradaprvku(Ucet& muj_ucet) {
    int nejpocet = 0;
    int aktualni = 0;

    vector<double>& historie = muj_ucet.getHistorieTransakci();

    for (int i = 0; i < historie.size(); i++)
    {
        if (historie[i]>0)
        {
            aktualni++;
        }
        if (aktualni>nejpocet)
        {
            nejpocet = aktualni;
        }
        if (historie[i]<0)
        {
            aktualni = 0;
        }
        
    }
    cout<<"Nejdelsi:"<<nejpocet<<endl;
};


void odstranenimalprvku(Ucet& muj_ucet){

    vector<double>& historie = muj_ucet.getHistorieTransakci();
    for (int i = 0; i < historie.size();)
    {
        if (historie[i] < 0 && historie[i] > -50)
        {
            historie.erase(historie.begin() + i);
        }
        i++;
    }

};






int main(){
    cout<<"Pocet uctu: " << Ucet::getpocetUctu()<<endl;
    vector<Ucet*>ucty;
    ucty.push_back(new BeznyUcet("CZ-1111",50));
    ucty.push_back(new BeznyUcet("CZ-2222",30));
    ucty.push_back(new SporiciUcet("CZ-3333",4.5));

    BeznyUcet ucetPrvni = *(static_cast<BeznyUcet*>(ucty[0]));
    ucetPrvni += 500.0;

    cout << ucetPrvni << endl;

    for (int i = 0; i < ucty.size(); i++)
    {
        ucty[i]->vypisInfo();
        ucty[i]->analyzujUcet();
    }

    ucetPrvni.vypisInfo();

    nejradaprvku(ucetPrvni);
    for (int i = 0; i < ucty.size(); i++)
    {
        delete ucty[i];
    }
    cout << "Pocet uctu na konci: " << Ucet::getpocetUctu() << endl;
    return 0;
    
}
