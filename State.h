//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_STATE_H
#define EVEN2_STATE_H

#include <iostream>

template <class  T>
class State {
    T state;
    double cost;
    State<T>* cameFrom;
public:
    State(T state){
        this->state = state;
        std::cout<<"No cost"<<std::endl;// TODO remove after debug.

    }
    State(T state, double cost){
        this->state = state;
        this->cost = cost;

    }
    void setCost(double cost){
        this->cost = cost;
    }
    void setCameFrom(State<T> cameFrom){
        this->cameFrom=cameFrom;
    }
    double getCost(){
        return this->cost;
    }
    State<T> getCameFrom(){
        return this->cameFrom;
    }
     bool operator==(const State<T>& state1) const{
         return state == state1.state;
    }
    T getState() {
        return this->state;
    }


};


#endif //EVEN2_STATE_H
