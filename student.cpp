#include <bits/stdc++.h>
#include "Vector.cpp"
#include "membersrole.cpp"
using namespace std;
class student {
private :
string name ;
string rollnum;
string password;
Vector <membersRole*> memberships;
public :
student(const string &name,const string &rollnum,const string &password)
{
    this->name = name;
    this->rollnum = rollnum;
    this->password = password;
   

}
string getname()
{
    return name;
}
string getrollnum()
{
    return rollnum;
};
  void addmembership(membersRole* newMembership) {
        this->memberships.push(newMembership);
    }
};