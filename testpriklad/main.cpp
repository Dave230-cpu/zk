#include <iostream>
#include "WebovyServer.h"

int pocetSkoku(const std::vector<double>& historie){
    int skokCount = 0;
    for (int i = 1; i < historie.size(); i++)
    {
        int rozdil = historie[i] - historie[i-1];
        if (rozdil <= -30 || rozdil >= 30)
        {
            skokCount++;
        }
    }
    return skokCount;  
}

int main(){

    std::vector<Server*> servers;
    double promena = 10;

    std::cout << "Pocet serveru:" << Server::getPocetServeru() << std::endl;

    servers.push_back(new WebovyServer("Alexandra", 4000));
    servers.push_back(new WebovyServer("Kazdic", 4001));

    std::cout << "Pocet serveru:" << Server::getPocetServeru() << std::endl;

    WebovyServer server1 = *(static_cast<WebovyServer*>(servers[0]));
    WebovyServer server2 = *(static_cast<WebovyServer*>(servers[1]));

    server1.getHistorie() = {20, 50, 100, 40, 30, 20};

    std::cout << server1 << std::endl;
    std::cout << server2 << std::endl;

    server1.vypisInfo();

    std::cout << ((server2 < server1)?"Je mensi" : "Neni mensi") << std::endl;

    std::cout << pocetSkoku(server1.getHistorie()) << std::endl;
  

    return 0;
}