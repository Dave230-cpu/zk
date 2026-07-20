#include "Server.h"

int Server::pocetServeru = 0;

Server::Server(string hostname) : hostname(hostname)
{
    pocetServeru++;
}

Server::~Server()
{
    pocetServeru--;
}

vector<double>& Server::getHistorie()
{
    return this->historie;
}

int Server::getPocetServeru()
{
    return pocetServeru;
}

void Server::pridejHodnotu()
{
}

void Server::pridejHodnotu(double hodnota)
{
    this->historie.push_back(hodnota);
}
