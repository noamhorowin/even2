//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_MYPARALLELSERVER_H
#define EVEN2_MYPARALLELSERVER_H

#include "ServerSide.h"
#include <pthread.h>
#include <bits/pthreadtypes.h>
#include <vector>

class MyParallelServer : public server_side::Server{
    static void* thread_func(void* arg);
    static void* handleThread(void* arg);
    static void timeout(std::vector<pthread_t>running);
    public:
    MyParallelServer(){}
    virtual int open(int portNumber, ClientHandler* c);
    virtual void close(){}


};


#endif //EVEN2_MYPARALLELSERVER_H
