#include <bits/stdc++.h>
using namespace std;

const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
private:
    int y, m, d;

public:
    Date(): y(1900), m(1), d(1) {}

    Date(string str){
        y = stoi(str.substr(0, 4));
        m = stoi(str.substr(4, 2));
        d = stoi(str.substr(6, 2));
    }

    Date(int _y, int _m, int _d): y(_y), m(_m), d(_d) {} 

    int getDay() const {
        int day = (y - 1) * 365 + leap(y) - (m < 3);
        for(int i = m - 1; i >= 0; i--) day += month[i - 1];
        day += d;
        return day;
    }

    bool leap(int year) const {
        return ((!(year % 4) && year % 100) || !(year % 400));
    }

    Date nextDay() const {
        int d2 = d, m2 = m, y2 = y;
        if((d2 + 1) > (month[m2 - 1] + (m2 == 2 && leap(y2)))){
            d2 = 0;
            m2++;
        }
        if(m2 > 12){
            m2 = 1;
            y2++;
        }
        d2++;
        return Date(y2, m2, d2);
    }

    Date lastDay() const {
        int d2 = d, m2 = m, y2 = y;
        if(d2 > 1) return Date(y2, m2, d2 - 1);
        if(m2 > 1) return Date(y2, m2 - 1, (month[m2 - 2] + (m2 == 3 && leap(y2))));
        return Date(y2 - 1, 12, 31);
    }

    void print() const {
        cout << m << "/" << d << "/" << y;
    }

    bool operator ==(Date date) const {
        return getDay() == date.getDay();
    }

    bool operator >(Date date) const {
        return getDay() > date.getDay();
    }

    bool operator <(Date date) const {
        return getDay() < date.getDay();
    }

    bool operator <=(Date date) const {
        return getDay() <= date.getDay();
    }

    bool operator >=(Date date) const {
        return getDay() >= date.getDay();
    }
};

void merge(vector<pair<Date, Date>> &x, vector<pair<Date, Date>> &y){
    if(!x.size()) return;
    y.push_back(x[0]);
    int count = 0;
    for(int i = 1; i < x.size(); i++){
        if(y[count].second.nextDay() < x[i].first){
            y.push_back(x[i]);
            count++;
        }
        else y[count].second = max(y[count].second, x[i].second); //see if current or original vector end date is later
    }
}

void Print(pair<Date, Date> &x){
    if(x.first == x.second){
        cout << endl;
        x.first.print();
    }
    else{
        cout << endl;
        x.first.print();
        cout << " to ";
        x.second.print();
    }
}

int main(){
    int cases = 0;
    while(true){
        int a, b;
        cin >> a >> b;
        if(!(a || b)) return 0;
        cases++;
        if(cases != 1) cout << endl;
        cout << "Case " << cases << ":";
        string c, d;
        vector<pair<Date, Date>> be4, after;
        for(int i = 0; i < a; i++){
            cin >> c >> d;
            be4.push_back(make_pair(Date(c), Date(d)));
        }
        sort(be4.begin(), be4.end());
        for(int i = 0; i < b; i++){
            cin >> c >> d;
            after.push_back(make_pair(Date(c), Date(d)));
        }
        sort(after.begin(), after.end());
        vector<pair<Date, Date>> ik, idk;
        merge(be4, ik);
        merge(after, idk);
        if(!ik.size()){
            for(int i = 0; i < idk.size(); i++) Print(idk[i]);
            continue;
        }
        ik.push_back(make_pair(Date(2222, 11, 11), Date(2222, 11, 12))); //to make the code check the last time
        vector<pair<Date, Date>> ans;
        for(int i = 0; i < idk.size(); i++){
            Date left = idk[i].first;
            Date right = idk[i].second;
            for(int j = 0; j < ik.size(); j++){
                if(ik[j].second < left) continue; //known is earlier than unknown, so no need to check
                if(right < ik[j].first){ //unknown > known, simply push back
                    ans.push_back(make_pair(left, right));
                    break;
                }
                if(ik[j].first <= left && right <= ik[j].second){
                    break; //ik.a < idk.a < idk.b < ik.b, all gone
                }
                if(left < ik[j].first && right <= ik[j].second){
                    ans.push_back(make_pair(left, ik[j].first.lastDay()));
                    break; //the right side is gone
                }
                if(ik[j].first <= left && ik[j].second < right){
                    left = ik[j].second.nextDay();
                    continue; //the left side is gone
                }
                ans.push_back(make_pair(left, ik[j].first.lastDay()));
                left = ik[j].second.nextDay(); //idk.a < ik.a < ik.b < idk.b
            }
        }
        if(!ans.size()){
            cout << "\nNo additional quotes are required.";
            continue;
        }
        for(int i = 0; i < ans.size(); i++) Print(ans[i]);
    }
}