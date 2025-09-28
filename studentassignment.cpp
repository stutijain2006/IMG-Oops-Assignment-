#pragma once
#include <chrono>
#include "assignment.cpp" 
class student;
class studentassignment {
private:
    student* Student;
    assignment* Assignment;
    int score;
    chrono::system_clock::time_point submissionDate; 
    bool isLate;                                   
public:
 studentassignment(student* submittingStudent, assignment* theAssignment) {
        this->Student = submittingStudent;
        this->Assignment = theAssignment;
        this->score = -1;  this->submissionDate = chrono::system_clock::now();
        this->isLate = theAssignment->isPastDeadline();
}
    student* getStudent() const { return this->Student; }
    assignment* getAssignment() const { return this->Assignment; }
    bool wasSubmittedLate() const { return this->isLate; }
    int getScore() const { return this->score; }
    void setScore(int newScore) { this->score = newScore; }
};

