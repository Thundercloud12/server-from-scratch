#ifndef TestServer_hpp
#define TestServer_hpp

#include <stdlib.h>

#include "../hdelib-sockets.hpp"
#include "SimpleServer.hpp"
#include <stdlib.h>
class TestServer: public SimpleServer
{
private:
    char buffer[30000]={0};
    SOCKET new_socket;
    void listener();
    void accepter();
    void handler();

public:
    TestServer();
    void launcher();
};

#endif