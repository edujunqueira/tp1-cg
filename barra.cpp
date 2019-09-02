#include "barra.h"
#include "functions.h"

#define posmaxx 200
#define posmaxy 100

barra::barra(int usr)
{
    idTexturaBarra = carregaTextura("img/barra.png");
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

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPolygonMode(GL_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaBarra);
    glBegin(GL_TRIANGLE_FAN);
        //desenha uma barra
        glTexCoord2f(0, 0);
        glVertex3f(posicao->getX() - size->getX(), posicao->getY() - size->getY(),  0);

        glTexCoord2f(1, 0);
        glVertex3f(posicao->getX() + size->getX(), posicao->getY() - size->getY(),  0);

        glTexCoord2f(1, 1);
        glVertex3f(posicao->getX() + size->getX(), posicao->getY() + size->getY(),  0);

        glTexCoord2f(0, 1);
        glVertex3f(posicao->getX() - size->getX(), posicao->getY() + size->getY(),  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void barra::mover(int distancia){
    if( (posicao->getY() + size->getY() + distancia) < posmaxy && (posicao->getY() + distancia) > size->getY() )
        posicao->setY(posicao->getY() + distancia);
}
