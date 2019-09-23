#ifndef _PAUSE_CLASS
#define _PAUSE_CLASS

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "record.h"
#include "functions.h"
#include "botao.h"

class pause{

private:

    botao *botaoResume;
    botao *botaoConfig;
    botao *botaoRestart;
    botao *botaoExit;
    botao *botaoSim;
    botao *botaoNao;
    int confirmaAtual;

public:

    pause();
    void atualiza();
    void confirma(int botao);
    void desenhaPopUp();
    void desenhaPause();
    int mouseApertado(int button, int state, int x, int y);
    void mousePassivo(int x, int y);

};

#endif /* _PAUSE_CLASS */
