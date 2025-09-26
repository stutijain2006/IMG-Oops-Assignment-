#include <bits/stdc++.h>
#include "membersrole.cpp"
#include "vector.cpp"

using namespace std;

class club {
private : 
    string name ;
    string about;
    Vector <membersRole*> members;
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

};