Task 04 - Arithmetic and Stream Operator Overloading
#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long r = 0, int p = 0)
        : paise(r * 100 + p) {}

    Money operator+(const Money& m) const {
        Money result;
        result.paise = paise + m.paise;
        return result;
    }

    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long value = m.paise;
        if (value < 0) {
            out << "-";
            value = -value;
        }

        out << "Rs " << value / 100 << "."
            << setw(2) << setfill('0') << value % 100;

        return out;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;

    Money x(0, 75);
    Money y(0, 50);

    cout << x + y << endl;

    return 0;
}