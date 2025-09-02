#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction {
private:
    int num;
    int den;

    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void normalize() {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        if (num == 0) {
            den = 1;
        }
    }

public:
    Fraction() : num(0), den(1) {}

    Fraction(int n, int d) : num(n), den(d) {
        if (d == 0) {
            cerr << "Denominator cannot be zero! Setting to 1." << endl;
            den = 1;
        }
        normalize();
    }

    Fraction(const Fraction& other) : num(other.num), den(other.den) {}

    void printFraction() const {
        cout << num << "/" << den << endl;
    }

    void printNumerator() const {
        cout << num << endl;
    }

    void printDenominator() const {
        cout << den << endl;
    }

    void addNumber(int number) const {
        int new_num = num + number * den;
        int new_den = den;
        Fraction res(new_num, new_den);
        cout << "Result: " << res.num << "/" << res.den << endl;
    }

    void addFraction(const Fraction& other) const {
        int new_num = num * other.den + other.num * den;
        int new_den = den * other.den;
        Fraction res(new_num, new_den);
        cout << "Result: " << res.num << "/" << res.den << endl;
    }

    void subtractNumber(int number) const {
        int new_num = num - number * den;
        int new_den = den;
        Fraction res(new_num, new_den);
        cout << "Result: " << res.num << "/" << res.den << endl;
    }

    void subtractFraction(const Fraction& other) const {
        int new_num = num * other.den - other.num * den;
        int new_den = den * other.den;
        Fraction res(new_num, new_den);
        cout << "Result: " << res.num << "/" << res.den << endl;
    }

    void multiplyNumber(int number) const {
        int new_num = num * number;
        int new_den = den;
        Fraction res(new_num, new_den);
        cout << "Result: " << res.num << "/" << res.den << endl;
    }

    void multiplyFraction(const Fraction& other) const {
        int new_num = num * other.num;
        int new_den = den * other.den;
        Fraction res(new_num, new_den);
        cout << "Result: " << res.num << "/" << res.den << endl;
    }

    void divideFraction(const Fraction& other) const {
        if (other.num == 0) {
            cout << "Division by zero!" << endl;
            return;
        }
        int new_num = num * other.den;
        int new_den = den * other.num;
        Fraction res(new_num, new_den);
        cout << "Result: " << res.num << "/" << res.den << endl;
    }

    void divideNumber(int number) const {
        if (number == 0) {
            cout << "Division by zero!" << endl;
            return;
        }
        int new_num = num;
        int new_den = den * number;
        Fraction res(new_num, new_den);
        cout << "Result: " << res.num << "/" << res.den << endl;
    }

    void simplify() {
        if (den == 0) return;
        int g = gcd(num, den);
        num /= g;
        den /= g;
        normalize();
    }

    bool isProper() const {
        return abs(num) < abs(den);
    }
};
