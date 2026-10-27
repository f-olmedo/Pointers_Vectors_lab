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
    Inventory() = default;

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

        cout << "Inventory destroyed. Remaining books deleted.\n";
    }

    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;
};

int main() {
    Inventory store;
    int choice = 0;

    do {
        cout << "\n===== Book Inventory =====\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Remove Book\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            string title;
            string author;
            double price;

            cout << "Enter book title: ";
            getline(cin, title);

            cout << "Enter author: ";
            getline(cin, author);

            cout << "Enter price: ";

            if (!(cin >> price) || price < 0) {
                cout << "Invalid price. Enter a nonnegative number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Book* newBook = new Book(title, author, price);
            store.addBook(newBook);
            break;
        }

        case 2:
            store.displayAll();
            break;

        case 3: {
            int bookNumber;

            store.displayAll();


            cout << "Enter the book number to remove: ";

            if (!(cin >> bookNumber)) {
                cout << "Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            store.removeBook(bookNumber);
            break;
        }

        case 4:
            cout << "Exiting inventory...\n";
            break;

        default:
            cout << "Invalid choice. Choose 1 through 4.\n";
        }

    } while (choice != 4);

    return 0;
}
