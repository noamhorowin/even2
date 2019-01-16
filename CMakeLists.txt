cmake_minimum_required(VERSION 3.13)
project(even2)

set(CMAKE_CXX_STANDARD 14)

add_executable(even2 main.cpp State.cpp State.h ISearchable.h ISearcher.h Searcher.cpp Searcher.h MyPriorityQueue.cpp MyPriorityQueue.h BestFirstSearch.cpp BestFirstSearch.h ReverseString.cpp ReverseString.h Point.h MatrixSearchable.cpp MatrixSearchable.h MyComparator.cpp MyComparator.h BreadthFirstSearch.cpp BreadthFirstSearch.h DepthFirstSearch.cpp DepthFirstSearch.h AStar.cpp AStar.h HeuristicPointFunc.cpp HeuristicPointFunc.h IHeuristic.cpp IHeuristic.h PriorityState.cpp PriorityState.h)