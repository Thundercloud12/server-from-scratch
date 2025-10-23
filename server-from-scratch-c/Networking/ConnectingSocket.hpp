#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"

class ConnectingSocket : public SimpleSocket
{
public:
    ConnectingSocket(int domain, int service, int protocol, int port, u_long interfacee);
    int connect_to_network(SOCKET sock, struct sockaddr_in address);
};

#endif
