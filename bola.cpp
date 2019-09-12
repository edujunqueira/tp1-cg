#include "bola.h"

bola::bola(int r)
{
    // gera uma posicao aleatoria para a bola iniciar
    posicao = new ponto(randomPoint(pontoAleatorioX1, pontoAleatorioY1), randomPoint(pontoAleatorioX2, pontoAleatorioY2));
    // gera uma posicao aleatoria para a bola iniciar
    direcao = new ponto(randomPoint( velocidadeInicial, -velocidadeInicial ), randomPoint( velocidadeInicial, -velocidadeInicial ));
    idTexturaBola = carregaTextura("img/ball.png");
    raio = r;
    gol = false;
}

bola::~bola(){}

void bola::reinicia(){
    gol = false;
    // gera uma posicao aleatoria para a bola reiniciar
    posicao->setPonto(randomPoint(pontoAleatorioX1, pontoAleatorioY1), randomPoint(pontoAleatorioX2, pontoAleatorioY2));
    // gera uma direcao aleatoria para a bola reiniciar
    direcao->setPonto(randomPoint( velocidadeInicial, -velocidadeInicial ), randomPoint( velocidadeInicial, -velocidadeInicial ));
}

void bola::desenhaBola(){

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPolygonMode(GL_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaBola);
    glBegin(GL_TRIANGLE_FAN);
        //desenha um quadrado, definindo a textura da bola
        glTexCoord2f( 0, 0 );
        glVertex3f(posicao->getX() - raio, posicao->getY() - raio,  0);

        glTexCoord2f( 1, 0 );
        glVertex3f(posicao->getX() + raio, posicao->getY() - raio,  0);

        glTexCoord2f( 1, 1 );
        glVertex3f(posicao->getX() + raio, posicao->getY() + raio,  0);

        glTexCoord2f( 0, 1 );
        glVertex3f(posicao->getX() - raio, posicao->getY() + raio,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

int bola::checaColisao(int posYP1, int posYP2){
    int ret = 0;

    if(posicao->getX() > pontoAleatorioX1 && posicao->getX() < pontoAleatorioY1 ){
        bloqueio = false;
    }

    if (posicao->getY() >= (sizeTelaJogoY - raio) || (posicao->getY() <= raio)){          // se a bola estiver colidindo com teto ou chao
        direcao->setY(direcao->getY() * -1.0); // muda a direção
    } else if (gol) { // se ja tiver sido gol, espera a bola bater no extremo
        if (posicao->getX() <= 5 || posicao->getX() >= 195){
            if( (posicao->getX() - raio) <= (posPlayer1X + sizeBarraX))
                ret = PLAYER_TWO;
            else
                ret = PLAYER_ONE;
        }
    } else if (
       (((posicao->getX() + raio) >= (posPlayer2X - sizeBarraX)) &&            // a bolinha tem que estar no X da barra 2 ( 180 = posbarra - 5 da barra)
        ((posicao->getY() - raio) <= (posYP2 + sizeBarraY)) &&   // e a direita da bolinha tem que ser menor que a esquerda da barra
        ((posicao->getY() + raio) >= (posYP2 - sizeBarraY)))     // e a esquerda da bolinha tem que ser maior que a direita da barra
    || // barra 1 ou barra 2
       (((posicao->getX() - raio) <= (posPlayer1X + sizeBarraX)) &&            // a bolinha tem que estar no X da barra 1 ( 30 = posbarra + 5 da barra)
        ((posicao->getY() - raio) <= (posYP1 + sizeBarraY)) &&   // e a direita da bolinha tem que ser menor que a esquerda da barra
        ((posicao->getY() + raio) >= (posYP1 - sizeBarraY)))     // e a esquerda da bolinha tem que ser maior que a direita da barra
    ){ // todo a bola passa do Y
    	if(!bloqueio){
            if(fabs(direcao->getX()) >= velocidadeMaxima){
                direcao->setX(-direcao->getX()); // se estiver na velocidadeMaxima, só muda a direção
            } else {
                direcao->setX(direcao->getX() * -aumentoVelocidade); // muda a direção e aumenta a velocidade
                direcao->setY(direcao->getY() * aumentoVelocidade); // aumenta a velocidade
            }
    		bloqueio = true;
    	}
    } else if ( (posicao->getX() - raio) <= (posPlayer1X + sizeBarraX) || (posicao->getX() + raio) >= (posPlayer2X - sizeBarraX) ){
        // se rolar um gol (ou seja, bola passar de uma das barras)
        gol = true; // -> deixa a bola passar, pra ficar mais smooth
    }
    return ret;
}

int bola::movimenta(int posYP1, int posYP2){
    // checha por qualquer colisão
    int ret = this->checaColisao(posYP1, posYP2);
    // se movimenta
    posicao->setX(posicao->getX() + direcao->getX());
    posicao->setY(posicao->getY() + direcao->getY());
    return ret;
}
