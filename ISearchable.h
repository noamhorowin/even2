//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_ISEARCHABLE_H
#define EVEN2_ISEARCHABLE_H

#include "PriorityState.h"
//#include "State.h"
#include "vector"
template <class T>
class ISearchable {
private:
public:
    virtual PriorityState<T>* getInitialState()=0;
    virtual PriorityState<T>* getGoalState()=0;
    virtual std::vector<PriorityState<T>*> getAllPossibleStates(PriorityState<T>* s)=0;

};


#endif //EVEN2_ISEARCHABLE_H
