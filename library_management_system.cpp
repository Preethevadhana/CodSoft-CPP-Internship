#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available;
};

vector<Book> library;

void addBook() {
    Book b;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    cout << "Enter ISBN: ";
    getline(cin, b.isbn);

    b.available = true;

    library.push_back(b);

    cout << "Book added successfully!\n";
}

void viewBooks() {
    if (library.empty()) {
        cout << "No books available.\n";
        return;
    }

    cout << "\n===== BOOK LIST =====\n";

    for (int i = 0; i < library.size(); i++) {
        cout << "\nBook " << i + 1 << endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "ISBN: " << library[i].isbn << endl;
        cout << "Status: "
             << (library[i].available ? "Available" : "Issued")
             << endl;
    }
}

void searchBook() {
    string searchTitle;

    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, searchTitle);

    bool found = false;

    for (auto &book : library) {
        if (book.title == searchTitle) {
            cout << "\nBook Found!\n";
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.isbn << endl;
            cout << "Status: "
                 << (book.available ? "Available" : "Issued")
                 << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Book not found.\n";
}

void issueBook() {
    string isbn;

    cin.ignore();
    cout << "Enter ISBN of book to issue: ";
    getline(cin, isbn);

    for (auto &book : library) {
        if (book.isbn == isbn) {
            if (book.available) {
                book.available = false;
                cout << "Book issued successfully!\n";
            } else {
                cout << "Book is already issued.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void returnBook() {
    string isbn;

    cin.ignore();
    cout << "Enter ISBN of book to return: ";
    getline(cin, isbn);

    for (auto &book : library) {
        if (book.isbn == isbn) {
            if (!book.available) {
                book.available = true;

                int daysLate;
                cout << "Enter number of overdue days: ";
                cin >> daysLate;

                if (daysLate > 0) {
                    int fine = daysLate * 5;
                    cout << "Fine = Rs. " << fine << endl;
                } else {
                    cout << "No fine.\n";
                }

                cout << "Book returned successfully!\n";
            } else {
                cout << "Book was not issued.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}