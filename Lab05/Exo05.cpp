/****************************************************************************
 In the laboratory equipment lending scene, there are three main objects: Student, Equipment, and Laboratory. 
 A Student represents a student who borrows equipment, and name is the student's name. An Equipment object represents one item, and each item can be borrowed by at most one Student at a time. 
 In other words, when the input contains BORROW i name, the name field is the name of the student who tries to borrow equipment i. If the borrowing succeeds, equipment i is currently borrowed by that Student. 
 A Laboratory object represents the whole lending system and manages whether each equipment item is currently in the lab or has been borrowed by some student.
The rules are as follows. Initially, all equipment items are in the laboratory and available. BORROW i name means that the student whose name is name tries to borrow equipment i. 
If the equipment is available, the borrowing succeeds, and then equipment i should be regarded as currently borrowed by student name. If the equipment has already been borrowed, nothing changes. RETURN i means returning equipment i. If the return succeeds, the item goes back to the laboratory and no borrower remains. If the equipment was already in the lab, nothing changes. 
STATUS i reports the state of one equipment item, including whether it is available or currently borrowed by which student. SUMMARY reports the total numbers of borrowed and available items.
You must solve this problem using object-oriented programming. At minimum, use classes to describe Student, Equipment, and Laboratory, and let Equipment or Laboratory handle BORROW, RETURN, STATUS, and SUMMARY through member functions. Do not write the whole solution using only scattered variables and ordinary functions.
Output one line for each operation.
For BORROW, output Equipment i borrowed by name if the item is borrowed successfully, or Equipment i is unavailable if the item is not available.
For RETURN, output Equipment i returned if the item is returned successfully, or Equipment i is already in lab if it was already in the lab.
For STATUS, output either Equipment i: available or Equipment i: name.
For SUMMARY, output Borrowed: X, Available: Y.
Sample Input 
3 8
SUMMARY
BORROW 1 Amy
BORROW 2 Bob
STATUS 1
RETURN 1
STATUS 1
BORROW 2 Carl
SUMMARY
Sample Output 
Borrowed: 0, Available: 3
Equipment 1 borrowed by Amy
Equipment 2 borrowed by Bob
Equipment 1: Amy
Equipment 1 returned
Equipment 1: available
Equipment 2 is unavailable
Borrowed: 1, Available: 2
Source
 **********************************************************************/


#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    explicit Student(const std::string& n) : name(n) {}
};

class Equipment {
    int id;
    bool borrowed;
    std::string borrower;

public:
    explicit Equipment(int i) : id(i), borrowed(false) {}

    void borrow(const std::string& name) {
        if (borrowed) { std::cout << "Equipment " << id << " is unavailable\n"; return; }
        borrowed = true;
        borrower = name;
        std::cout << "Equipment " << id << " borrowed by " << name << "\n";
    }

    void return_() {
        if (!borrowed) { std::cout << "Equipment " << id << " is already in lab\n"; return; }
        borrowed = false;
        borrower.clear();
        std::cout << "Equipment " << id << " returned\n";
    }

    void status() const {
        if (!borrowed) std::cout << "Equipment " << id << ": available\n";
        else           std::cout << "Equipment " << id << ": " << borrower << "\n";
    }

    bool isBorrowed() const { return borrowed; }
};

class Laboratory {
    std::vector<Equipment> items;

public:
    explicit Laboratory(int E) {
        for (int i = 1; i <= E; ++i) items.emplace_back(i);
    }

    void borrow(int i, const std::string& name) { items[i-1].borrow(name); }
    void return_(int i)                         { items[i-1].return_(); }
    void statusOne(int i)                       { items[i-1].status(); }

    void summary() const {
        int borrowed = 0;
        for (auto& e : items) if (e.isBorrowed()) ++borrowed;
        std::cout << "Borrowed: " << borrowed
                  << ", Available: " << (int)items.size() - borrowed << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int E, Q; std::cin >> E >> Q;
    Laboratory lab(E);

    for (int i = 0; i < Q; ++i) {
        std::string op; std::cin >> op;
        if      (op == "BORROW") { int idx; std::string n; std::cin >> idx >> n; lab.borrow(idx, n); }
        else if (op == "RETURN") { int idx; std::cin >> idx; lab.return_(idx); }
        else if (op == "STATUS") { int idx; std::cin >> idx; lab.statusOne(idx); }
        else                     { lab.summary(); }
    }
    return 0;
}