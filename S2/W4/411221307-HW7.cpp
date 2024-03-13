class Segment{
private:
    Point p1, p2;

public:
    Segment(Point *_p1, Point *_p2): p1(*_p1), p2(*_p2) {};

    double length(){
        return sqrt((p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p2.getY() - p1.getY()));
    }

    Point getEnd(int n){
        if(n) return p2;
        else return p1;
    }
};