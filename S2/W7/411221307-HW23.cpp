#include <bits/stdc++.h>
using namespace std;

class DateTime {
private:
    int y, m, d, h, min, s;
    string str1;

public:
    DateTime(): y(1900), m(1), d(1), h(0), min(0), s(0), str1("1900/01/01 00:00:00") {}

    DateTime(string str){
        char c;
        sscanf(str.c_str(), "%d%c%d%c%d%d%c%d%c%d", &y, &c, &m, &c, &d, &h, &c, &min, &c, &s);
        str1 = str;
    }

    string toString() const {
        return str1;
    }
};

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    DateTime t1(s1);
    DateTime t2(s2);
    cout << t1.toString() << endl << t2.toString() << endl;
}