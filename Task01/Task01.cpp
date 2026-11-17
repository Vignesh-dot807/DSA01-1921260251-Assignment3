Task 01 - Constructors and Constructor Overloading
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title;
    int copies;
    string author;

public:
    Book() : Book("Untitled", 0, "Unknown") {}

    explicit Book(string t) : Book(t, 1, "Unknown") {}

    Book(string t, int c, string a)
        : title(t), copies(c), author(a) {
        if (copies < 0)
            throw invalid_argument("Invalid copies");
    }

    void display() const {
        cout << "Title: " << title
             << ", Copies: " << copies
             << ", Author: " << author << endl;
    }
};

int main() {
    try {
        Book b1;
        Book b2("The Alchemist");
        Book b3("Wings of Fire", 5, "A.P.J Abdul Kalam");

        b1.display();
        b2.display();
        b3.display();

        Book b4("Invalid Book", -2, "Test");
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}