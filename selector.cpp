#pragma once
#include "role.cpp"


class StudentSelectorRole : public role {
public:
  
    bool canAddMembers() const override { return true; }
    bool canRemoveMembers() const override { return true; }
    bool canCreateAssignments() const override { return false; }
    bool canGradeSubmissions() const override { return false; }
};
