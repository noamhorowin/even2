//
// Created by noam on 1/11/19.
//

#ifndef EVEN2_POINT_H
#define EVEN2_POINT_H
//template <class T>
class Point {

    double x;
    double y;
public:
    Point(double X, double Y) {
        this->x = X;
        this->y = Y;
    }

    int getX() const {
        return this->x;
    }

    int getY() const {
        return this->y;
    }

    void setX(double X) {
        this->x = X;
    }

    void setY(double Y) {
        this->y = Y;
    }

    void setPoint(double X, double Y) {
        this->x = X;
        this->y = Y;
    }

    double getXdistance(Point p) {
        return this->x - p.x;
    }

    double getYdistance(Point p) {
        return this->y - p.y;
    }

    double getDistance(Point p) {

        return this->getYdistance(p) + this->getXdistance(p);
    }

    bool operator==(const Point &p)const{
        return ((x == p.getX()) &&(y==p.getY()));
    }
    // int getDistancePitagorass
};

#endif //EVEN2_POINT_H
