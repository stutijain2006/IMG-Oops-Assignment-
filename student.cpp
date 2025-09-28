
#include "student.h"
#include "club.h" 
#include "membersrole.cpp"
#include "assignment.cpp"
#include "studentassignment.cpp"
student::student(const string& name, const string& rollnum, const string& password) {
    this->name = name;
    this->rollnum = rollnum;
    this->password = password;
}
string student::getname() const {
    return this->name;
}
string student::getrollnum() const {
    return this->rollnum;
}
bool student::checkPassword(const string& attempt) const {
    return this->password == attempt;
}

void student::addmembership(membersRole* newMembership) {
    this->memberships.push(newMembership);
}
void student::viewMyClubs() const {
    cout << "\nClubs for " << this->name << ":" << endl;
    if (this->memberships.size() == 0) {
        cout << "  - You are not a member of any clubs yet." << endl;
        return;
    }
    for (int i = 0; i < this->memberships.size(); ++i) {
        membersRole* currentMembership = this->memberships.get(i);
        club* associatedClub = currentMembership->getClub();
        cout << "  - " << associatedClub->getname() << endl;
    }
}
void student::submitAssignment(assignment* theAssignment) {
    if (theAssignment == nullptr) {
        cout << "Error: Cannot submit a null assignment." << endl;
        return;
    }
    cout << this->name << " is submitting assignment: " << theAssignment->gettitle() << endl;
    studentassignment* newSubmission = new studentassignment(this, theAssignment);
    this->submissions.push(newSubmission);
}