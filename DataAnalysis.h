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
double  a;
        bool runF = true;
        if(trace.size() != 0) {

            for (int i = 0; i < trace.size() - 1; i++) {
                Point *p = trace[i]->getState(); // goal
                Point *cameFromP = trace[i + 1]->getState();
                if (p->getX() == cameFromP->getX()) {
                    if (cameFromP->getY() > p->getY()) {
                        road += ",Left";
                    }
                    if (cameFromP->getY() < p->getY()) {
                        road += ",Right";

                    }
                } else {// p.getY == CameFromP.getY
                    if (cameFromP->getX() > p->getX()) {
                        road += ",Up";
                    }
                    if (cameFromP->getX() < p->getX()) {
                        road += ",Down";

                    }
                }
                if (runF) {
                    runF = false;
                    road.erase(0, 1);
                }
            }
        }
        else{
            road+="stay";
        }
        road+='\n';
        return road;
    }

    std::vector<std::string> makeStringRow(std::string s) {
        std::string newString = s;
        size_t pos = 0;
        std::string token;
        std::string delimiter = ",";
        std::vector<std::string> splitted;
        while ((pos = newString.find(delimiter)) != std::string::npos) {
            token = newString.substr(0, pos);
            splitted.push_back(token);
            newString.erase(0, pos + delimiter.length());
        }
        splitted.push_back(newString);
        return splitted;
    }


    std::vector<std::vector<std::string>>
    attachRow(std::vector<std::vector<std::string>> stringMatrix, std::vector<std::string> row) {
        stringMatrix.push_back(row);
        return stringMatrix;
    }

    std::string matrixSavedFormat(std::vector<std::string> matrixInfo) {
        int size = matrixInfo.size();
        std::string fData="";
        int row = size-2;
        int col = matrixInfo[0].size();
        fData+=row;
        fData+=",";
        fData+=col;
        fData+=",";
        for(int i=size-1;i>=0;i--) {
            fData+=matrixInfo[i]+",";
        }
        return fData;
    }



};


#endif //EVEN2_DATAANALYSIS_H
