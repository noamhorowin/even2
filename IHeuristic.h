//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_IHEURISTIC_H
#define EVEN2_IHEURISTIC_H

#include "State.h"

template <class T>
class IHeuristic {
public:
    IHeuristic(){

    }

protected:
    State<T> goal;

    virtual double distanceFromGoal(State<T> s) = 0;

};


#endif //EVEN2_IHEURISTIC_H
