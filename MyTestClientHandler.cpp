//
// Created by noam on 1/17/19.
//

#include "MyTestClientHandler.h"
#include "ServerSide.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>
#include <strings.h>
#include <cstring>
#include "ReverseString.h"

void MyTestClinetHandler::handleClient(int newsockfd) {

    char buffer[256];
    int n;
    std::string clientMessage;
    bzero(buffer,256);
    n = read( newsockfd,buffer,255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    clientMessage=buffer;
  //  ReverseString rs;
    while(clientMessage != "end") {
        std::string reversed = solver->solve(clientMessage);//rs.activeReverser(clientMessage);

        const char* serverMessage = reversed.c_str();
        const void* mes = serverMessage;
           //n = write(newsockfd,serverMessage,strlen(serverMessage));
           n = send(newsockfd,serverMessage,strlen(serverMessage), 0);
           memset(buffer,0,strlen(buffer));
           n = read( newsockfd,buffer,255 );
        clientMessage=buffer;

    }

}