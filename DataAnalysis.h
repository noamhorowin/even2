//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_DATAANALYSIS_H
#define EVEN2_DATAANALYSIS_H


#include <string>
#include <vector>
#include "Point.h"
#include "State.h"

class DataAnalysis {
public:
    DataAnalysis() {}

    std::string fromTraceBackToString(std::vector<State<Point> *> trace) {
        std::string road;

        bool runF = true;
        for (int i = 0; i < trace.size() - 1; i++) {
            Point *p = trace[i]->getState(); // goal
            Point *cameFromP = trace[i + 1]->getState();
            if (p->getX() == cameFromP->getX()) {
                if (cameFromP->getY() > p->getY()) {
                    road += " Left";
                }
                if (cameFromP->getY() < p->getY()) {
                    road += " Right";

                }
            } else {// p.getY == CameFromP.getY
                if (cameFromP->getX() > p->getX()) {
                    road += " Up";
                }
                if (cameFromP->getX() < p->getX()) {
                    road += " Down";

                }
            }
            if (runF) {
                runF = false;
                road.erase(0, 1);
            }
        }

        return road;
    }

    std::vector<std::string> makeStringRow(std::string s) {
        std::vector<std::string> row;
        std::cout<<"size of the s "<< s.size()<<std::endl;
        for (int i = 0; i < s.size() + 1; ++i) {
            try {
                std::stod(std::to_string(s[i]));
            }
            catch (std::exception) {
                std::cout << "block at data analysis, i saw , instead of num" << std::endl;
            }
            std::cout<<"the number i : "<< i<<std::endl;
            row.push_back(std::to_string(s[i]));
            ++i;
        }
        return row;
    }


    std::vector<std::vector<std::string>>
    attachRow(std::vector<std::vector<std::string>> stringMatrix, std::vector<std::string> row) {
        stringMatrix.push_back(row);
        return stringMatrix;
    }

};


#endif //EVEN2_DATAANALYSIS_H
