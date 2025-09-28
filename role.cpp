#pragma once
class role {
public:
    virtual ~role() {}
    virtual bool canAddMembers() const = 0;
    virtual bool canRemoveMembers() const = 0;
    virtual bool canCreateAssignments() const = 0;
    virtual bool canGradeSubmissions() const = 0;
};
