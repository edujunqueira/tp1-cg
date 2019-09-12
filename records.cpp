#include "records.h"

records::records()
{
    fileName = "records.txt";
    recordName = "";
}

void records::processWin()
{
    recordsFile.open (fileName);
    recordsFile << recordName + "\n";
    recordsFile.close();
    recordName = "";
}

bool records::processName(unsigned char key) // return true = acabou, false = continua
{
    if(key == 27) // tecla esc
        return true;

    recordName += key;

    if(recordName.length() >= 5){
        this->processWin();
        return true;
    }

    return false;
}
