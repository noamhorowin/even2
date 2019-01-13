//
// Created by noam on 1/13/19.
//

#ifndef EVEN2_DEPTHFIRSTSEARCH_H
#define EVEN2_DEPTHFIRSTSEARCH_H

#include "Searcher.h"
#include "stack"

template<class T>
class DepthFirstSearch : public Searcher<T> {

    double getPrioity(State<T> father) {
        return 0;
    }

    virtual std::vector<State<T>> search(ISearchable<T> searchable) {
        // this->addToOpenList(searchable.getInitialState());
        std::stack<State<T>> vertex;
        vertex.push(searchable.getInitialState());
        std::map<State<T>, int> visited;
        State<T> s;
        if (s == searchable.getGoalState()) {
            return this->getBackTrace(s);
        }//TODO stop con.
        while (!vertex.empty()) {
            State<T> v = vertex.top();
            vertex.pop();
            //Todo check for goal.
            if (visited.count(v) == 0) {
                visited[v] = 1;
                std::vector<State<T>> successors = searchable.getAllPossibleStates(v);
                for (int i = 0; i < successors.size(); i++) {
                    vertex.push(successors[i]);
                }
            }
        }
        std::cout << "failed in dfs" << std::endl;
        return nullptr;
    }


};


#endif //EVEN2_DEPTHFIRSTSEARCH_H
