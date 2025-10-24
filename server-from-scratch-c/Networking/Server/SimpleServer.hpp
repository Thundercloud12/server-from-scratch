#ifndef SimpleServer_hpp
#define SimpleServer_hpp

#include <stdlib.h>

#include "../hdelib-sockets.hpp"

class SimpleServer{
    private:
        ListeningSocket *socket;
        virtual void listener()=0;
        virtual void accepter()=0;
        virtual void handler()=0;
    public:
        SimpleServer(int domain, int service, int protocol, int port, u_long interfacee, int bklg);
        virtual void launcher();
        ListeningSocket *get_socket();
};


#endif