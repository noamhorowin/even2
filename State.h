//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_STATE_H
#define EVEN2_STATE_H

#include <iostream>
#include "Point.h"
template <class  T>
class State {
protected:
    T* state;
   // T stoto;
    double cost;
    State<T>* cameFrom = NULL;
public:
/*    State(T* state){
        this->state = state;
        std::cout<<"No cost"<<std::endl;// TODO remove after debug.

    }*/
    State(T* state, double cost){
        this->state = state;
        this->cost = cost;

    }

    void setCost(double cost){
        this->cost = cost;
    }
    void setCameFrom(State<T>* cameFrom){
        this->cameFrom=cameFrom;
    }
    /**
     *
     * @return the cost of sda
     */
    double getCost(){
        return this->cost;
    }
    State<T>* getCameFrom(){
        return this->cameFrom;
    }


    bool operator==(State<T> &pstate) {
        return (*this->getState()) == (*pstate.getState());
    }

    T* getState() {
        return this->state;
    }


};


#endif //EVEN2_STATE_H
