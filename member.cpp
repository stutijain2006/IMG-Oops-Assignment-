#include "Role.cpp"


class MemberRole : public role {
public:
  
    bool canAddMembers() const override { return false; }
    bool canRemoveMembers() const override { return false; }
    bool canCreateAssignments() const override { return false; }
    bool canGradeSubmissions() const override { return false; }
};
