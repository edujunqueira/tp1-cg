#ifndef _RECORDS_CLASS
#define _RECORDS_CLASS

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "record.h"
#include "functions.h"

class records{

private:

    std::ifstream readFile;
    std::ofstream writeFile;
    std::string fileName;
    std::string recordName;
    std::vector<record> holders;

public:

    records();
    void processWin();
    bool processName(unsigned char key);
    void teste();

};

#endif /* _RECORDS_CLASS */
