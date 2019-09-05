#ifndef _BARRA_CLASS
#define _BARRA_CLASS

#include "functions.h"
#include "ponto.h"

class barra{

private:

    ponto *posicao;
    ponto *size;
    int user;
    // textura da barra
    GLuint idTexturaBarra;

public:

    barra(int usr);
    int getPosY(){return posicao->getY();};
    void desenhaBarra();
    void mover(bool up, bool down);
};

#endif /* _BARRA_CLASS */
