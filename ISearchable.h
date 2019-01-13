//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_ISEARCHABLE_H
#define EVEN2_ISEARCHABLE_H

#include "State.h"
#include "vector"
template <class T>
class ISearchable {
private:
public:
    virtual State<T> getInitialState()=0;
    virtual State<T> getGoalState()=0;
    virtual std::vector<State<T>> getAllPossibleStates(State<T> s)=0;

};


#endif //EVEN2_ISEARCHABLE_H
