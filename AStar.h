//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_ASTAR_H
#define EVEN2_ASTAR_H

#include "Searcher.h"

template<class T>
class AStar : public Searcher<T> {
private:
    double goalX;//member
    double goalY;//member

public:

    IHeuristic<T> *heuristic;// member

    AStar(IHeuristic<T> *h) {
        this->heuristic = h;
    }

    void setGoalX(double x) {
        this->goalX = x;
    }

    void setGoalY(double y) {
        this->goalY = y;
    }

    void setGoal(double x, double y) {
        setGoalX(x);
        setGoalY(y);
    }

    virtual double getPrioity(State<T> *fatherOrSon) {
        if(fatherOrSon->getCameFrom() == NULL){
            return( (this->heuristic->distanceFromGoal(fatherOrSon)) + fatherOrSon->getCost());
        }
        return (heuristic->distanceFromGoal(fatherOrSon) +
               this->getPrioity(fatherOrSon->getCameFrom()) + fatherOrSon->getCost());

    }

};


#endif //EVEN2_ASTAR_H
