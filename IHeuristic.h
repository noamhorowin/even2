//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_IHEURISTIC_H
#define EVEN2_IHEURISTIC_H

#include "PriorityState.h"

template <class T>
class IHeuristic {
protected:
   State<T> *goal;

public:
    IHeuristic(){
        //this->goal = s;
    }

public:
    virtual double distanceFromGoal(State<T> * s) = 0;

virtual void setGoal(State<T> * goli) = 0;
};


#endif //EVEN2_IHEURISTIC_H
