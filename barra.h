#ifndef _BARRA_CLASS
#define _BARRA_CLASS

#include "ponto.h"

class barra{

private:

    ponto *posicao;
    ponto *size;
    int user;

public:

    barra(int usr);
    int getPosY(){return posicao->getY();};
    void desenhaBarra();
    void mover(int dist);
};

#endif /* _BARRA_CLASS */
