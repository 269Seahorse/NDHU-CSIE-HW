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
    void display(){
        cout << *this;
    }
    friend std::ostream& operator << (std::ostream& out, Fraction &f) {
        if(f.denominator < 0){
            f.denominator *= -1;
            f.numerator *= -1;
        }
        if (f.denominator != 1)
            out << "(" << f.numerator << "/" << f.denominator << ")";
        else
            out << "(" << f .numerator << ")";
        return out;
    }

    int lcm(int a, int b) const {
        return a * b / __gcd(a, b);
    }

    Fraction operator +(const Fraction &f) const {
        int n, d, _gcd, _lcm;
        _gcd = __gcd(denominator, f.getDenominator());
        _lcm = lcm(denominator, f.getDenominator());
        n = numerator * (_lcm / denominator) + f.getNumerator() * (_lcm / f.getDenominator());
        d = _lcm;
        int tmp = __gcd(n, d);
        n /= tmp;
        d /= tmp;
        return Fraction(n, d);
    }

    Fraction operator -(const Fraction &f) const {
        int n, d, _gcd, _lcm;
        _gcd = __gcd(denominator, f.getDenominator());
        _lcm = lcm(denominator, f.getDenominator());
        n = numerator * (_lcm / denominator) - f.getNumerator() * (_lcm / f.getDenominator());
        d = _lcm;
        int tmp = __gcd(n, d);
        n /= tmp;
        d /= tmp;
        return Fraction(n, d);
    }

    Fraction operator *(const Fraction &f) const {
        int n, d, _gcd, _lcm;
        _gcd = __gcd(denominator, f.getDenominator());
        _lcm = lcm(denominator, f.getDenominator());
        n = numerator * f.getNumerator();
        d = denominator * f.getDenominator();
        int tmp = __gcd(n, d);
        n /= tmp;
        d /= tmp;
        return Fraction(n, d);
    }

    Fraction operator /(const Fraction &f) const {
        int n, d, _gcd, _lcm;
        _gcd = __gcd(denominator, f.getDenominator());
        _lcm = lcm(denominator, f.getDenominator());
        n = numerator * f.getDenominator();
        d = denominator * f.getNumerator();
        int tmp = __gcd(n, d);
        n /= tmp;
        d /= tmp;
        return Fraction(n, d);
    }

    void operator =(const Fraction &f){
        numerator = f.getNumerator();
        denominator = f.getDenominator();
    }

    Fraction operator !(){
        int _gcd = __gcd(numerator, denominator);
        return Fraction(denominator / _gcd, numerator / _gcd);
    }

private:
    int numerator, denominator;
};

int main(){
    int a, b;
    cin >> a >> b;
    Fraction aa(a, b), k;
    k = !aa;
    k.display();
}