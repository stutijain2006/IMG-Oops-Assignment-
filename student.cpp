#include <bits/stdc++.h>
using namespace std;
class student {
private :
string name ;
string rollnum;
string password;
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
};