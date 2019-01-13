//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_BREADTHFIRSTSEARCH_H
#define EVEN2_BREADTHFIRSTSEARCH_H

#include "Searcher.h"

template <class T>
class BreadthFirstSearch : public Searcher<T> {

    double getPrioity(State<T> father) {
        return -1;
    }
};


#endif //EVEN2_BREADTHFIRSTSEARCH_H
