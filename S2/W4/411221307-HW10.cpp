#include <bits/stdc++.h>
using namespace std;

class uwu{
public:
    uwu(string a){
        bool y = 0;
        for(int i = 0; i < 4; i++){
            if (a[i] == '4'){
                cout << "Yes";
                y = 1;
                break;
            }
        }
        if(!y) cout << "No";
    }
};

int main(){
    string a;
    cin >> a;
    uwu awa(a);
}