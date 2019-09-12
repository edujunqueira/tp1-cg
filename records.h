#ifndef _RECORDS_CLASS
#define _RECORDS_CLASS

#include <fstream>

#include "functions.h"

class records{

private:

    std::ofstream recordsFile;
    std::string fileName;
    std::string recordName;

public:

    records();
    void processWin();
    bool processName(unsigned char key);

};

#endif /* _RECORDS_CLASS */
