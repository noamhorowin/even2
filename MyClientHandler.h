//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_MYCLIENTHANDLER_H
#define EVEN2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include <vector>
#include <string>
#include "ICacheManager.h"
using namespace std;

class MyClientHandler : public ClientHandler {
    Solver<vector<string>, string>* solver;
    ICacheManager<std::string, std::string>* cacheManager;

    string getSolution(std::vector<string> matrix, string format);
public:
    MyClientHandler(Solver<vector<string>, string>* solver1, ICacheManager<std::string, std::string>* cacheManager1) {
        this->solver = solver1;
        this->cacheManager = cacheManager1;
    }
    virtual void handleClient(int socketNumber);
};


#endif //EVEN2_MYCLIENTHANDLER_H
