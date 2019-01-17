//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_BREADTHFIRSTSEARCH_H
#define EVEN2_BREADTHFIRSTSEARCH_H

#include "Searcher.h"

template<class T>
class BreadthFirstSearch : public Searcher<T> {
public:
    BreadthFirstSearch() {}

    std::vector<State<T> *> search(ISearchable<T> *searchable) {
        this->addToOpenList(searchable->getInitialState());
        bool firstRun;
        while (this->openList->size() > 0) {
            PriorityState<T> *s = this->popOpenList();
            if (firstRun) {
                s->setPrioity(this->getPrioity(s->getStateOfPriority()));
            }
            this->closed.insert(s->getStateOfPriority());
            if (*s->getStateOfPriority() == *searchable->getGoalState()->getStateOfPriority()) {
                return this->getBackTrace(s);
            }
            std::vector<PriorityState<T> *> successors = searchable->getAllPossibleStates(s);
            for (int i = 0; i < successors.size(); i++) {
                if (*s->getStateOfPriority() == *searchable->getGoalState()->getStateOfPriority()) {
                    return this->getBackTrace(s);
                }
                PriorityState<T> * tem = successors[i];
                if (!(this->hasVisited(tem->getStateOfPriority()))) { //
                    // need to add to the q.
                    this->closed.insert(s->getStateOfPriority());
                    PriorityState<Point> *tempos = successors[i];
                    tempos->setCameFrom(s->getStateOfPriority());
                    tempos->setPrioity(s->getPriotiy() + 1);
                    this->openList->push(tempos);
                }
            }
        }
        std::cout << "bfs you r under arrest  " << std::endl;
        throw "the gun";
    }

    double getPrioity(State<T> *fatherOrSon) {
        return 1;
    }

};


#endif //EVEN2_BREADTHFIRSTSEARCH_H
