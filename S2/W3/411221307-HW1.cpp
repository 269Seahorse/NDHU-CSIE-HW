#include <bits/stdc++.h>
using namespace std;

class Point{
public:
    float x, y;

    Point(float x2, float y2): x(x2), y(y2) {};
};

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        float x, y;
        cin >> x >> y;
        Point p(x, y);
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}