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
    PriorityState<Point>* goal;
    PriorityState<Point>* start;
    int row;
    int col;
    std::vector<std::vector< PriorityState<Point>*>> matrixPoints;

public:
    MatrixSearchable(int row, int col, PriorityState<Point> *start, PriorityState<Point> *goal,
                     std::vector<std::vector<std::string>> stringMatrix) {
        this->row = row;
        this->col = col;
        this->start = start;
        this->goal = goal;
        buidMatrixFromString(stringMatrix);

    }

    PriorityState<Point> *getInitialState() {
        return (new PriorityState<Point>((new Point(0,0)),2,10));
    };

    PriorityState<Point> * getGoalState() {
        return (new PriorityState<Point>((new Point(10,10)),1,10)); // TODO point start from 0 0 to max - 1, max - 1
    };

    std::vector<PriorityState<Point>*>
    getAllPossibleStates(PriorityState<Point>* s) {
        std::vector<PriorityState<Point>*> listOfStates; // add up down right left
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
        for (int i = 0; i < listOfStates.size(); i++) {
            PriorityState<Point> * co = new PriorityState<Point>(*s);
          //  listOfStates[i]->setCameFrom(s->getStateOfPriority());
          //  listOfStates[i]->getStateOfPriority()->setCameFrom(co->getStateOfPriority());
           /* if(listOfStates[i]->getStateOfPriority()->getCameFrom() == NULL){
                std::cout<<"Die"<<std::endl;
            }*/
        }
        return listOfStates;
    }

    void buidMatrixFromString(std::vector<std::vector<std::string>> stringMatrix) {
        for (int i = 0; i < stringMatrix.size(); i++) {

            matrixPoints.push_back(this->installColVector(col));
            for (int j = 0; j < stringMatrix[i].size(); j++) {
                //State<Point> sda = State<Point,;
                // &Point(i, j) fix it
              //  Point swd = Point(113, 112);
               // State<Point> sa = State<Point>(&swd, 25);
              //  matrixPoints[0][2] = nullptr;
                //  Point a = Point(i, j);
                 //State<Point> state = State<Point>(&a, 34);
             //   PriorityState<Point> assd = PriorityState<Point>(&sa, 43);
                matrixPoints[i][j]->getStateOfPriority()->getState()->setX(i);
                matrixPoints[i][j]->getStateOfPriority()->getState()->setY(j);
                matrixPoints[i][j]->getStateOfPriority()->setCost(std::stod(stringMatrix[i][j]));
                std::cout << matrixPoints[i][j]->getStateOfPriority()->getCost()<< std::endl;
               // matrixPoints[i][j] =  assd;
            }
        }
    }

    std::vector<PriorityState<Point>*> installColVector(int coli){
        std::vector<PriorityState<Point>*> ve;
        //PriorityState<Point>* vx =         vx = ;
        for(int i =0; i < coli; i++){
        //    std::cout<<"the real cost : "<< vx.getStateOfPriority(true).getCost()<<std::endl;
            ve.push_back((new PriorityState<Point>((new Point(-1,-1)),-10,-10)));
          //  std::cout<<ve[i].getPriotiy()<<std::endl;
        }
        return ve;
    }


    /*void freeMatrix(){
    }*/
};


#endif //EVEN2_SEARCHABLE_H
