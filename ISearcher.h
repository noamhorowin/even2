//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_ISEARCHER_H
#define EVEN2_ISEARCHER_H

#include <vector>
#include "ISearchable.h"
#include "State.h"
template <class T>

class ISearcher {
public:
    // the search method
    virtual std::vector<State<T>*> search (ISearchable<T>* searchable)=0;
// get how many nodes were evaluated by the algorithm
    virtual int getNumberOfNodesEvaluated()=0;

};


#endif //EVEN2_ISEARCHER_H
