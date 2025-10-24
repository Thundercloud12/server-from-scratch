#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <winsock2.h> 
#include <ws2tcpip.h>
#include <iostream>

class SimpleSocket
{
private:
    struct sockaddr_in address;
    SOCKET sock;
    SOCKET connection;

public:
    SimpleSocket(int domain, int service, int protocol, int port, u_long interfacee);
    virtual int connect_to_network(SOCKET sock, struct sockaddr_in address) = 0;
    void test_connection(int item_to_test);
    void test_connection(SOCKET item_to_test);
    struct sockaddr_in get_socket_address();
    SOCKET get_socket();
    SOCKET get_connection();
    void set_connection(SOCKET con);
};

#endif
