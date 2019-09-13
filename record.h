#ifndef _RECORD_CLASS
#define _RECORD_CLASS

#include "functions.h"

class record{

private:

    std::string name;
    int score;

public:

    record(std::string n, int s){ name = n; score = s; }
    int getScore() const { return score; }
    std::string getName() const { return name; }
    std::string getRecord() { return name + ": " + std::to_string(score);}
    void addScore() { score++; }
};

#endif /* _RECORD_CLASS */
