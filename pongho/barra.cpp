#include <GL/glew.h>
#include <GL/freeglut.h>

#include "barra.h"

barra::barra(int usr)
{
    // seta o tamanho da barra
    size = new ponto(20, 5);
    // seta o usuario
    user = usr;
    if(usr == 1) // se for jogador 1, em cima
        posicao = new ponto(50, 15);
    else          // se for jogador 2, em baixo
        posicao = new ponto(50, 185);
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
    posicao->setX(posicao->getX() + distancia);
}
