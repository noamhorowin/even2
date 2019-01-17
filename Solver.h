//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_SOLVER_H
#define EVEN2_SOLVER_H

template <class P, class S>
class Solver {
public:
    virtual S solve(P problem)=0;

};


#endif //EVEN2_SOLVER_H
