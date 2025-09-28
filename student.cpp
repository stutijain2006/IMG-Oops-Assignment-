#include <bits/stdc++.h>
#include "Vector.cpp"
#include "membersrole.cpp"
#include "club.cpp"
#include "studentassignment.cpp"
#include "assignment.cpp"
using namespace std;
class student {
private :
string name ;
string rollnum;
string password;
Vector <membersRole*> memberships;
Vector<studentassignment*> submissions;
public :
student(const string &name,const string &rollnum,const string &password)
{
    this->name = name;
    this->rollnum = rollnum;
    this->password = password;
}
string getname(){
    return name;
}
string getrollnum(){
    return rollnum;
};
void addmembership(membersRole* newMembership) {
        this->memberships.push(newMembership);
    }
void viewMyClubs() const {
        cout << "Clubs for " << this->name << ":" << endl;
        if (this->memberships.size() == 0) {
            cout << "  - Not a member of any clubs." << endl;
            return;
        }

        
        for (int i = 0; i < this->memberships.size(); ++i) {
            
            membersRole* currentMembership = this->memberships.get(i);
    
            club* associatedClub = currentMembership->getClub();
    
            cout << "  - " << associatedClub->getname() << endl;
        }
    }
    void submitAssignment(assignment* theAssignment) {
        cout << this->name << " is submitting assignment: " << theAssignment->gettitle() << endl;
        studentassignment* newSubmission = new studentassignment(this, theAssignment);
        this->submissions.push(newSubmission);
    }
};