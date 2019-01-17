#include <iostream>
#include "queue"
#include "PriorityState.h"
#include "Point.h"
#include "MyPriorityQueue.h"
#include "MatrixSearchable.h"
#include "DepthFirstSearch.h"
#include "BestFirstSearch.h"
#include "AStar.h"
#include "ISearchable.h"
#include "HeuristicPointFunc.h"
#include "ISearchable.h"
#include "BestFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "FileCacheManager.h"
#include "DataAnalysis.h"
#include "unordered_map"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MyParallelServer.h"
#include "ReverseString.h"
#include "MatrixSolver.h"
#include "MyClientHandler.h"

using namespace std;

/*
 *
 *
 */
int main(int argc, char **argv) {
    vector<string> lines;
    AStar<Point> *astar = new AStar<Point>(new HeuristicPointFunc(new State<Point>((new Point(0, 0)), 0)));
    MatrixSolver *ms1 = new MatrixSolver(astar, lines);

     ClientHandler* clientHandler = new MyClientHandler(ms1, new FileCacheManager("myFile.txt"));
     MyParallelServer s;
     s.open(stoi(argv[1]), clientHandler);
     pthread_exit(nullptr);
    //return 0;
}