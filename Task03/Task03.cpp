Task 03 - Dynamic Constructors and Destructors
#include <iostream>
using namespace std;

class Event {
    int rows, seats;
    char** seatMap;
    int booked;

public:
    Event(int r, int s)
        : rows(r), seats(s), booked(0) {

        seatMap = nullptr;

        if (rows <= 0 || seats <= 0) {
            rows = seats = 0;
        }
        else {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                    seatMap[i][j] = 'O';
            }
        }

        cout << "Event Created" << endl;
    }

    void book(int r, int s) {
        if (seatMap && r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'O') {

            seatMap[r][s] = 'X';
            booked++;
            cout << "Seat Booked" << endl;
        }
        else {
            cout << "Invalid Seat" << endl;
        }
    }

    void cancel(int r, int s) {
        if (seatMap && r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'X') {

            seatMap[r][s] = 'O';
            booked--;
            cout << "Booking Cancelled" << endl;
        }
    }

    ~Event() {
        if (seatMap) {
            for (int i = 0; i < rows; i++)
                delete[] seatMap[i];

            delete[] seatMap;
        }

        cout << "Event Closed. Booked Seats: "
             << booked << endl;
    }
};

int main() {
    Event e1(2, 3);
    e1.book(0, 1);
    e1.cancel(0, 1);

    {
        Event e2(2, 2);
        e2.book(1, 1);
    }

    Event* e3 = new Event(3, 3);
    e3->book(0, 0);
    delete e3;

    return 0;
}