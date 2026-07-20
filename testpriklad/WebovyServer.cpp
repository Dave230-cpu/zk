#include "WebovyServer.h"
#include "Server.h"


WebovyServer::WebovyServer(std::string hostname, int port) : Server(hostname)
{
    this->port = port;
}

void WebovyServer::vypisInfo() const
{
    std::cout<< "hostname: "<< this->hostname << "port: "<< this->port <<std::endl;
}

std::ostream &operator<<(std::ostream &os, const WebovyServer &v)
{
    os << "Server (" << v.hostname<< ", " << v.port << ") Historie: ";
    for (double h : v.historie)
    {
        os << h;
    }
    
    return os;
}

bool WebovyServer::operator<(const WebovyServer &other) const
{
    return this->historie.size() < other.historie.size();
}

bool WebovyServer::over()
{
    for(double hodnota: this->historie){                     //this->historie ukazuje na ten náš vektor 
            if(hodnota>80){                                 //Tento cyklus projede vše nemusíme používat i++, porovnáváme všechny hodnoty vektoru s číslem 80.
                return true;
            }
         }
    return false;
     
}
