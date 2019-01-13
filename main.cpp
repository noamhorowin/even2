#include <iostream>
#include "queue"
#include "vector"
#include "ReverseString.h"
#include "Point.h"

//#include
int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> mypq;

    mypq.push(30);
    mypq.push(100);
    mypq.push(25);
    mypq.push(40);
    Point w=Point(20,23);
    Point das= Point(590,123);
    std::cout<<"x dis : " << w.getXdistance(das)<<" y dis: "<<w.getYdistance(das)<<" total dis: " <<das.getDistance(w)<<std::endl;
    ReverseString r = ReverseString();
    std::string s = r.activeReverser(" dam futs\n",true);
    std::cout << s << std::endl;
  //  mypq.emplace(30,12324);
    std::cout << "Popping out elements...";
    while (!mypq.empty()) {
        std::cout << ' ' << mypq.top();
        mypq.pop();
    }
    std::cout << '\n';
    return 0;
}