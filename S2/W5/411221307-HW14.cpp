#include <bits/stdc++.h>
using namespace std;

class numbers{
private:
    vector<int> num;

    int n;
public:
    void insert(){
        cin >> n;
        num.resize(n);
        for(int i = 0; i < n; i++) cin >> num[i];
    }

    int rvsint(int a){
        string tmp = to_string(a);
        reverse(tmp.begin(), tmp.end());
        a = stoi(tmp);
        return a;
    }

    bool check(int a){
        string check = to_string(a);
        string check2 = check;
        reverse(check2.begin(), check2.end());
        return check == check2;
    }

    void procedure(){
        for(int i = 0; i < n; i++){
            int count = 0;
            while(count == 0 || !check(num[i])){
                num[i] += rvsint(num[i]);
                count++;
            }
            cout << count << " " << num[i] << endl;
        }
    }
};

int main(){
    numbers a;
    a.insert();
    a.procedure();
}