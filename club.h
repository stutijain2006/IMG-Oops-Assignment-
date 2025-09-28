#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include "Vector.cpp"
class membersRole;
class assignment;

using namespace std;

class club {
private:
    string name;
    string about;
    Vector<membersRole*> members;
    Vector<assignment*> assignments;

public:
    club(const string& name, const string& about);
    string getname() const;
    void addMember(membersRole* newMember);
    void listAllMembers() const;
    void createAssignment(const string& title, int maxScore, int secondsUntilDue, membersRole* creator);
    void viewAllAssignments() const;
    assignment* getAssignment(int index);
};
