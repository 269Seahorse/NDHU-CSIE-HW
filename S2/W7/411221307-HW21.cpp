#include <bits/stdc++.h>
using namespace std;

class Time {
private:
    int h, m, s;
    string str1;

public:
    Time(): h(0), m(0), s(0), str1("00:00:00") {}

    Time(string str){
        char d;
        sscanf(str.c_str(), "%d%c%d%c%d", &h, &d, &m, &d, &s);
        str1 = str;
    }

    string toString() const {
        return str1;
    }

    int getTime() const {
        return h * 3600 + m * 60 + s;
    }

    int operator-(const Time &t) const {
        int sec = abs(h * 3600 + m * 60 + s - t.getTime());
        return sec;
    }
};

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    Time t1(s1);
    Time t2(s2);
    cout << t1.toString() << endl << t2.toString() << endl;
    cout << t1 - t2;
}