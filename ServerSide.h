//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_SERVERSIDE_H
#define EVEN2_SERVERSIDE_H


#include "ClientHandler.h"
#include "pthread.h"


namespace server_side {
    static pthread_mutex_t mutexi;
    class Server {
    public:
        virtual int open(int portNumber, ClientHandler* c)=0;
        virtual void close()=0;
    };
    struct MyParams
    {
        int sockfd;
        ClientHandler* c;
    };

}

#endif //EVEN2_SERVERSIDE_H
