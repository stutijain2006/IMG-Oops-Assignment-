#pragma once
#include <bits/stdc++.h>
#include <chrono>
class club;
using namespace std;
class assignment {
private:
    string title;
    int maxScore;
    club* issuingClub;
    chrono::system_clock::time_point deadline;
public:
    assignment(const string& initialTitle, int initialMaxScore, club* creator, const chrono::system_clock::time_point& due) {
        this->title = initialTitle;
        this->maxScore = initialMaxScore;
        this->issuingClub = creator;
        this->deadline = due;
    }
    string gettitle() const {
        return this->title;
    }

    int getmaxScore() const {
        return this->maxScore;
    }
    chrono::system_clock::time_point getDeadline() const {
        return this->deadline;
    }
    club* getIssuingClub() const {
        return this->issuingClub;
    }
    bool isPastDeadline() const {
        return chrono::system_clock::now() > this->deadline;
    }
    void extendDeadline(int additionalSeconds) {
        this->deadline += chrono::seconds(additionalSeconds);
    }
};

