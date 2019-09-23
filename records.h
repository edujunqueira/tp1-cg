#ifndef _RECORDS_CLASS
#define _RECORDS_CLASS

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "record.h"
#include "functions.h"
#include "botao.h"

class records{

private:

    botao *botaoBack;
    GLuint idTexturaBgMenu;
    std::ifstream readFile;
    std::ofstream writeFile;
    std::string fileName;
    std::string recordName;
    std::vector<record> holders;

public:

    records();
    void atualizaTela();
    void desenhaTela();
    void processWin();
    bool processName(unsigned char key);
    void desenhaPopUp(int scorer);
    void escreveRecords();
    void atualizaRecords();
    int mouseApertado(int button, int state, int x, int y);
    void mousePassivo(int x, int y);

};

#endif /* _RECORDS_CLASS */
