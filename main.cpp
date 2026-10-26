/*
Author: Fabian Olmedo
Date: October 26, 2026
Project: Pointers
Purpose: Create a reliable book inventory system by implementing the Inventory class
which will be fully responsible for the life-cycle of all Book objects it contains
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    Book(string title, string author, double price)
        : title(title), author(author), price(price) {
    }

    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
    }
};

class Inventory {
private:
    vector<Book*> books;

public:
    void addBook(Book* bookPtr) {
        if (bookPtr != nullptr) {
            books.push_back(bookPtr);
            cout << "Book added successfully.\n";
        }
    }
};

int main() {
    return 0;
}