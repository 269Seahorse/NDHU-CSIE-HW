#include <bits/stdc++.h>
using namespace std;

class Point{
private:
    float x, y;

public:
    Point(float x2, float y2): x(x2), y(y2) {};

    float getx() {
        return x;
    }

    float gety() {
        return y;
    }
};

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        float x, y;
        cin >> x >> y;
        Point p(x, y);
        cout << "(" << p.getx() << ", " << p.gety() << ")\n";
    }
}