//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_SEARCHER_H
#define EVEN2_SEARCHER_H


#include <algorithm>
#include <set>
#include "ISearcher.h"
#include "MyPriorityQueue.h"
#include "HeuristicPointFunc.h"
#include "MyComparator.h"

template<class T>
class Searcher : public ISearcher<T> {

protected:
    MyPriorityQueue<T> *openList;
    std::set<State<T> *> closed;
    int evaluatedNodes;
    IHeuristic<State<T> *> *heFunc;

public:
    void myInsert(State<T> *state) {
        closed.insert(state);
    }

    bool hasVisited(State<T> *state) {
        return closed.end() != std::find_if(closed.begin(), closed.end(), MyStateComperator<T>(state));
    }

    Searcher() {
        openList = new(MyPriorityQueue<T> );
        // this->closed = new ( std::set<State<T> *> );
        this->evaluatedNodes = 0;
    }


    Searcher(IHeuristic<T> *heFunci) {
        this->heFunc = heFunci;
        this->evaluatedNodes = 0;

    }

    int OpenListSize() {
        return this->openList->size();
    }

    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    virtual double getPrioity(State<T> *fatherOrSon) = 0;

    virtual std::vector<State<T> *> search(ISearchable<T> *searchable) {
        this->addToOpenList(searchable->getInitialState());
        while (this->OpenListSize() > 0) {
            PriorityState<T> *s = this->popOpenList();// TODO pair
            closed.insert(s->getStateOfPriority());
            if (*s->getStateOfPriority() == *searchable->getGoalState()->getStateOfPriority()) {
                return this->getBackTrace(s);
            }
            std::vector<PriorityState<T> *> successors = searchable->getAllPossibleStates(
                    s);//->getAllPossibleStates(); //TODO pair
            typename std::vector<PriorityState<T> *>::iterator it = successors.begin(); // TODO pair
            while (it != successors.end()) {
                if ((!hasVisited((*it)->getStateOfPriority()))
                    &&
                    !(this->openList->contains((*it)->getStateOfPriority()))) { // list dosent contains the son.
                    (*it)->setCameFrom(s->getStateOfPriority());
                    if ((*it)->getStateOfPriority()->getCost() != -1) { // can step on it
                        double prioity =
                                (*it)->getStateOfPriority()->getCost() + this->getPrioity(s->getStateOfPriority());
                        (*it)->setPrioity(prioity);
                        (*it)->getStateOfPriority()->setCameFrom(s->getStateOfPriority());
                        this->openList->push((*it));
                    }
                    //else cant reach to it.

                } else { //check if update of the list is require
                    double sPrioity = s->getPriotiy();
                    if (this->openList->contains((*it)->getStateOfPriority())) {
                        double sonPrioity = this->openList->findSpeseficState((*it))->getPriotiy();

                        if (sPrioity >= 0) {
                            if (sPrioity + (*it)->getStateOfPriority()->getCost() < sonPrioity) { // need to update.
                                if (this->openList->contains((*it)->getStateOfPriority())) { // check if in open
                                    this->openList->popSpeseficState((*it));
                                } else {// in close
                                    closed;// todo add delte method.
                                }
                                double newPrioity =
                                        sPrioity +
                                        (*it)->getStateOfPriority()->getCost(); // s.getCameFromCost isnt change since it cretion.
                                //(*it).setCameFrom(s); allready done.
                                (*it)->setPrioity(newPrioity);
                                this->openList->push((*it));// TODO
                            } //else dont change a thing
                        }
                    }
                }
                ++it;

            }
        }
        std::cout << "best and stars like to " << std::endl;
        throw "rocks";

    }


    std::vector<State<T> *> getBackTrace(PriorityState<T>
                                         *s) {

        State<T> *temp = s->getStateOfPriority();
        std::vector<State<T> *> road;
        if (s == NULL) {
            std::cout << "hi" <<
                      std::endl;
        } else {
            if (s->getStateOfPriority()->getCameFrom() != NULL) {
//road[0] = s;
                int i = 0;
                while (temp != NULL) {
                    road.push_back(temp);
                    temp = temp->getCameFrom();
                    std::cout << i << std::endl;
                    ++i;
                }
            }
        }
        std::cout << "finish" << std::endl;
        return road;
    }

    PriorityState<T> *popOpenList() {
        evaluatedNodes++;
        PriorityState<T> *s = this->openList->top();
        this->openList->pop();
        return s;
    }

    void addToOpenList(PriorityState<T> *s) {
        this->openList->push(s);
    }

};


#endif //EVEN2_SEARCHER_H
