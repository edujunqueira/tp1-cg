#ifndef _PLACAR_CLASS
#define _PLACAR_CLASS

#include "functions.h"

class placar
{

private:

    // coordenadas do ponto
    int pontos[3];
    int sets[3];
    bool vantagem[3];
    GLuint idTexturaBg;
    GLuint idTexturaVantagem;

public:

    // constructor
    placar();

    // getters e setters
    void reiniciaPontos();
    int pontua(int player); // retorna se um jogador ganhou a partida nesse ponto
    int getPontos(int player);
    void atualiza();
};

#endif /*_PLACAR_CLASS*/
