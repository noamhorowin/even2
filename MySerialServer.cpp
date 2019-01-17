//
// Created by noam on 1/17/19.
//

#include "MySerialServer.h"
#include "ClientHandler.h"

/*struct MyParams
{
    int sockfd;
    ClientHandler* c;
};*/

void* MySerialServer::thread_func(void *arg) {
    struct server_side::MyParams* params = (struct server_side::MyParams*) arg;
    int s = params->sockfd;
    ClientHandler* c = params->c;
    int new_sock;
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    /*timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));*/
    new_sock = accept(s, (struct sockaddr*)&client, &clilen);
    if (new_sock < 0)	{
        if (errno == EWOULDBLOCK)	{
            cout << "timeout!" << endl;
            exit(2);
        }	else	{
            perror("other error");
            exit(3);
        }
    }
    c->handleClient(new_sock);

    while(true) {
        listen(s, 5);
        struct sockaddr_in client;
        socklen_t clilen = sizeof(client);

        timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        new_sock = accept(s, (struct sockaddr*)&client, &clilen);
        if (new_sock < 0)	{
            if (errno == EWOULDBLOCK)	{
                cout << "timeout!" << endl;//
                exit(2);
            }	else	{
                perror("other error");
                exit(3);
            }
        }
        c->handleClient(new_sock);

    }

}
int MySerialServer::open(int portNumber, ClientHandler* c) {
    int port = portNumber;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *)&serv, sizeof(serv)) < 0)	{
        cerr << "Bad!" << endl;
    }
    struct server_side::MyParams* params = new server_side::MyParams();
    params->sockfd = s;
    params->c = c;
    pthread_t trid;
    pthread_create(&trid, nullptr, MySerialServer::thread_func, params);


}

