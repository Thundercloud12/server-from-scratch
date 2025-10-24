#include "SimpleSocket.hpp"
#include <stdio.h>

SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interfacee)
{
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interfacee);
    sock = socket(domain, service, protocol);
    test_connection(sock);
}

void SimpleSocket::test_connection(int item_to_test)
{
    if (item_to_test == SOCKET_ERROR)
    {
        std::cerr << "Winsock call failed, code: " << WSAGetLastError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void SimpleSocket::test_connection(SOCKET item_to_test)
{
    if (item_to_test == INVALID_SOCKET)
    {
        std::cerr << "Socket creation/accept failed, code: " << WSAGetLastError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in SimpleSocket::get_socket_address()
{
    return address;
}

SOCKET SimpleSocket::get_socket()
{
    return sock;
}

SOCKET SimpleSocket::get_connection()
{
    return connection;
}

void SimpleSocket::set_connection(SOCKET con)
{
    connection = con;
}
