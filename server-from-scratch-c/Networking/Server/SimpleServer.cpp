#include "SimpleServer.hpp"

SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interfacee, int bklg)
{
    socket = new ListeningSocket(domain,service,protocol,port,interfacee,bklg);

}

void SimpleServer::launcher()
{
    
}

ListeningSocket * SimpleServer::get_socket(){
    return socket;
}