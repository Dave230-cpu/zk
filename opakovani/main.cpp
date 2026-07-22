#include "Ucet.h"
#include "BeznyUcet.h"
#include "SporiciUcet.h"
#include <iostream>
#include "vector"
#include "string"
using namespace std;
int nejradavkladu(Ucet& mujUcet){
    int aktualnirada = 0;
    int nejdelsirada = 0;
    vector<double> historie = mujUcet.gethistorieTransakci();
    for (int i = 0; i < historie.size(); i++)
    {
        if (historie[i]>0)
        {
            aktualnirada++;
        }
        if (aktualnirada>nejdelsirada)
        {
            nejdelsirada=aktualnirada;
        }
        if (historie[i]<0)
        {
            aktualnirada = 0;
        }
        
       
    }
    return nejdelsirada; 
}
void odstranenimalychvyberu(Ucet& mujUcet){
    vector<double> historie = mujUcet.gethistorieTransakci();
    for (int i = 0; i < historie.size(); )
    {
        if (historie[i] < 0 && historie[i]> -50)
        {
            historie.erase(historie.begin() + i);
        }
        i++;
    }
    
}








int main()
{
    // na zacatku vypisu pocet uctu, melo by byt 0
    cout << "Pocet uctu: " << Ucet::getpocet() << endl;

    // vytvorim vektor ukazatelu na Ucet
    // muzu do nej ulozit BeznyUcet i SporiciUcet
    vector<Ucet*> ucty;

    // pres new vytvorim 2 bezne ucty a 1 sporici ucet
    ucty.push_back(new BeznyUcet("CZ-1111", 50));
    ucty.push_back(new BeznyUcet("CZ-2222", 50));
    ucty.push_back(new SporiciUcet("CZ-3333", 4.5));

    // po vytvoreni by mely existovat 3 ucty
    cout << "Pocet uctu: " << Ucet::getpocet() << endl;


    // pridam transakce prvnimu uctu
    ucty[0]->pridejTransakci(100);
    ucty[0]->pridejTransakci(200);
    ucty[0]->pridejTransakci(300);
    ucty[0]->pridejTransakci(-20);
    ucty[0]->pridejTransakci(-100);

    // pridam transakce druhemu uctu
    ucty[1]->pridejTransakci(500);
    ucty[1]->pridejTransakci(-45);
    ucty[1]->pridejTransakci(600);

    // pridam transakce sporicimu uctu
    ucty[2]->pridejTransakci(1000);
    ucty[2]->pridejTransakci(2000);
    ucty[2]->pridejTransakci(-500);


    // projdu vsechny ucty
    // diky virtual se zavola spravna metoda podle skutecneho typu uctu
    for (int i = 0; i < ucty.size(); i++)
    {
        ucty[i]->vypisInfo();
        ucty[i]->analyzujteUcet();
    }


    // ALGORITMUS 1
    // zjistim nejdelsi radu kladnych transakci prvniho uctu
    cout << "Nejdelsi rada vkladu: "<< nejradavkladu(*ucty[0])<< endl;


    // ALGORITMUS 2
    // odstranim z prvniho uctu male vybery mezi -50 a 0
    odstranenimalychvyberu(*ucty[0]);


    // OPERATOR += a OPERATOR <<
    // prevedu ukazatel Ucet* na BeznyUcet* a pracuji primo s prvnim uctem
    BeznyUcet& prvniUcet = *(static_cast<BeznyUcet*>(ucty[0]));

    // pomoci += pridam novou transakci
    prvniUcet += 500;

    // pomoci << vypisu BeznyUcet
    cout << prvniUcet << endl;


    // OPERATOR ==
    // ziskam druhy BeznyUcet
    BeznyUcet& druhyUcet = *(static_cast<BeznyUcet*>(ucty[1]));

    // porovnam dva bezne ucty
    if (prvniUcet == druhyUcet)
    {
        cout << "Ucty jsou stejne" << endl;
    }
    else
    {
        cout << "Ucty nejsou stejne" << endl;
    }


    // vsechny objekty vytvorene pres new musim smazat pres delete
    for (int i = 0; i < ucty.size(); i++)
    {
        delete ucty[i];
    }


    // po smazani vsech uctu by mel byt pocet 0
    cout << "Pocet uctu na konci: "
         << Ucet::getpocet()
         << endl;

    return 0;
}