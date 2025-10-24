#include "TestServer.hpp"


using namespace std;

TestServer::TestServer():SimpleServer(AF_INET,SOCK_STREAM,0,8080,INADDR_ANY,10){
    launcher();
}


void TestServer::accepter(){
    struct sockaddr_in address = get_socket()->get_socket_address();
    int length1 = sizeof(address);
    new_socket = accept(get_socket()->get_socket(), (struct sockaddr *)&address, &length1);
    int rec = recv(new_socket, buffer, sizeof(buffer) - 1, 0);
    if (rec > 0) buffer[rec] = '\0';
}

void TestServer::listener(){
    std::cout<<buffer<<std::endl;
}

void TestServer::handler(){
    const char *hello = "Kaise ho sir??";
    int sent = send(new_socket, hello, (int)strlen(hello), 0);
    if (sent == SOCKET_ERROR)
    {
        std::cerr << "send failed: " << WSAGetLastError() << std::endl;
    }

    closesocket(new_socket);
}

void TestServer::launcher(){
    while(1){
        cout<<"===================TESTING==============="<<endl;
        accepter();
        listener();
        handler();
        cout<<"====DONE===OR....."<<endl;
    }
}