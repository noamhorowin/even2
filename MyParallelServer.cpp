//
// Created by noam on 1/17/19.
//

#include "MyParallelServer.h"

#include "ServerSide.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;


int MyParallelServer::open(int portNumber, ClientHandler *c) {

    int port = portNumber;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *) &serv, sizeof(serv)) < 0) {
        cerr << "Bad!" << endl;
    }
    struct server_side::MyParams *params = new server_side::MyParams();
    params->sockfd = s;
    params->c = c;
    pthread_t trid1;
    pthread_mutex_init(&server_side::mutexi, nullptr);
    pthread_create(&trid1, nullptr, MyParallelServer::thread_func, params);

}

void *MyParallelServer::thread_func(void *arg) {
    struct server_side::MyParams *params = (struct server_side::MyParams *) arg;
    int s = params->sockfd;
    ClientHandler *c = params->c;
    int new_sock;
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    vector<pthread_t> running;
    new_sock = accept(s, (struct sockaddr *) &client, &clilen);
    if (new_sock < 0) {
        if (errno == EWOULDBLOCK) {
            cout << "timeout!" << endl;
            exit(2);
        } else {
            perror("other error");
            exit(3);
        }
    }
    //c->handleClient(new_sock);
    struct server_side::MyParams *params2 = new server_side::MyParams();
    params2->sockfd = new_sock;
    params2->c = c;
    pthread_t trid2;
    pthread_create(&trid2, nullptr, MyParallelServer::handleThread, params2);
    running.push_back(trid2);

    while (true) {
        listen(s, 5);
        struct sockaddr_in client;
        socklen_t clilen = sizeof(client);

        timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

        new_sock = accept(s, (struct sockaddr *) &client, &clilen);
        if (new_sock < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                MyParallelServer::timeout(running);
                pthread_mutex_destroy(&server_side::mutexi);
                exit(2);
            } else {
                perror("other error");
                exit(3);
            }
        }
        //c->handleClient(new_sock);
        struct server_side::MyParams *params2 = new server_side::MyParams();
        params2->sockfd = new_sock;
        params2->c = c;
        pthread_t trid;

        pthread_create(&trid, nullptr, MyParallelServer::handleThread, params2);
        running.push_back(trid);

    }

}

void *MyParallelServer::handleThread(void *arg) {
    struct server_side::MyParams *params = (struct server_side::MyParams *) arg;
    int s = params->sockfd;
    ClientHandler *c = params->c;
    c->handleClient(s);
}

void MyParallelServer::timeout(std::vector<pthread_t> running) {
    for (int i = 0; i < running.size(); i++) {
        pthread_join(running[i], nullptr);
    }


}