#include "ConnectingSocket.hpp"

ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interfacee) : SimpleSocket(domain, service, protocol, port, interfacee)
{
    set_connection(connect_to_network(get_socket(), get_socket_address()));
    test_connection(get_connection());
}

int ConnectingSocket::connect_to_network(SOCKET sock, struct sockaddr_in address)
{
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}