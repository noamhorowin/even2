//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_MYPRIORITYQUEUE_H
#define EVEN2_MYPRIORITYQUEUE_H

#include <map>
#include <queue>
#include <set>
#include <algorithm>
//#include "State.h"
#include "PriorityState.h"
#include "MyComparator.h"

template<class T>

class MyPriorityQueue :MyComperator<T> {

    std::priority_queue<PriorityState<T> *, std::vector<PriorityState<T>*>,MyComperator<T>> q;
    std::set<State<T> *> valSet;
    //MyComperator<State<T>> as;

public:
    MyPriorityQueue() {

    };

    void popSpeseficState(PriorityState<T> *pState) {
        std::vector<PriorityState<T> *> temp;
        bool fail = true;
        PriorityState<T> *tempos;
int size =  q.size() ;
        for (int i = 0; i < size ; i++) {
            PriorityState<Point> * xoxo = q.top();
            tempos = new PriorityState<Point>(xoxo->getStateOfPriority(),xoxo->getPriotiy());

            if ((pState->getStateOfPriority()->operator==(*(tempos->getStateOfPriority())))){
                //  temp[i] = q.top();
                //   std::cout<<q.top()->getPriotiy()<<std::endl;
                q.pop();
                break;
            }
            temp.push_back(tempos);
            q.pop();
        }
        for (int j = 0; j < temp.size(); j++) {
            fail = false;
            q.push(temp[j]);
        }
        if (fail) {
          //  std::cout << "wrong!!!!" << std::endl;
        }
        valSet.erase(pState->getStateOfPriority());
    }

    PriorityState<T> * findSpeseficState(PriorityState<T> *pState) {
        if (this->contains(pState->getStateOfPriority())) {
            std::vector<PriorityState<T> *> temp;
            bool fail = true;
           // PriorityState<T> ret;
            PriorityState<T> *tempos;
            int size = q.size();

            for (int i = 0; i < size; i++) {

                PriorityState<Point> * xoxo = q.top();
                tempos = new PriorityState<Point>(xoxo->getStateOfPriority(),xoxo->getPriotiy());

                if ((pState->getStateOfPriority()->operator==(*(tempos->getStateOfPriority())))){
                   // ret = *tempos;

                    break;
                }
                temp.push_back(tempos);
                q.pop();
            }
            for (int j = 0; j < temp.size(); j++) {
                fail = false;
                q.push(temp[j]);
            }
            if (fail) {
            }
            return tempos;
        }
        throw "failed";

    }


    int size() {
        return this->q.size();
    }

    void push(PriorityState<T> *pState) {
        this->q.push(pState);
        this->valSet.insert(pState->getStateOfPriority());
    }

    bool contains(State<T> *state) {
        return (valSet.end() != std::find_if(valSet.begin(), valSet.end(), MyStateComperator<T>(state)));
    }

    void pop() {
        PriorityState<T>* s = (this->top());
        this->valSet.erase(s->getStateOfPriority());
        q.pop();
    }

    PriorityState<T> * top() {
        return q.top();
    }

    void clearQ(){
        this->valSet.clear();
        while (!this->q.empty())
        {
            q.pop();
        }
    }
};


#endif //EVEN2_MYPRIORITYQUEUE_H
