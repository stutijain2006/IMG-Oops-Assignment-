#include <bits/stdc++.h>
#include <chrono> 
#include "Vector.cpp"
#include "membersrole.cpp"
#include "student.cpp"
#include "assignment.cpp"
using namespace std;

class club {
private : 
    string name ;
    string about;
    Vector <membersRole*> members;
    Vector<assignment*> assignments;
public :
    club(const string &name,const string &about)
    {
        this->name = name;
        this->about = about;
    }
    string getname()
    {
        return name;
    }
    string getabout()
    {
        return about;
    }
    void addMember(membersRole* newMember) {
        this->members.push(newMember);
        cout << "LOG: New member added to " << this->name << endl;
    }
    void listAlMembers() const {
    cout << "Member of" << this->clubName << ":" << endl;
        if (this->members.size() == 0) {
            cout << "  - No members " << endl;
            return;
        }
        for (int i = 0; i < this->members.size(); ++i) {
            cout << "  - " << this->members.get(i)->getStudent()->getname() << endl;
        }
    }
    void createAssignment(const string& title, int maxScore, int secondsUntilDue, membersrole* creator) {
        if (creator->getRole()->canCreateAssignments()) {
            cout << "Permission GRANTED. Creating assignment." << endl;
            auto deadline = chrono::system_clock::now() + chrono::seconds(secondsUntilDue);
            assignment* newAssignment = new assignment(title, maxScore, this, deadline);
            this->assignments.push(newAssignment);
        } else {
            cout << "Permission DENIED. You cannot create assignments." << endl;
        }
    }


};