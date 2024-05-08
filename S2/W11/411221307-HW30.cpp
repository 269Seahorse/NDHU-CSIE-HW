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

    bool operator ==(Point p) const {
        return (x == p.getX() && y == p.getY());
    }

    bool operator >(Point p) const {
        return (x > p.getX() && y > p.getY());
    }

    bool operator <(Point p) const {
        return (x < p.getX() && y < p.getY());
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

    Point getP1() const {
        return p1;
    }

    Point getP2() const {
        return p2;
    }

    float getLength() const {
        return sqrt((p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p2.getY() - p1.getY()));
    }
};

class Shape{
public:
    Shape(): edgeCount(0) {};

    Shape(Segment *s, int n) {
        if(n < 3) throw invalid_argument("666");
        list<Point> chk;
        chk.clear();
        for(int i = 0; i < n; i++){
            if(find(chk.begin(), chk.end(), s[i].getP2()) != chk.end()) throw invalid_argument("666");
            chk.push_front(s[i].getP2());
        }
        for(int i = 0; i < n; i++){
            chk.remove(s[i].getP1());
        }
        if(!chk.empty()) throw invalid_argument("666");
        for(int i = 0; i < n; i++) seg[i] = s[i];
        edgeCount = n;
    }; // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.

    virtual float getArea() = 0;

    float getPerimeter(){
        float peri = 0;
        for(int i = 0; i < edgeCount; i++) peri += seg[i].getLength();
        return peri;
    }

    Segment &getSeg(int index){
        return seg[index];
    }

private:
    Segment seg[10];
    int edgeCount;
};

class Rectangle : public Shape{
public:
    Rectangle(Segment *s): Shape(s, 4) {};
    float getArea() override {
        float length = getSeg(0).getLength();
        float width;
        for(int i = 1; i < 4; i++){
            if(getSeg(i).getLength() != length){
                width = getSeg(1).getLength();
                break;
            }
            if(i == 3) width = length;
        }
        return length * width;
    }
};