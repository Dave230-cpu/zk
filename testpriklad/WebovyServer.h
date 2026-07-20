#pragma once

#include "Server.h"

class WebovyServer : public Server
{
private:
    int port;
public:
    WebovyServer(std::string hostname, int port);
    ~WebovyServer() = default;

    void vypisInfo() const override;
    friend std::ostream& operator<<(std::ostream& os, const WebovyServer& v);
    bool operator<(const WebovyServer& other) const;

    bool over();
};

