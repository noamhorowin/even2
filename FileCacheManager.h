//
// Created by noam on 1/16/19.
//

#ifndef EVEN2_FILECACHEMANAGER_H
#define EVEN2_FILECACHEMANAGER_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include "ICacheManager.h"

/**
 * load from file to map at birth.
 * update map in life
 * upload all data from map to file in death.
 */
class FileCacheManager : public ICacheManager<std::string, std::string> {
private:
    std::unordered_map<std::string, std::string> myMap;
    std::string fileName;
public:
// Constructor & Destructor
     FileCacheManager(std::string fileName) {
        this->fileName = fileName;
    }

    ~FileCacheManager() {
        saveAllToFile();
    }


    bool contains(std::string problem) {
        //formatData(problem);
        bool exists = (myMap.count(problem) > 0);
        //undoFormatData(problem);
        return exists;
    }

    std::string getSolution(std::string problem) {
        //formatData(problem);
        std::string sol = myMap.at(problem);
        //undoFormatData(problem);
        return sol;
    }

    void saveSolution(std::string problem, std::string solution) {
        myMap[problem] = solution;
    }

// file to map
    void loadFromFile() {
        std::ifstream inFile(fileName);
        std::string problem;
        std::string sol;
        if (inFile.is_open()) {
            // Load file here
            while (getline(inFile, problem) && (!(inFile.eof()))) {
                if (!problem.empty()) {
                    getline(inFile, sol);
                    //undoFormatData(problem);
                    //undoFormatData(sol);
                    myMap[problem] = sol;
                }
            }
        }
        inFile.close();
    }

// map to file
    void saveAllToFile() {
        std::ofstream myFile(fileName);
        for (std::pair<std::string, std::string> pair : myMap) {
            myFile << pair.first<< std::endl;
            myFile << pair.second << std::endl;
        }
        myFile.close();
    }



};


#endif //EVEN2_FILECACHEMANAGER_H
