#ifndef _BOTAO_CLASS
#define _BOTAO_CLASS

#include "functions.h"
#include "ponto.h"

class botao{

private:

    GLuint idTexturaBotao;
    std::string texto;
    ponto *pos;
    ponto *size;
    bool hover;
    int estado;

public:

    botao(std::string text, float x, float y, int sizex, int sizey);
    void desenhaBotao();
    bool checaClique(int state, int x, int y);
    void checaHover(int x, int y);

};

#endif /* _BOTAO_CLASS */
