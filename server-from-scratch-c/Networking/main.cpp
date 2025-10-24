#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "SimpleSocket.hpp"
#include "BindingSocket.hpp"
#include "ListeningSocket.hpp"
#include "ConnectingSocket.hpp"

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cout << "WSAStartup failed" << std::endl;
        return 1;
    }

    // Test SimpleSocket (basic socket creation)
    // SimpleSocket simpleSock(AF_INET, SOCK_STREAM, IPPROTO_TCP, 8080, INADDR_ANY);
    // std::cout << "SimpleSocket created successfully" << std::endl;

    // Test BindingSocket (bind to port)
    BindingSocket bindSock(AF_INET, SOCK_STREAM, IPPROTO_TCP, 8081, INADDR_ANY);
    std::cout << "BindingSocket created and bound successfully" << std::endl;

    // Test ListeningSocket (listen for connections)
    ListeningSocket listenSock(AF_INET, SOCK_STREAM, IPPROTO_TCP, 8080, INADDR_ANY, 5);
    std::cout << "ListeningSocket created and listening successfully" << std::endl;


    // Cleanup
    WSACleanup();
    std::cout << "All socket tests completed" << std::endl;
    return 0;
}