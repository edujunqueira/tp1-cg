#ifndef _CONFIG_CLASS
#define _CONFIG_CLASS

#include "functions.h"
#include "botao.h"

class config{

private:

    GLuint idTexturaBgConfig;
    /*
    botao *botaoPlay;
    botao *botaoConfig;
    botao *botaoRecords;
    botao *botaoExit;
    */

public:

    config();
    void inicia();
    void desenhaConfig();
    int mouseApertado(int button, int state, int x, int y);
    void mousePassivo(int x, int y);

};

#endif /* _MENU_CLASS */
