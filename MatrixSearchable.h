//
// Created by noam on 1/12/19.
//

#ifndef EVEN2_SEARCHABLE_H
#define EVEN2_SEARCHABLE_H


#include "ISearchable.h"
#include "Point.h"
#include "PriorityState.h"


//template<class Point>
class MatrixSearchable : public ISearchable<Point> {

private:
    Point *goal;
    Point *start;
    int row;
    int col;
    std::vector<std::vector<PriorityState<Point> *>> matrixPoints;

public:
    MatrixSearchable(int row, int col, Point *start, Point *goal,
                     std::vector<std::vector<std::string>> stringMatrix) {
        this->row = row;
        this->col = col;
        this->start = start;
        this->goal = goal;
        buildMatrixFromString(stringMatrix);

    }

    PriorityState<Point> *getInitialState() {
        return this->matrixPoints[this->start->getX()][this->start->getY()];
    };

    PriorityState<Point> *getGoalState() {
        return (new PriorityState<Point>(goal, 1, 10)); // TODO point start from 0 0 to max - 1, max - 1
    };

    std::vector<PriorityState<Point> *>
    getAllPossibleStates(PriorityState<Point> *s) {
        std::vector<PriorityState<Point> *> listOfStates; // add up down right left
        if (s->getStateOfPriority()->getState()->getX() - 1 >= 0) {
            listOfStates.push_back((new PriorityState<Point>(*matrixPoints[s->getStateOfPriority()->getState()->getX() -
                                                                           1][s->getStateOfPriority()->getState()->getY()])));
        }
        if (s->getStateOfPriority()->getState()->getY() - 1 >= 0) {
            listOfStates.push_back((new PriorityState<Point>(*matrixPoints[s->getStateOfPriority()->getState()->getX()][
                    s->getStateOfPriority()->getState()->getY() - 1])));
        }
        if (s->getStateOfPriority()->getState()->getX() + 1 < row) {
            listOfStates.push_back((new PriorityState<Point>(*matrixPoints[s->getStateOfPriority()->getState()->getX() +
                                                                           1][s->getStateOfPriority()->getState()->getY()])));
        }
        if (s->getStateOfPriority()->getState()->getY() + 1 < col) {
            listOfStates.push_back(new PriorityState<Point>(*matrixPoints[s->getStateOfPriority()->getState()->getX()][
                    s->getStateOfPriority()->getState()->getY() + 1]));
        }

        return listOfStates;
    }

    void buildMatrixFromString(std::vector<std::vector<std::string>> stringMatrix) {
        for (int i = 0; i < stringMatrix.size(); i++) {

            matrixPoints.push_back(this->installColVector(col));
            for (int j = 0; j < stringMatrix[i].size(); j++) {
                matrixPoints[i][j]->getStateOfPriority()->getState()->setX(i);
                matrixPoints[i][j]->getStateOfPriority()->getState()->setY(j);
                matrixPoints[i][j]->getStateOfPriority()->setCost(std::stod(stringMatrix[i][j]));
            }
        }
    }

    std::vector<PriorityState<Point> *> installColVector(int coli) {
        std::vector<PriorityState<Point> *> ve;
        for (int i = 0; i < coli; i++) {
            ve.push_back((new PriorityState<Point>((new Point(-1, -1)), -10, -10)));
        }
        return ve;
    }


    /*void freeMatrix(){
    }*/
};


#endif //EVEN2_SEARCHABLE_H
