//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_SOLVERSEARCHER_H
#define EVEN2_SOLVERSEARCHER_H

#include "Solver.h"
#include "ISearcher.h"
template <class P, class S, class T>
class SolverSearcher : public Solver<P,S> {
protected:
    ISearcher<T> * searcher;
public:
    SolverSearcher(){}
    virtual S solve(P problem)=0;


};


#endif //EVEN2_SOLVERSEARCHER_H
