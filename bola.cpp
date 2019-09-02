#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bola.h"

#define posmaxx 200
#define posmaxy 100

int randomPoint(int x, int y){
    int ret;
    srand(time(NULL));
    if(x == 1 || y == 1){
        ret = rand() % 2;
        if(ret == 0)
            ret = -1;
    }else
        ret = (rand() % (y-x)) + x;

    return ret;
}

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
    posicao = new ponto(randomPoint(80, 120), randomPoint(20, 80)); // gera uma posicao aleatoria para a bola iniciar
    direcao = new ponto(randomPoint( 1,  -1), randomPoint( 1, -1)); // gera uma direcao aleatoria para a bola iniciar
    idTexturaBola = carregaTextura("ball.png");
    raio = r;
}

bola::~bola(){}

void bola::reinicia(){
    posicao->setPonto(randomPoint(80, 120), randomPoint(20, 80)); // gera uma posicao aleatoria para a bola reiniciar
    direcao->setPonto(randomPoint( 1,  -1), randomPoint( 1, -1)); // gera uma direcao aleatoria para a bola reiniciar
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

    if (posicao->getY() >= (posmaxy - raio) || (posicao->getY() <= raio)){          // se a bola estiver colidindo com teto ou chao
        direcao->setY(direcao->getY() * -1.0); // muda a direção
    } else if (
       (((posicao->getX() + raio) >= 180) &&            // a bolinha tem que estar no X da barra 2 ( 180 = posbarra - 5 da barra)
        ((posicao->getY() - raio) <= (posx2 + 20)) &&   // e a direita da bolinha tem que ser menor que a esquerda da barra
        ((posicao->getY() + raio) >= (posx2 - 20)))     // e a esquerda da bolinha tem que ser maior que a direita da barra
    || // barra 1 ou barra 2
       (((posicao->getX() + raio) <= 30) &&            // a bolinha tem que estar no X da barra 1 ( 30 = posbarra + 5 da barra)
        ((posicao->getY() - raio) <= (posx1 + 20)) &&   // e a direita da bolinha tem que ser menor que a esquerda da barra
        ((posicao->getY() + raio) >= (posx1 - 20)))     // e a esquerda da bolinha tem que ser maior que a direita da barra
    ){ // todo a bola passa do Y
        direcao->setX(direcao->getX() * -1.1); // muda a direção e aumenta a velocidade
    } else if ( (posicao->getX() + raio) <= 30 || (posicao->getX() + raio) >= 180 ){    // se rolar um gol (ou seja, bola colidindo com um dos lados)
        printf("Gol!");
        // reinicia a posição da bola
        this->reinicia();
    }

}

void bola::movimenta(int posx1, int posx2){
    // checha por qualquer colisão
    this->checaColisao(posx1, posx2);
    // se movimenta
    posicao->setX(posicao->getX() + direcao->getX());
    posicao->setY(posicao->getY() + direcao->getY());
}
