//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_HEURISTICFUNC_H
#define EVEN2_HEURISTICFUNC_H

#include "IHeuristic.h"
#include "Point.h"
#include "PriorityState.h"
#include <cmath>

//template <class T>
class HeuristicPointFunc : public IHeuristic<Point> {
public:

    HeuristicPointFunc(State<Point> *goali) {
        this->goal = goali;

    };

    virtual double distanceFromGoal(State<Point> *s) {
        double temp = fabs(goal->getState()->getX() - s->getState()->getX()) +
                      fabs(((goal->getState()->getY() - s->getState()->getY())));
        return temp;
    }

    void setGoal(State<Point> * goli){
        this->goal = goli;
    }
};


#endif //EVEN2_HEURISTICFUNC_H
