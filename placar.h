#ifndef _PLACAR_CLASS
#define _PLACAR_CLASS

#include "functions.h"

class placar
{

private:

    // coordenadas do ponto
    int p1, p2;
    GLuint idTexturaBg;

public:

    // constructor
    placar();

    // getters e setters
    void pontua(int player);
    void atualiza();
};

#endif /*_PLACAR_CLASS*/
