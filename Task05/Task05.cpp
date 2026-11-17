Task 05 - Increment Comparison and Subscript Operators
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    Time& operator++() {
        ++seconds;
        return *this;
    }

    Time operator++(int) {
        Time old = *this;
        ++seconds;
        return old;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    int getValue() const {
        return seconds;
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(vector<string> t) : tracks(t) {}

    string& operator[](int i) {
        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");

        return tracks[i];
    }

    const string& operator[](int i) const {
        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");

        return tracks[i];
    }
};

int main() {
    Time t(5);

    Time a = t++;
    Time b = ++t;

    cout << a.getValue() << " "
         << b.getValue() << " "
         << t.getValue() << endl;

    Playlist p({"Intro", "Main Theme", "Ending"});

    cout << "Track: " << p[1] << endl;

    try {
        cout << p[5] << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}