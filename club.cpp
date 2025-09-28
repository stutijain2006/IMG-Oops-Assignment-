
#include "club.h"
#include "student.h" 
#include "membersrole.cpp"
#include "assignment.cpp"
#include "Role.cpp" 
club::club(const string& name, const string& about) {
    this->name = name;
    this->about = about;
}
string club::getname() const {
    return this->name;
}
void club::addMember(membersRole* newMember) {
    this->members.push(newMember);
}
void club::listAllMembers() const {
    cout << "\nMembers of " << this->name << ":" << endl;
    if (this->members.size() == 0) {
        cout << "  - This club has no members yet." << endl;
        return;
    }
    for (int i = 0; i < this->members.size(); ++i) {

        membersRole* currentMembership = this->members.get(i);

        student* currentStudent = currentMembership->getStudent();
        cout << "  - " << currentStudent->getname() << endl;
    }
}

void club::createAssignment(const string& title, int maxScore, int secondsUntilDue, membersRole* creator) {
    if (creator->getRole()->canCreateAssignments()) {
        cout << "Permission granted. Creating assignment..." << endl;
        auto deadline = chrono::system_clock::now() + chrono::seconds(secondsUntilDue);
        assignment* newAssignment = new assignment(title, maxScore, this, deadline);
        this->assignments.push(newAssignment);
    } else {
        cout << "Permission denied. You do not have the rights to create assignments." << endl;
    }
}

void club::viewAllAssignments() const {
    cout << "\nAssignments for " << this->name << ":" << endl;
    if (this->assignments.size() == 0) {
        cout << "  - No assignments have been created for this club." << endl;
        return;
    }
    cout << "Please select an assignment by its number:" << endl;
    for (int i = 0; i < this->assignments.size(); i++) {
        cout << "  " << i << ": " << this->assignments.get(i)->gettitle() << endl;
    }
}
assignment* club::getAssignment(int index) {
    if (index >= 0 && index < this->assignments.size()) {
        return this->assignments.get(index);
    }
    cout << "Error: Invalid assignment number." << endl;
    return nullptr; 
}