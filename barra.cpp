#include <GL/glew.h>
#include <GL/freeglut.h>

#include "barra.h"

#define posmaxx 200
#define posmaxy 100

barra::barra(int usr)
{
    // seta o tamanho da barra
    size = new ponto(5, 20);
    // seta o usuario
    user = usr;
    if(usr == 1) // se for jogador 1, em cima
        posicao = new ponto(15, 50);
    else          // se for jogador 2, em baixo
        posicao = new ponto(185, 50);
}

void barra::desenhaBarra(){

    glColor3f(1, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        //desenha uma barra
        glVertex3f(posicao->getX() - size->getX(), posicao->getY() - size->getY(),  0);

        glVertex3f(posicao->getX() + size->getX(), posicao->getY() - size->getY(),  0);

        glVertex3f(posicao->getX() + size->getX(), posicao->getY() + size->getY(),  0);

        glVertex3f(posicao->getX() - size->getX(), posicao->getY() + size->getY(),  0);
    glEnd();
}

void barra::mover(int distancia){
    if( (posicao->getY() + size->getY() + distancia) < posmaxy && (posicao->getY() + distancia) > size->getY() )
        posicao->setY(posicao->getY() + distancia);
}
