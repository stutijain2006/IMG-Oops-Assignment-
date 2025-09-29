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
        bool hasAdminRole = false;
        Vector <membersRole*> myMemberships = loggedInStudent->getMemberships();
        for (int i=0; i< myMemberships.size(); i++){
            if (myMemberships[i]->getRole()->canAddMembers()){
                hasAdminRole=true;
                break;
            }
        }
        if (hasAdminRole) cout << "3. Club Admin Panel"<< endl;
        cout << "9. Logout" << endl;
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
        }
            else if (choice == 3) {
                cout<< "\nEnter the name of the club you want to access: " << endl;
                Vector<membersRole*> myMemberships = loggedInStudent->getMemberships();
                int adminCount=0;
                for (int i=0; i< myMemberships.size(); i++){
                    if (myMemberships[i]->getRole()->canAddMembers()){
                        adminCount++;
                        cout<< " ["<<adminCount<<"]" << myMemberships[i]->getClub()->getname() << endl;
                    }
                }
                if (adminCount==0){
                    cout<< "You are not an admin of any club." << endl;
                    continue;
                }
                cout <<"Enter choice: ";
                int c;
                cin >> c;
                if (cin.fail() || c < 1 || c > adminCount) {
                    cout << "Invalid input. Please enter a valid number." << endl;
                    cin.clear();
                    continue;
                }
                cout << "\n--- Club Admin Panel ---" << endl;
                cout << "1. Add Member" << endl;
                cout << "2. Remove Member" << endl;
                cout << "3. Create Assignment" << endl;
                cout << "4. View All Assignments" << endl;
                cout << "5. Extend Assignment Deadline" << endl;
                cout <<"6. View all Members" << endl;

                int adminChoice;
                cin >> adminChoice;

                membersRole* selectedAdminMembership= myMemberships[c-1];
                club* selectedClub = selectedAdminMembership->getClub();

                if (adminChoice ==1){
                    cout << "Enter the roll number of the student to add: ";
                    string rollToAdd;
                    cin >> rollToAdd;
                    student* studentToAdd = nullptr;
                    for (int i = 0; i < allStudents.size(); ++i) {
                        if (allStudents.get(i)->getrollnum() == rollToAdd) {
                            studentToAdd = allStudents.get(i);
                            break;
                        }
                    }
                    if (!studentToAdd) {
                        cout << "Student with roll number " << rollToAdd << " not found." << endl;
                        continue;
                    }
                    else {
                        membersRole* newMembership = new membersRole(studentToAdd, selectedClub, new MemberRole());
                        selectedClub->addMember(newMembership);
                        studentToAdd->addmembership(newMembership);
                        cout << "Member added successfully." << endl;
                    }
                }
                else if (adminChoice ==2){
                    cout << "Enter the roll number of the student to remove: ";
                    string rollToRemove;
                    cin >> rollToRemove;
                    student* studentToRemove = nullptr;
                    for (int i = 0; i < allStudents.size(); ++i) {
                        if (allStudents.get(i)->getrollnum() == rollToRemove) {
                            studentToRemove = allStudents.get(i);
                            break;
                        }
                    }
                    if (!studentToRemove) {
                        cout << "Student with roll number " << rollToRemove << " not found." << endl;
                        continue;
                    }
                    else {
                        selectedClub->removeMember(studentToRemove, selectedAdminMembership);
                    }
                }
                else if (adminChoice == 3) {
                    string title;
                    int maxScore, secondsUntilDue;
                    cout << "Enter Assignment Title: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, title);
                    cout << "Enter Maximum Score: ";
                    cin >> maxScore;
                    cout << "Enter Time Until Due (in seconds): ";
                    cin >> secondsUntilDue;
                    selectedClub->createAssignment(title, maxScore, secondsUntilDue, selectedAdminMembership);
                } 
                else if (adminChoice == 4) {
                    selectedClub->viewAllAssignments();
                }
                else if (adminChoice == 5) {
                    selectedClub->viewAllAssignments();
                    cout << "Enter the assignment number to extend its deadline: ";
                    int assignmentIndex;
                    cin >> assignmentIndex;
                    cout << "Enter additional time (in seconds) to extend: ";
                    int additionalSeconds;
                    cin >> additionalSeconds;
                    selectedClub->extendAssignmentDeadline(assignmentIndex, additionalSeconds, selectedAdminMembership);
                }
                else if (adminChoice == 6) {
                    selectedClub->listAllMembers();
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
         
            else if (choice == 9) {
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