#pragma once
#include "role.cpp"

// AdminRole "is-a" Role. It inherits from the Role class.
class AdminRole : public role {
public:
    
    bool canAddMembers() const override { return true; }
    bool canRemoveMembers() const override { return true; }
    bool canCreateAssignments() const override { return true; }
    bool canGradeSubmissions() const override { return true; }
};
