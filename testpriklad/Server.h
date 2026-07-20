#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Server
{
protected:
    string hostname;
    vector<double> historie;
    static int pocetServeru;
public:
    Server(string hostname);
    virtual ~Server();

    vector<double>& getHistorie();

    static int getPocetServeru();

    void pridejHodnotu();
    void pridejHodnotu(double hodnota);

    virtual void vypisInfo() const = 0;
};
