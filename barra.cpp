#include "barra.h"
#include "functions.h"

barra::barra(int usr)
{
    idTexturaBarra = carregaTextura("img/barra.png");
    // seta o tamanho da barra
    size = new ponto(sizeBarraX, sizeBarraY);
    // seta o usuario
    user = usr;
    if(usr == PLAYER_ONE)       // se for jogador 1, esquerda
        posicao = new ponto(posPlayer1X, posPlayerInicialY);
    else if(usr == PLAYER_TWO)  // se for jogador 2, direita
        posicao = new ponto(posPlayer2X, posPlayerInicialY);
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

void barra::mover(bool up, bool down){
    if(down)
        if( (posicao->getY() + size->getY() + velocidadeBarra) < sizeTelaJogoY && (posicao->getY() + velocidadeBarra) > size->getY() )
            posicao->setY(posicao->getY() + velocidadeBarra);

    if(up)
        if( (posicao->getY() + size->getY() - velocidadeBarra) < sizeTelaJogoY && (posicao->getY() - velocidadeBarra) > size->getY() )
            posicao->setY(posicao->getY() - velocidadeBarra);
}
