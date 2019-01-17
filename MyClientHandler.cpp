//
// Created by noam on 1/17/19.
//

#include <iostream>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include "MyClientHandler.h"
#include "DataAnalysis.h"
#include "ServerSide.h"

void MyClientHandler::handleClient(int socketNumber) {
    char buffer[256];
    int n;
    vector<string> clientProblem;
    std::string clientMessage;
    bzero(buffer,256);
    n = read( socketNumber,buffer,255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    const char* serverMessage = "message accepted";
    int serverMessageLength = strlen(serverMessage);
    clientMessage=buffer;
    while(clientMessage != "end") {
        clientProblem.push_back(clientMessage);
        const void* mes = serverMessage;
        n = send(socketNumber,serverMessage,serverMessageLength, 0);
        memset(buffer,0,strlen(buffer));
        n = read( socketNumber,buffer,255 );
        clientMessage=buffer;
    }
    DataAnalysis dA;
    string format = dA.matrixSavedFormat(clientProblem);
    string solution = this->getSolution(clientProblem, format);


    //string solution1 = this->solver->solve(clientProblem);
    const char* finalSolution = solution.c_str();
    n = send(socketNumber,finalSolution,strlen(finalSolution), 0);

}

string MyClientHandler::getSolution(std::vector<string> matrix, string format) {

    string solution;
    pthread_mutex_lock(&server_side::mutexi);
    if(this->cacheManager->contains(format)) {
        solution= this->cacheManager->getSolution(format);

    }
     else {
        solution = this->solver->solve(matrix);
        this->cacheManager->saveSolution(format, solution);
    }
    pthread_mutex_unlock(&server_side::mutexi);
    return solution;

}