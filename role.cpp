#include <bits/stdc++.h>
using namespace std;
class role {
  virtual ~role() {}

    
    virtual bool canAddMembers() const = 0;
    virtual bool canRemoveMembers() const = 0;
    virtual bool canCreateAssignments() const = 0;
    virtual bool canGradeSubmissions() const = 0;
}
;