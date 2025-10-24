#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>
#include "BindingSocket.hpp"

class ListeningSocket : public BindingSocket
{
private:
    int backlog;
    int listening;

public:
    ListeningSocket(int domain, int service, int protocol, int port, u_long interfacee, int bklg);
    void start_listening();
    int connect_to_network(SOCKET sock, struct sockaddr_in address);
};

#endif