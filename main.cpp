#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1. Abstract Base Class (Abstraction & Polymorphism)
class LibraryItem {
protected:
    int id;
    string title;
    bool isBorrowed;

public:
    LibraryItem(int id, string title) {
        this->id = id;
        this->title = title;
        this->isBorrowed = false;
    }

    virtual ~LibraryItem() {} // Virtual destructor for dynamic memory cleanup

    int getId() const { return id; }
    string getTitle() const { return title; }
    bool getBorrowedStatus() const { return isBorrowed; }

    void borrowItem() { isBorrowed = true; }
    void returnItem() { isBorrowed = false; }

    // Pure Virtual Function
    virtual void displayDetails() const = 0;
};

// 2. Derived Class: Book (Single Inheritance)
class Book : public LibraryItem {
private:
    string author;

public:
    Book(int id, string title, string author) : LibraryItem(id, title) {
        this->author = author;
    }

    void displayDetails() const override {
        cout << "[BOOK] ID: " << id << " | Title: " << title 
             << " | Author: " << author 
             << " | Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

// 3. Derived Class: Magazine (Single Inheritance)
class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(int id, string title, int issue) : LibraryItem(id, title) {
        this->issueNumber = issue;
    }

    void displayDetails() const override {
        cout << "[MAGAZINE] ID: " << id << " | Title: " << title 
             << " | Issue #: " << issueNumber 
             << " | Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

// 4. Member Class (Encapsulation)
class Member {
private:
    int memberId;
    string name;

public:
    Member(int id, string name) {
        this->memberId = id;
        this->name = name;
    }

    int getMemberId() const { return memberId; }
    string getName() const { return name; }
};

// 5. Library Management System Class
class Library {
private:
    vector<LibraryItem*> items;
    vector<Member> members;

public:
    ~Library() {
        // Dynamic memory cleanup
        for (LibraryItem* item : items) {
            delete item;
        }
    }

    void addItem(LibraryItem* item) {
        items.push_back(item);
        cout << "Item added successfully!" << endl;
    }

    void registerMember(int id, string name) {
        members.push_back(Member(id, name));
        cout << "Member registered: " << name << endl;
    }

    void showCatalog() const {
        cout << "\n--- LIBRARY CATALOG ---" << endl;
        if (items.empty()) {
            cout << "No items in library." << endl;
            return;
        }
        for (const auto& item : items) {
            item->displayDetails(); // Dynamic Binding / Polymorphism
        }
        cout << "-----------------------" << endl;
    }

    void issueItem(int itemId) {
        for (auto& item : items) {
            if (item->getId() == itemId) {
                if (!item->getBorrowedStatus()) {
                    item->borrowItem();
                    cout << "Successfully issued: " << item->getTitle() << endl;
                } else {
                    cout << "Sorry, this item is already borrowed." << endl;
                }
                return;
            }
        }
        cout << "Item ID not found!" << endl;
    }

    void returnItem(int itemId) {
        for (auto& item : items) {
            if (item->getId() == itemId) {
                if (item->getBorrowedStatus()) {
                    item->returnItem();
                    cout << "Successfully returned: " << item->getTitle() << endl;
                } else {
                    cout << "This item was not borrowed." << endl;
                }
                return;
            }
        }
        cout << "Item ID not found!" << endl;
    }
};

// Main Function
int main() {
    Library lib;

    // Adding Items (Polymorphic dynamic allocation)
    lib.addItem(new Book(101, "The C++ Programming Language", "Bjarne Stroustrup"));
    lib.addItem(new Book(102, "Clean Code", "Robert C. Martin"));
    lib.addItem(new Magazine(201, "Tech Monthly", 45));

    // Registering Members
    lib.registerMember(1, "Aman");

    // Display Initial Catalog
    lib.showCatalog();

    // Issue a book
    cout << "\nIssuing Item 101..." << endl;
    lib.issueItem(101);

    // Display updated catalog
    lib.showCatalog();

    // Return the book
    cout << "\nReturning Item 101..." << endl;
    lib.returnItem(101);

    // Final Catalog
    lib.showCatalog();

    return 0;
}