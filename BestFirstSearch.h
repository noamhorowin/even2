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

    /*virtual std::vector<State<T>> search(ISearchable<T> searchable) {
        this->addToOpenList(searchable.getInitialState());
        std::map<std::pair<State<T>, double>, int> closed;
        while (this->OpenListSize() > 0) {
            std::pair<State<T>, double> s = this->popOpenList();
            closed[s] = 1;
            if (s.first == searchable.getGoalState()) {
                std::vector<State<T>> road;
                road[0] = s.first;
                int i = 1;
                State<T> temp = s.first;
                while (temp != NULL) {
                    road[i] = temp.getCameFrom();
                    temp = temp.getCameFrom();
                    ++i;
                }
                return road; //TODO add back TRACE method
            }
            std::vector<State<T>> successors = searchable.getAllPossibleStates();
            typename std::vector<State<T>>::iterator it = successors.begin();
            while (it != successors.end()) {
                if ((closed.count(*it) == 0) && (!this->openList.contains(*it))) { // list dosent contains the son.
                    // s.setCameFrom(n); //TODO already done by getSuccessors

                    if (this->getPrioity(s) < 0) { // bfs and dfs
                        this->openList.push(*it, this->getPrioity(s));
                    } else if (it.getCost() != -1) {
                        double prioity = (*it).getCost() + this->getPrioity(s);
                        this->openList.push(*it, prioity);
                    }
                    //else cant reach to it.

                } else { //check if update of the list is require
                    double sPrioity = this->getPrioity(s);
                    if(s >=0){
                    if (sPrioity < this->getPrioity((*it).getCameFrom())) { // need to update.
                        this->openList->popSpeseficState(*it);
                        double newPrioity =
                                sPrioity + (*it).getCost(); // s.getCameFromCost isnt change since it cretion.
                     //   (*it).setCameFrom(s);
                        this->openList.push((*it), newPrioity);
                    } //else dont change a thing
                }
                }
            }

        }

        return nullptr;
    }*/

    double getPrioity(State<T> fatherOrSon) {
        double priority = this->openList.findSpeseficState(std::pair<State<T>,double >(fatherOrSon,0)).second; // priority isnt taken in sreach.
        return priority;
    }
};


#endif //EVEN2_BESTFIRSTSEARCH_H
