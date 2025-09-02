#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

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
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        if (numerator == 0) {
            denominator = 1;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int n, int d) : numerator(n), denominator(d) {
        if (d == 0) {
            cerr << "Denominator cannot be zero! Setting to 1." << endl;
            denominator = 1;
        }
        normalize();
    }

    Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

    void printFraction() const {
        cout << numerator << "/" << denominator << endl;
    }

    void printNumerator() const {
        cout << numerator << endl;
    }

    void printDenominator() const {
        cout << denominator << endl;
    }

    void addNumber(int number) const {
        int newNumerator = numerator + number * denominator;
        int newDenominator = denominator;
        Fraction res(newNumerator, newDenominator);
        cout << "Result: " << res.numerator << "/" << res.denominator << endl;
    }

    void addFraction(const Fraction& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        Fraction res(newNumerator, newDenominator);
        cout << "Result: " << res.numerator << "/" << res.denominator << endl;
    }

    void subtractNumber(int number) const {
        int newNumerator = numerator - number * denominator;
        int newDenominator = denominator;
        Fraction res(newNumerator, newDenominator);
        cout << "Result: " << res.numerator << "/" << res.denominator << endl;
    }

    void subtractFraction(const Fraction& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        Fraction res(newNumerator, newDenominator);
        cout << "Result: " << res.numerator << "/" << res.denominator << endl;
    }

    void multiplyNumber(int number) const {
        int newNumerator = numerator * number;
        int newDenominator = denominator;
        Fraction res(newNumerator, newDenominator);
        cout << "Result: " << res.numerator << "/" << res.denominator << endl;
    }

    void multiplyFraction(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        Fraction res(newNumerator, newDenominator);
        cout << "Result: " << res.numerator << "/" << res.denominator << endl;
    }

    void divideFraction(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "Division by zero!" << endl;
            return;
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        Fraction res(newNumerator, newDenominator);
        cout << "Result: " << res.numerator << "/" << res.denominator << endl;
    }

    void divideNumber(int number) const {
        if (number == 0) {
            cout << "Division by zero!" << endl;
            return;
        }
        int newNumerator = numerator;
        int newDenominator = denominator * number;
        Fraction res(newNumerator, newDenominator);
        cout << "Result: " << res.numerator << "/" << res.denominator << endl;
    }

    void simplify() {
        if (denominator == 0) return;
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        normalize();
    }

    bool isProper() const {
        return abs(numerator) < abs(denominator);
    }
};
