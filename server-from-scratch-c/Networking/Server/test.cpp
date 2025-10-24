#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "TestServer.hpp"

int main()
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        std::cerr << "WSAStartup failed: " << WSAGetLastError() << std::endl;
        return 1;
    }

    // now safe to create/use sockets
    TestServer t;

    // If TestServer::launcher runs forever, WSACleanup won't be reached.
    // If it returns, cleanup:
    WSACleanup();
    return 0;
}