//
// Created by noam on 1/10/19.
//

#ifndef EVEN2_MYPRIORITYQUEUE_H
#define EVEN2_MYPRIORITYQUEUE_H

#include <map>
#include "queue"
#include "State.h"

template<class T>

class MyPriorityQueue {
    struct MyComperator {
        std::pair<State<T>, double> a;

        bool operator<(const MyComperator &val) const {
            return (a.second < val.a.second);
        }
    };

    std::priority_queue<State<T>, std::vector<std::pair<State<T>, double >>,MyComperator> q;
    std::map<State<T>, int> vals;


public:
    MyPriorityQueue() {
    }

    void popSpeseficState(std::pair<State<T> , double> state) {
        std::vector<std::pair<State<T>,double >> temp;
        bool fail = true;
        for (int i = 0; i < q.size(); i++) {
            if (state.first == q.top().first) {
                q.pop();
                break;
            }
            temp[i] = q.top();
            q.pop();
        }
        for (int j = 0; j < temp.size(); j++) {
            fail = false;
            q.pop(temp[j]);
        }
        if (fail) {
            std::cout << "wrong!!!!" << std::endl; // TODO del befor sub.
        }
        vals.erase(state);
    }
   std::pair<State<T>, double> findSpeseficState(std::pair<State<T>, double> state) {
        std::vector<std::pair<State<T>,double> > temp;
        bool fail = true;
       std::pair< State<T>,double> ret;
        for (int i = 0; i < q.size(); i++) {
            if (state.first == q.top().first) {
                ret = q.top();
                break;
            }
            temp[i] = q.top();
            q.pop();
        }
        for (int j = 0; j < temp.size(); j++) {
            fail = false;
            q.pop(temp[j]);
        }
        if (fail) {
            std::cout << "wrong!!!!" << std::endl; // TODO del befor sub.
        }
        return ret;
    }


    int size() {
        return this->q.size();
    }

    void push(std::pair<State<T>, double> s) {
        this->q.push(s);
        this->vals[s] = 1;
    }

    bool contains(std::pair<State<T>,
    double> s) {
        return vals.count(s.first) == 1;
    }

    void pop() {
       std::pair<State<T>,double >s = this->top();
        this->vals.erase(s.first);
        q.pop();
    }

    std::pair< State<T>,double> top() {
        return q.top();
    }
};


#endif //EVEN2_MYPRIORITYQUEUE_H
