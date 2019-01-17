//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_DEPTHFIRSTSEARCH_H
#define EVEN2_DEPTHFIRSTSEARCH_H

#include <set>
#include "Searcher.h"
#include "stack"


template<class T>
class DepthFirstSearch : public Searcher<T> {

public:
    DepthFirstSearch() {}


    std::vector<State<T> *> search(ISearchable<T> *searchable) {
        // this->addToOpenList(searchable.getInitialState());
        this->evaluatedNodes++;
        std::stack<PriorityState<T> *> vertex;
        PriorityState<T> *s = searchable->getInitialState();
        vertex.push((s));
        //std::set<PriorityState<T>* , int> visited;
        PriorityState<T> *gaolso = searchable->getGoalState();
        if (s->getStateOfPriority()->operator==(*(gaolso->getStateOfPriority()))) {
            return this->getBackTrace(s);
        }
        bool fiRun = true;
        while (!vertex.empty()) {
            PriorityState<T> *v = ((vertex.top()));
            this->evaluatedNodes++;
            vertex.pop();
            if (v->getStateOfPriority()->operator==(*(gaolso->getStateOfPriority()))) {
                while (!vertex.empty()) {
                    vertex.pop();
                }
                this->closed.clear();
                return this->getBackTrace(v);
            }

            if (!(this->hasVisited((v->getStateOfPriority())))) {
                fiRun = false;
                this->myInsert(v->getStateOfPriority());
                std::vector<PriorityState<T> *> successors = searchable->getAllPossibleStates(v);
                for (int i = 0; i < successors.size(); i++) {
                    PriorityState<T> *al = successors[i];
                    State<T> *ssd = (al->getStateOfPriority());
                    if (!this->hasVisited(ssd)) {
                        al->setCameFrom((v->getStateOfPriority()));
                        //  PriorityState<T> tema= *successors[i];
                        vertex.push(al);
                        //  successors[i]
                    }



                }
            }
        }
        throw "no way!";
    }

    double getPrioity(State<T> *fatherOrSon) {
        return 0;
    }

};


#endif //EVEN2_DEPTHFIRSTSEARCH_H
