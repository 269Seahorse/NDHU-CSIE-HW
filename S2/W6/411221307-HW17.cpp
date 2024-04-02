#include <bits/stdc++.h>
using namespace std;

class Fraction {
public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int n, int m) : numerator(n) {
        if(m == 0)
        throw "divided by zero";
        denominator = m;
    }
    int getNumerator() const {
        return numerator;
    }
    int getDenominator() const {
        return denominator;
    }
    void setNumerator(int n) {
        numerator = n;
    }
    void setDenominator(int m) {
        if(m == 0)
        throw "divided by zero";
        denominator = m;
    }
    friend std::ostream& operator << (std::ostream& out, const Fraction &f) {
        if (f.denominator != 1)
            out << "[" << f.numerator << "/" << f.denominator << "]";
        else
            out << f.numerator;
        return out;
    }

private:
    int numerator, denominator;
};


//didn't want to write lcm but the version of oj compiler is just too old =.=
int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

Fraction operator +(const Fraction &f, const Fraction &f2) {
    int n, d, _gcd, _lcm;
    _gcd = __gcd(f.getDenominator(), f2.getDenominator());
    _lcm = lcm(f.getDenominator(), f2.getDenominator());
    n = f.getNumerator() * (_lcm / f.getDenominator()) + f2.getNumerator() * (_lcm / f2.getDenominator());
    d = _lcm;
    int tmp = __gcd(n, d);
    n /= tmp;
    d /= tmp;
    return Fraction(n, d);
}

Fraction operator -(const Fraction &f, const Fraction &f2) {
    int n, d, _gcd, _lcm;
    _gcd = __gcd(f.getDenominator(), f2.getDenominator());
    _lcm = lcm(f.getDenominator(), f2.getDenominator());
    n = f.getNumerator() * (_lcm / f.getDenominator()) - f2.getNumerator() * (_lcm / f2.getDenominator());
    d = _lcm;
    int tmp = __gcd(n, d);
    n /= tmp;
    d /= tmp;
    return Fraction(n, d);
}

bool operator ==(const Fraction &f, const Fraction &f2) {
    int n1, n2, _gcd, _lcm;
    _gcd = __gcd(f.getDenominator(), f2.getDenominator());
    _lcm = lcm(f.getDenominator(), f2.getDenominator());
    n1 = f.getNumerator() * (_lcm / f.getDenominator());
    n2 =  f2.getNumerator() * (_lcm / f2.getDenominator());
    return n1 == n2;
}

int main(){
    int n1, n2, m1, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    Fraction f1(n1, m1), f2(n2, m2);
    cout << (f1 + f2) << endl;
    cout << (f1 - f2) << endl;
    cout << (f1 == f2) << endl;
}