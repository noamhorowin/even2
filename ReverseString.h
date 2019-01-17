//
// Created by noam on 1/11/19.
//

#ifndef EVEN2_REVERSESTRING_H
#define EVEN2_REVERSESTRING_H

#include "Solver.h"

#include <string>
#include <iostream>

class ReverseString : public Solver<std::string, std::string> {

    bool ok;
public:
    ReverseString(){
        ok = true;
    }

    std::string activeReverser(std::string s) {
        std::string revS;
        for (int i = s.size() -1 ; i >= 0; i--) {
            revS += s[i];
        }
        return revS;
    }
    std::string activeReverser(std::string s, bool booli) {
        std::string revS;
        for (int i = s.size() -1 ; i >= 0; i--) {
            if(s[i] != '\n'){
            revS += s[i];
        }
        }
        return revS;
    }
    virtual std::string solve(std::string problem) {
        return this->activeReverser(problem);
    }
};


#endif //EVEN2_REVERSESTRING_H
