#include <bits/stdc++.h>
using namespace std;

class money{
public:
    money(float km){
        cout << round((km - (km > 200) * (km - 200)) * 1.2 + (km > 200) * (km - (km > 200) * 200) * 1.2 * 0.75);
    }
};

int main(){
    float km;
    cin >> km;
    money a(km);
}