#include <bits/stdc++.h>
using namespace std;

//don't modify
class Point {
    double x, y;
public:
    void setX(double _x) {
        x = _x;
    }
    void setY(double _y) {
        y = _y;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
};
//code start

class Segment{
public:
    Point p1, p2;

    void distance(){
        cout << sqrt((p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p2.getY() - p1.getY())) << endl;
    }
};

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        Segment seg;
        seg.p1.setX(a);
        seg.p1.setY(b);
        seg.p2.setX(c);
        seg.p2.setY(d);
        seg.distance();
    }
}