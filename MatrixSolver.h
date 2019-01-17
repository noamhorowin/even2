//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_MATRIXSOLVER_H
#define EVEN2_MATRIXSOLVER_H

#include "SolverSearcher.h"
#include <string>
#include <vector>
#include "Point.h"
#include "State.h"
#include "PriorityState.h"
#include "DataAnalysis.h"

using namespace std;

class MatrixSolver : public SolverSearcher<vector<string>, string, Point> {
    vector<string> problem;
    vector<vector<string>> toStringMatrix(vector<string> lines, int numRows);
public:
    MatrixSolver(ISearcher<Point> *searcher1, vector<string> problem) {
        this->problem = problem;
        this->searcher = searcher1;
    }
    virtual string solve(vector<string> problem) {
        DataAnalysis dA;
        ISearchable<Point>* searchable = this->getSearchable(problem);
        return dA.fromTraceBackToString(this->searcher->search(searchable));
    }
    ISearchable<Point>* getSearchable(vector<string> lines);


};


#endif //EVEN2_MATRIXSOLVER_H
