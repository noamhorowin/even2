//
// Created by noam on 1/17/19.
//

#include "MatrixSolver.h"
#include "MatrixSearchable.h"
ISearchable<Point>* MatrixSolver::getSearchable(vector<string> lines) {

    vector<string> matrix = lines;
    int numberOfLines = lines.size();
    string start = lines[numberOfLines - 2];
    string goal = lines[numberOfLines - 1];
    vector<vector<string>> graph = this->toStringMatrix(lines, numberOfLines - 2);
    int row = graph.size();
    int col = graph[0].size();
    string startX="";
    string startY="";
    int pos = start.find(",");
    for(int i = 0; i<start.size(); i++) {
        if(i<pos) {
            startX+=start[i];
        }
        else if(i>pos) {
            startY+=start[i];
        }
    }
    string goalX="";
    string goalY="";
    int pos1 = goal.find(",");
    for(int i = 0; i<goal.size(); i++) {
        if(i<pos1) {
            goalX+=goal[i];
        }
        else if(i>pos1) {
            goalY+=goal[i];
        }
    }

    Point* startP = new Point(stod(startX),stod(startY));
    Point* goalP = new Point(stod(goalX),stod(goalY));

    return new MatrixSearchable(row, col, startP, goalP, graph);
}

vector<vector<string>> MatrixSolver::toStringMatrix(vector<string> lines, int numRows) {
    vector<vector<string>> matrix;
    DataAnalysis dA;
    for(int i = 0; i<numRows; i++) {
        vector<string> lineAsVector = dA.makeStringRow(lines[i]);
        matrix.push_back(lineAsVector);
    }
    return matrix;



}