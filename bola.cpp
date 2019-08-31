#include <SOIL/SOIL.h>
#include <stdio.h>

#include "bola.h"

#define posmaxx 100
#define posmaxy 200

GLuint carregaTextura(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

bola::bola(int r)
{
    posicao = new ponto(20, 33);
    direcao = new ponto( 1,  1);
    idTexturaBola = carregaTextura("ball.png");
    raio = r;
}

bola::~bola(){}

void bola::reinicia(){
    posicao->setPonto(20, 33);
    direcao->setPonto( 1,  1);
}

void bola::desenhaBola(){
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaBola);
    glBegin(GL_TRIANGLE_FAN);
        //desenha um quadrado, definindo a textura da bola
        glTexCoord2f(0, 0);
        glVertex3f(posicao->getX() - raio, posicao->getY() - raio,  0);

        glTexCoord2f(1, 0);
        glVertex3f(posicao->getX() + raio, posicao->getY() - raio,  0);

        glTexCoord2f(1, 1);
        glVertex3f(posicao->getX() + raio, posicao->getY() + raio,  0);

        glTexCoord2f(0, 1);
        glVertex3f(posicao->getX() - raio, posicao->getY() + raio,  0);
    glEnd();
}

void bola::checaColisao(int posx1, int posx2){
    if (posicao->getY() >= (posmaxy - raio) || posicao->getY() <= raio){                // se rolar um gol (ou seja, bola colidindo com o teto ou o chão)
        printf("Gol!");
        // reinicia a posição da bola
        this->reinicia();
    } else if (posicao->getX() >= (posmaxx - raio) || (posicao->getX() <= raio)){        // se a bola estiver colidindo com algum dos lados
        direcao->setX(direcao->getX() * -1.0); // muda a direção
    } else if (
       (((posicao->getY() + raio) >= 180) &&            // a bolinha tem que estar no Y da barra 2
        ((posicao->getX() + raio) <= (posx2 + 20)) &&   // e a direita da bolinha tem que ser menor que a esquerda da barra
        ((posicao->getX() - raio) >= (posx2 - 20)))     // e a esquerda da bolinha tem que ser maior que a direita da barra
    || // barra 1 ou barra 2
       (((posicao->getY() + raio) <= 30) &&            // a bolinha tem que estar no Y da barra 1
        ((posicao->getX() + raio) <= (posx1 + 20)) &&   // e a direita da bolinha tem que ser menor que a esquerda da barra
        ((posicao->getX() - raio) >= (posx1 - 20)))     // e a esquerda da bolinha tem que ser maior que a direita da barra
    ){ // todo a bola passa do Y
        direcao->setY(direcao->getY() * -1.1); // muda a direção e aumenta a velocidade
    }
}

void bola::movimenta(int posx1, int posx2){
    // checha por qualquer colisão
    this->checaColisao(posx1, posx2);
    // se movimenta
    posicao->setX(posicao->getX() + direcao->getX());
    posicao->setY(posicao->getY() + direcao->getY());
}
