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
    void displayAll() const {
        if (books.empty()) {
            cout << "The inventory is empty.\n";
            return;
        }

        for (size_t i = 0; i < books.size(); i++) {
            cout << "\nBook #" << i + 1 << endl;
            books[i]->displayInfo();
        }
    }

    void removeBook(int index) {
        if (index < 1 || index > static_cast<int>(books.size())) {
            cout << "Invalid book number.\n";
            return;
        }

        delete books[index - 1];
        books.erase(books.begin() + index - 1);

        cout << "Book removed successfully.\n";
    }

    ~Inventory() {
        for (Book* bookPtr : books) {
            delete bookPtr;
        }
    }

    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;
};

int main() {
    return 0;
}