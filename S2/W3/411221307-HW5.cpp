#include <bits/stdc++.h>
using namespace std;

class just_a_class{
private:
    int x, y;

public:
    just_a_class(int _x, int _y): x(_x), y(_y) {};

    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
};

class just_another_class{
private:
    just_a_class a, b;

public:
    just_another_class(just_a_class _a, just_a_class _b): a(_a), b(_b) {};

    void compare(){
        if(a.getX() < b.getY() && a.getY() > b.getX()) cout << "overlay\n";
        else cout << "no overlay\n";
    }
};

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    just_a_class aa(a, b), aaa(c, d);
    just_another_class aaaa(aa, aaa);
    aaaa.compare();
}