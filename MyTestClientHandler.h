//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_MYTESTCLIENTHANDLER_H
#define EVEN2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include <string>

class MyTestClinetHandler : public ClientHandler {
    Solver<std::string, std::string>* solver;
public:
    MyTestClinetHandler(Solver<std::string, std::string>* solver1){
        this->solver = solver1;
    }
    virtual void handleClient(int socketNumber);
};



#endif //EVEN2_MYTESTCLIENTHANDLER_H
