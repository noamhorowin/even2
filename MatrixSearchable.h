//
// Created by noam on 1/12/19.
//

#ifndef EVEN2_SEARCHABLE_H
#define EVEN2_SEARCHABLE_H


#include "ISearchable.h"

template<class T>
class MatrixSearchable : public ISearchable<T> {

private:
// goal
// start
// size
//
public:
    MatrixSearchable(int row, int col, State<T> start, State<T> goal, std::vector);// TODO write this func

    State<T> getInitialState() {};// TODO write this func

    State<T> getGoalState() {};// TODO write this func

    std::vector<State<T>> getAllPossibleStates(State<T> s) { // TODO matrix get Up right left down points
        std::vector<State<T>> listOfStates = NULL; // add up down right left
        typename std::vector<State<T>>::iterator it = listOfStates.begin();
        while(*it != listOfStates.end()){
            (*it).setCameFrom(s);
        }//
        return listOfStates;
    }
};


#endif //EVEN2_SEARCHABLE_H
