//
// Created by noam on 1/12/19.
//

#ifndef EVEN2_MYCOMPARATOR_H
#define EVEN2_MYCOMPARATOR_H


#include "PriorityState.h"

template<typename T>
class MyComperator {
public:


    bool operator()(PriorityState<T> *left, PriorityState<T> *right) {
        return (left->getPriotiy() > right->getPriotiy());
    }

    /*   bool binaryopertor < (const PriorityState<T> *left,const PriorityState<T> right){

       }*/

};

template<typename T>
class MyStateComperator {
public:
    State<T> *search;
    explicit MyStateComperator(State<T>* search) :
            search(search) {}

    bool operator()(State <T> *ptr) {
        return (*ptr == *search);
    }

};



#endif //EVEN2_MYCOMPARATOR_H
