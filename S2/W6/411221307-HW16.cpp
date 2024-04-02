#include <bits/stdc++.h>
using namespace std;

class Anagram: public string {
private:
    string a = "";

public:
    Anagram(string _a){
        for(int i = 0; i < _a.length(); i++){
            if(isalpha(_a[i])) a += tolower(_a[i]);
        }
    }

    bool operator==(const Anagram &str) const{
        int tmp[26] = {0};
        if(a.length() != str.a.length()) return false;
        for(int i = 0; i < a.length(); i++){
            tmp[a[i] - 'a']++;
        }
        for(int i = 0; i < a.length(); i++){
            tmp[str.a[i] - 'a']--;
        }
        bool flag = 1;
        for(int i = 0; i < 26; i++){
            if(tmp[i] != 0){
                flag = 0;
                break;
            }
        }
        return flag;
    };
};

int main() {
    string buf;
    getline(cin, buf);
    Anagram a1(buf);
    getline(cin, buf);
    Anagram a2(buf);
    cout << (a1 == a2) << endl;
    cout << (a2 == a1) << endl;
}