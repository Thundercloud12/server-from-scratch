#include "ListeningSocket.hpp"

ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interfacee, int bklg):BindingSocket(domain,service,protocol,port,interfacee){
    backlog = bklg;
    start_listening();
    std::cout<<listening<<std::endl;
    test_connection(listening);

}

void ListeningSocket::start_listening()
{

    std::cout<<"1"<<std::endl;
    listening = listen(get_socket(), backlog);
}

int ListeningSocket::connect_to_network(SOCKET sock, struct sockaddr_in address)
{
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}
