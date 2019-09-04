#ifndef _PLACAR_CLASS
#define _PLACAR_CLASS

#include "functions.h"

class placar
{

private:

    // coordenadas do ponto
    int p1, p2;
    GLuint idTexturaBg;
    GLuint idTexturaFonte;

public:

    // constructor
    placar();

    // getters e setters
    void pontua(int player);
    void atualiza();
    void desenhaLetra(int letra, int x, int y, int sizex, int sizey);
};

#endif /*_PLACAR_CLASS*/
