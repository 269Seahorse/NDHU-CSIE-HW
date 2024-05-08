#include <bits/stdc++.h>
using namespace std;

class Point{
private:
    float x, y;

public:
    Point(float x2, float y2): x(x2), y(y2) {};

    Point(): x(0), y(0) {};

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    void setX(float _x) {
        x = _x;
    }

    void setY(float _y) {
        y = _y;
    }

    void printPoint() const {
        cout << "(" << x << ", " << y << ")";
    }

    float getDistance(Point p) const {
        return sqrt((x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY()));
    }
};

class Segment{
private:
    Point p1, p2;

public:
    Segment(Point _p1, Point _p2): p1(_p1), p2(_p2) {};

    Segment() {
        p1 = *(new Point);
        p2 = *(new Point);
    }

    float getLength() const {
        return sqrt((p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p2.getY() - p1.getY()));
    }
};
