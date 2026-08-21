# C++ Library Management System (OOP)

A lightweight, console-based Library Management System built in C++ to demonstrate core Object-Oriented Programming (OOP) paradigms and manual memory management.

## 🚀 Key Features
* **Catalog Management:** Add polymorphic library items (Books, Magazines).
* **Member Registration:** Manage registered library members.
* **Borrow & Return System:** Tracks availability status and prevents double-issuing.
* **Dynamic Memory Cleanup:** Uses custom destructors to clean up heap-allocated items without memory leaks.

## 🧠 OOP Concepts Implemented
* **Abstraction & Pure Virtual Functions:** `LibraryItem` acts as an abstract base class containing a pure virtual function `displayDetails()`.
* **Polymorphism & Dynamic Binding:** `displayDetails()` is overridden by derived classes (`Book`, `Magazine`) and invoked at runtime via base-class pointers (`LibraryItem*`).
* **Inheritance:** Single inheritance where `Book` and `Magazine` derive from `LibraryItem`.
* **Encapsulation:** Class attributes are marked `private`/`protected` and accessed exclusively through getter/setter methods.
* **Resource Management (RAII):** Custom destructor in `Library` manages memory explicitly with `delete`.

## 🛠️ How to Build and Run

### Prerequisites
* A C++ compiler supporting C++11 or higher (e.g., GCC/g++, Clang, MSVC).

### Execution Steps
1. Clone the repository:
   ```bash
   git clone [https://github.com/YOUR_GITHUB_USERNAME/cpp-oop-library-management.git](https://github.com/YOUR_GITHUB_USERNAME/cpp-oop-library-management.git)
   cd cpp-oop-library-management
