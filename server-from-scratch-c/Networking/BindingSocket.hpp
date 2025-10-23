#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"

class BindingSocket: public SimpleSocket{
    public:
        BindingSocket(int domain,int service,int protocol,int port, u_long interfacee);
        int connect_to_network(SOCKET sock, struct sockaddr_in address);

};


#endif
