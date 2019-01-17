//
// Created by noam on 1/14/19.
//

#ifndef EVEN2_PRIORITYSTATE_H
#define EVEN2_PRIORITYSTATE_H

#include "State.h"

template<class T>
class PriorityState {
    State<T> *state;
//<T> sda;
    double prioity;
public:
    PriorityState(State<T> *t, double priotiy){
        this->state = t;
        this->prioity = priotiy;
    }
    PriorityState(T *t, double cost ,double priotiy){
        this->state = (new State<T>(t,cost));
        this->prioity = priotiy;
    }



    State<T>* getStateOfPriority() {
        return this->state;
    }


    double getPriotiy() {
        return prioity;
    }

    void setCost(double cost) {
        this->getStateOfPriority()->getCost();
    }

    void setCameFrom(State<T >* cameFrom) {
        this->state->setCameFrom(cameFrom);
    }

    void setPrioity(double p) {
        this->prioity = p;
    }

    bool operator == (const PriorityState<T> &pstate)const {
        return (*this->getStateOfPriority()->getState() == (*pstate.getStateOfPriority().getState()));
    }


    bool operator()(PriorityState <T> *ptr) {
        return (*ptr->getStateOfPriority() == *this->getStateOfPriority());
    }
};


#endif //EVEN2_PRIORITYSTATE_H
