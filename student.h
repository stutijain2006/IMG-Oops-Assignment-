#pragma once
#include <bits/stdc++.h>
#include "Vector.cpp"
class membersRole;
class studentassignment;
class assignment;
class club;
using namespace std;
class student {
private:
    string name;
    string rollnum;
    string password;
    Vector<membersRole*> memberships;
    Vector<studentassignment*> submissions;
public:
    student(const string& name, const string& rollnum, const string& password);
    string getname() const;
    string getrollnum() const;
    bool checkPassword(const string& attempt) const;
    void addmembership(membersRole* newMembership);
    void viewMyClubs() const;
    void submitAssignment(assignment* theAssignment);
};
