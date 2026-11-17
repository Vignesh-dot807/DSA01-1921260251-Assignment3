Task 07 - Complex Number Class
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r) : real(r), imag(0) {}

    Complex(double r, double i)
        : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    Complex operator/(const Complex& c) const {
        double d = c.real * c.real + c.imag * c.imag;

        if (d == 0)
            throw runtime_error("Division by zero");

        return Complex(
            (real * c.real + imag * c.imag) / d,
            (imag * c.real - real * c.imag) / d
        );
    }

    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + j" << c.imag;
        else
            out << " - j" << -c.imag;

        return out;
    }
};

int main() {
    Complex R(10, 0);
    Complex L(0, 5);
    Complex C(0, -2);

    Complex series = R + L + C;

    cout << "Series Impedance: " << series << endl;

    Complex z1(4, 3);
    Complex z2(4, -3);

    Complex parallel = (z1 * z2) / (z1 + z2);

    cout << "Parallel Impedance: " << parallel << endl;

    cout << "Magnitude: " << parallel.magnitude() << endl;

    try {
        Complex zero;
        Complex result = z1 / zero;
        cout << result << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}