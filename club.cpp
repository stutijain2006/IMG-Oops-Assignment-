#include <bits/stdc++.h>

#include "vector.cpp"
using namespace std;

class club {
private : 
    string name ;
    string about;
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

};