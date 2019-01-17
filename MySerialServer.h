//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_MYSERIALSERVER_H
#define EVEN2_MYSERIALSERVER_H


#include "ServerSide.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class MySerialServer : public server_side::Server {
    static void* thread_func(void* arg);
public:
    MySerialServer(){}
    virtual int open(int portNumber, ClientHandler* c);
    virtual void close(){}
};


#endif //EVEN2_MYSERIALSERVER_H
