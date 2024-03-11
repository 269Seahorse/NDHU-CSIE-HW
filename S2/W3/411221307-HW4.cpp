#include <bits/stdc++.h>
using namespace std;

class just_a_class{
private:
    double km, hr;

public:
    just_a_class(double d, double t): km(d), hr(t) {};

    void v(){
        cout << km / hr << endl;
    }
};

int main(){
    double d, t;
    cin >> d >> t;
    just_a_class ahhhh(d, t);
    ahhhh.v();
}