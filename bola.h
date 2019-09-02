#ifndef _BOLA_CLASS
#define _BOLA_CLASS

#include "functions.h"
#include "ponto.h"

class bola{

private:

    // posicao atual da bola
    ponto *posicao;
    // direcao e velocidade que a bola está indo
    ponto *direcao;
    // textura da bola
    GLuint idTexturaBola;
    // raio da bola
    int raio;

public:

    // constructor e desconstructor
    bola(int r);
    ~bola();
    // funcionalidades da bola
    void desenhaBola();
    int checaColisao(int posx1, int posx2);
    int movimenta(int posx1, int posx2);
    void reinicia();

};

/*glBegin(GL_LINE_LOOP);
    for(int i = 1; i <= 36; i++)
        glVertex3f(posicaoBola.x + 5 * cos(10*(i*M_PI/180)), posicaoBola.y + 5 * sin(10*(i*M_PI/180)), 0.0);
glEnd();*/

#endif /* _BOLA_CLASS */
