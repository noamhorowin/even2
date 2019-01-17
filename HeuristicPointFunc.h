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
    State<Point> *goal;

    HeuristicPointFunc(State<Point> *goal) {
        this->goal = goal;

    };

    virtual double distanceFromGoal(State<Point> *s) { //TODO can cause problems, fix it before am test
        double temp = fabs(goal->getState()->getX() - s->getState()->getX()) +
                      fabs(((goal->getState()->getY() - s->getState()->getY())));
        return temp;
    }
};


#endif //EVEN2_HEURISTICFUNC_H
