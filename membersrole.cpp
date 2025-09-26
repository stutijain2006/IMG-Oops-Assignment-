#include <bits/stdc++.h>
using namespace std;
#include <role.cpp>;
class student ;
class club ;
class membersRole {
private:
    student* Student;
    club* Club;
    role* Role;
   
public:
    membersRole(student* relatedStudent, club* relatedClub, role* assignedRole) {
        this->Student = relatedStudent;
        this->Club = relatedClub;
        this->Role = assignedRole;
    };
   
    

    student* getStudent() const { return this->Student; }
    club* getClub() const { return this->Club; }
    role* getRole() const { return this->Role; }
};
