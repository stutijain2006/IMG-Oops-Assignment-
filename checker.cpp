#pragma once
#include "role.cpp"


class AssignmentCheckerRole : public role {
public:

    bool canAddMembers() const override { return false; }
    bool canRemoveMembers() const override { return false; }
    bool canCreateAssignments() const override { return true; }
    bool canGradeSubmissions() const override { return true; }
};
