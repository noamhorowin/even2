//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_SEARCHER_H
#define EVEN2_SEARCHER_H


#include "ISearcher.h"
#include "MyPriorityQueue.h"
#include "HeuristicPointFunc.h"

template<class T>
class Searcher : public ISearcher<T> {

protected:
    MyPriorityQueue<State<T>> openList;

    int evaluatedNodes;
    HeuristicPointFunc<T> heFunc

public:
    Searcher() {
        this->evaluatedNodes = 0;
    }

    Searcher(HeuristicPointFunc<T> heFunc) {
        this->heFunc = heFunc;
        this->evaluatedNodes = 0;

    }

    int OpenListSize() {
        return this->openList.size();
    }

    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    virtual double getPrioity(State<T> fatherOrSon) = 0;

    virtual std::vector<State<T>> search(ISearchable<T> searchable) {
        this->addToOpenList(searchable.getInitialState());
        std::map<std::pair<State<T>, double>, int> closed;
        while (this->OpenListSize() > 0) {
            std::pair<State<T>, double> s = this->popOpenList();
            closed[s] = 1;
            if (s.first == searchable.getGoalState()) {
                return this->getBackTrace(s.first); //TODO add back TRACE method
            }
            std::vector<State<T>> successors = searchable.getAllPossibleStates();
            typename std::vector<State<T>>::iterator it = successors.begin();
            while (it != successors.end()) {
                if ((closed.count(*it) == 0) && (!this->openList.contains(*it))) { // list dosent contains the son.
                    // s.setCameFrom(n); //TODO already done by getSuccessors

                    if (this->getPrioity(s) == -1) { // for algos that dosent care about cost
                        this->openList.push(*it, this->getPrioity(s));
                    } else if (it.getCost() != -1) { // for algos that take care about the cost
                        double prioity = (*it).getCost() + this->getPrioity(s);
                        this->openList.push(std::pair<State<T>, double>(*it, prioity));
                    }
                    //else cant reach to it.

                } else { //check if update of the list is require
                    double sPrioity = this->getPrioity(s);
                    double sonPrioity = this->openList.findSpeseficState(*it).second;
                    if (sPrioity >= 0) {
                        if (sPrioity + (*it).getCost() < sonPrioity) { // need to update.
                            if (this->openList.contains(*it)) { // check if in open
                                this->openList->popSpeseficState(*it);
                            } else {// in close
                                closed.erase(*it);
                            }
                            double newPrioity =
                                    sPrioity + (*it).getCost(); // s.getCameFromCost isnt change since it cretion.
                            //(*it).setCameFrom(s); allready done.
                            this->openList.push(std::pair<State<T>, double>(*it, newPrioity));
                            // TODO update close
                        } //else dont change a thing
                    }
                }

            }

        }
        return nullptr;


    }

    std::vector<State<T>> getBackTrace(State<T> s) {
        std::vector<State<T>> road;
        road[0] = s;
        int i = 1;
        State<T> temp = s;
        while (temp != NULL) {
            road[i] = temp.getCameFrom();
            temp = temp.getCameFrom();
            ++i;
        }
        return road;
    }

    State<T> popOpenList() {
        evaluatedNodes++;
        State<T> s = this->openList.top();
        this->openList.pop();
        return s;
    }

    void addToOpenList(std::pair<State<T>, double> s) {
        this->openList.push(s);
    }

};


#endif //EVEN2_SEARCHER_H
