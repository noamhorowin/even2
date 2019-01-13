//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_HEURISTICFUNC_H
#define EVEN2_HEURISTICFUNC_H

#include "IHeuristic.h"
#include "Point.h"

//template <class T>
class HeuristicPointFunc : public IHeuristic<Point> {

    State<Point> goal;
HeuristicPointFunc(State<Point> goal) : goal(goal){
}
    virtual double distanceFromGoal(State<Point> s) {
        double temp = goal.getState().getX() - s.getState().getX() +
                (goal.getState().getY() - s.getState().getY());
        return temp;
    }
};


#endif //EVEN2_HEURISTICFUNC_H
