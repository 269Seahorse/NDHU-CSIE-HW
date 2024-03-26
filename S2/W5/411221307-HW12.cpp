#include <bits/stdc++.h>
using namespace std;

const string num = "0123456789";

class Digit { // class Digit represent a digit in base 10
private:
    int digit;

public:
    Digit(int d) : digit(d % 10) {}

    Digit() {
        digit = 0;
    }

    void setDigit(int d) {
        digit = d % 10;
    }

    int getDigit() const {
        return digit;
    }
};
class Integer { //class Integer represent a integer
    Digit value[1000];

    bool sign = 0;

    int count = 0;
public:
    //construct an integer in base 10 using a string.
    //This constructor will convert the given string to integer if possible.
    //Otherwise it will convert the digit part in prefix of the given string.
    Integer(string n){
        reverse(n.begin(), n.end());
        for(int i = 0; i < n.length(); i++){
            if(n[i] >= '0' && n[i] <= '9'){
                value[i].setDigit(n[i] - '0');
                count++;
            }
            if(n[i] == '-') {
                sign = 1;
            }
        }
    }
    //default constructor will construct an Integer object with value 0.
    Integer(){
        count++;
        value[0].setDigit(0);
    }
    //function addition will add up two integer and return a new Integer object as result.
    Integer addition(const Integer &b) const{
        string ans = "";
        int len = max(count, b.count), carry = 0;
        for(int i = 0; i < len; i++){
            int tmp = value[i].getDigit() + b.value[i].getDigit() + carry;
            carry = 0;
            if(tmp >= 10){
                tmp -= 10;
                carry = 1;
            }
            ans.push_back(num[tmp]);
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return Integer(ans);
    };
    //function subtraction will minus b from current object and return a new as result.
    Integer subtraction(const Integer &b) const{
        string ans = "";
        bool negative = 0, carry = 0;
        if((count < b.count) || (count == b.count && value[count - 1].getDigit() < b.value[count - 1].getDigit())) negative = 1;
        int len = max(count, b.count), tmp;
        for(int i = 0; i < len; i++){
            if(!negative)
                tmp = value[i].getDigit() - b.value[i].getDigit() - carry;
            else
                tmp = b.value[i].getDigit() - value[i].getDigit() - carry;
            carry = 0;
            if(tmp < 0){
                tmp += 10;
                carry = 1;
            }
            ans.push_back(num[tmp]);
        }
        if(negative) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return Integer(ans);
    };

    void display(){
        bool isZero = 1;
        if(sign) cout << "-";
        for(int i = count - 1; i >= 0; i--){
            if(value[i].getDigit() != 0) isZero = 0;
            if(value[i].getDigit() != 0 || isZero == 0 || i == 0)
                cout << num[value[i].getDigit()];
        }
    }
};

// int main(){
//   string a, b;
//   cin >> a >> b;
//   Integer num1(a), num2(b);
//   num1.addition(num2).display();
//   cout << endl;
//   num2.addition(num1).display();
//   cout << endl;
//   num1.subtraction(num2).display();
//   cout << endl;
//   num2.subtraction(num1).display();
//   cout << endl;
// }