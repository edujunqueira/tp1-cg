#ifndef _MENU_CLASS
#define _MENU_CLASS

#include "functions.h"
#include "botao.h"

class menu{

private:

    GLuint idTexturaBgMenu;
    botao *botaoPlay;
    botao *botaoConfig;
    botao *botaoRecords;
    botao *botaoExit;

public:

    menu();
    void inicia();
    void desenhaMenuBg();
    int mouseApertado(int button, int state, int x, int y);
    void mousePassivo(int x, int y);

};

#endif /* _MENU_CLASS */
