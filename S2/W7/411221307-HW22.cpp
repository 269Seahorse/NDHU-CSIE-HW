#include <bits/stdc++.h>
using namespace std;

const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
private:
    int y, m, d;
    string str1;

public:
    Date(): y(1900), m(1), d(1), str1("1900/01/01") {}

    Date(string str){
        char c;
        sscanf(str.c_str(), "%d%c%d%c%d", &y, &c, &m, &c, &d);
        str1 = str;
    }

    string toString() const {
        return str1;
    }

    int getDate() const {
        int day = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + (m > 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        for(int i = m - 1; i > 0; i--) day += month[i - 1];
        day += d;
        return day;
    }

    int operator-(const Date &t) const {
        int day = abs(getDate() - t.getDate());
        return day;
    }
};

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    Date t1(s1);
    Date t2(s2);
    cout << t1.toString() << endl << t2.toString() << endl;
    cout << t1 - t2;
}