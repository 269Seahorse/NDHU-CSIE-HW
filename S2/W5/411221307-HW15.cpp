#include <bits/stdc++.h>
using namespace std;

class instructions{
private:
    string cmd, p1, p2, p3;

public:
    instructions(string _cmd, string _p1, string _p2, string _p3): cmd(_cmd), p1(_p1), p2(_p2), p3(_p3) {
        if(cmd == "addi"){
            opTranslate(cmd);
            regTranslate(p2);
            regTranslate(p1);
            regTranslate(p3);
        }
        else {
            opTranslate(cmd);
            regTranslate(p2);
            regTranslate(p3);
            regTranslate(p1);
            shamt();
            functTranslate(cmd);
        }
    }

    void regTranslate(string a){
        string tmp = a.substr(0, 3);
        if(tmp == "$t0") cout << "01000";
        else if(tmp == "$t1") cout << "01001";
        else if(tmp == "$t2") cout << "01010";
        else if(tmp == "$t3") cout << "01011";
        else if(tmp == "$t4") cout << "01100";
        else if(tmp == "$t5") cout << "01101";
        else if(tmp == "$t6") cout << "01110";
        else if(tmp == "$t7") cout << "01111";
        else{
            dec2bin(stoi(a));
        }
    }

    void opTranslate(string a){
        if(a == "add") cout << "000000";
        else if(a == "sub") cout << "000000";
        else if(a == "or") cout << "000000";
        else if(a == "and") cout << "000000";
        else if(a == "addi") cout << "001000";
    }

    void shamt(){
        cout << "00000";
    }

    void functTranslate(string a){
        if(a == "add") cout << "100000";
        else if(a == "sub") cout << "100010";
        else if(a == "or") cout << "100101";
        else if(a == "and") cout << "100100";
    }

    void dec2bin(int a){
        int digit = 0, ans = 0;
        while(a != 0){
            ans += (a % 2) * (pow(10, digit));
            a /= 2;
            digit++;
        }
        if(digit == 0) digit = 1;
        for(int i = 0; i < (16 - digit); i++) cout << "0";
        cout << ans;
    }
};

int main(){
    string cmd, p1, p2, p3;
    while(cin >> cmd >> p1 >> p2 >> p3){
        instructions a(cmd, p1, p2, p3);
        cout << endl;
    }
}