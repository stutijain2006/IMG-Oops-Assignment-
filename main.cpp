#include <iostream>
#include <string>
#include <limits>
#include "student.h"
#include "club.h"
#include "Vector.cpp"
#include "Role.cpp"
#include "admin.cpp"
#include "member.cpp"
#include "checker.cpp"
#include "selector.cpp"
#include "assignment.cpp"
#include "studentassignment.cpp"
#include "membersrole.cpp"

using namespace std;

void showMenu(student* loggedInStudent, Vector<club*>& allClubs);

Vector<student*> allStudents;
Vector<club*> allClubs;
Vector<membersRole*> allMemberships;
student* currentUser = nullptr;

void handleLogin() {
    string roll, pass;
    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Password: ";
    cin >> pass;

    for (int i = 0; i < allStudents.size(); ++i) {
        student* s = allStudents.get(i);
        if (s->getrollnum() == roll && s->checkPassword(pass)) {
            currentUser = s;
            cout << "\nWelcome, " << currentUser->getname() << endl;
            showMenu(currentUser, allClubs);
            return;
        }
    }
    cout << "Invalid credentials. Please try again." << endl;
}

void handleRegister() {
    string name, roll, pass;
    cout << "Enter Your Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter Your Roll Number: ";
    cin >> roll;
    cout << "Enter Your Password: ";
    cin >> pass;

    student* newStudent = new student(name, roll, pass);
    allStudents.push(newStudent);
    cout << "Registration successful for " << name << endl;
}

void showMenu(student* loggedInStudent, Vector<club*>& allClubs) {
    while (true) {
        cout << "\n--- Student Menu ---" << endl;
        cout << "1. View My Clubs" << endl;
        cout << "2. View All Clubs" << endl;
        cout << "3. Logout" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            continue;
        }

        if (choice == 1) {
            loggedInStudent->viewMyClubs();
        } else if (choice == 2) {
            cout << "\nAll  Clubs:" << endl;
            for (int i = 0; i < allClubs.size(); ++i) {
                cout << " - " << allClubs.get(i)->getname() << endl;
            }
        } else if (choice == 3) {
            currentUser = nullptr;
            cout << "You have been logged out." << endl;
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    student* s1 = new student("umesh soni", "24114102", "img");
    allStudents.push(s1);

    club* c1 = new club("IMG", "my club");
    allClubs.push(c1);

    membersRole* m1 = new membersRole(s1, c1, new AdminRole());
    s1->addmembership(m1);
    c1->addMember(m1);
    allMemberships.push(m1);

    while (true) {
        cout << "\nWelcome" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "what you want ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
    
            continue;
        }

        if (choice == 1) {
            handleLogin();
        } else if (choice == 2) {
            handleRegister();
        } else if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    for (int i = 0; i < allMemberships.size(); ++i) {
        delete allMemberships.get(i);
    }
    for (int i = 0; i < allStudents.size(); ++i) {
        delete allStudents.get(i);
    }
    for (int i = 0; i < allClubs.size(); i++) {
        delete allClubs.get(i);
    }
    return 0;
}