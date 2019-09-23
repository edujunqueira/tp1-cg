#ifndef _CONFIG_CLASS
#define _CONFIG_CLASS

#include "functions.h"
#include "botao.h"

class config{

private:

    botao *botaoBack;
    GLuint idTexturaBgConfig;
    bool backToGame;

    /*
    botao *botaoPlay;
    botao *botaoConfig;
    botao *botaoRecords;
    botao *botaoExit;
    */

public:

    config();
    void atualiza();
    void desenhaConfig();
    int mouseApertado(int button, int state, int x, int y);
    void mousePassivo(int x, int y);
    void toGame(bool game) { backToGame = game; }

};

#endif /* _MENU_CLASS */
