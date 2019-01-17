//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_BESTFIRSTSEARCH_H
#define EVEN2_BESTFIRSTSEARCH_H

#include "vector"
#include "Searcher.h"

template<class T>
class BestFirstSearch : public Searcher<T> {
public:
    BestFirstSearch() : Searcher<T>() {
    }


    double getPrioity(State<T>* fatherOrSon) {
        if(fatherOrSon->getCameFrom() == NULL){
            return fatherOrSon->getCost();
        }
        double priority = this->getPrioity(fatherOrSon->getCameFrom()) + fatherOrSon->getCost(); // priority isnt taken in sreach.
        return priority;
    }
};


#endif //EVEN2_BESTFIRSTSEARCH_H
