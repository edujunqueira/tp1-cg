#include "placar.h"

placar::placar(){
    pontos[PLAYER_ONE] = 0;
    pontos[PLAYER_TWO] = 0;
    sets[PLAYER_ONE] = 0;
    sets[PLAYER_TWO] = 0;
    vantagem[PLAYER_ONE] = false;
    vantagem[PLAYER_TWO] = false;
    idTexturaBg = carregaTextura("img/bg.png");
    idTexturaVantagem = carregaTextura("img/vantagem.png");
}

void placar::reiniciaPontos(){
    pontos[PLAYER_ONE] = 0;
    pontos[PLAYER_TWO] = 0;
    vantagem[PLAYER_ONE] = false;
    vantagem[PLAYER_TWO] = false;
}

int placar::pontua(int player){ // retorna se um jogador ganhou a partida nesse ponto
    int ret = player;
    if(pontos[PLAYER_ONE] == (pointsToWin-1) && pontos[PLAYER_TWO] == (pointsToWin-1) ){ // vai a 2
        int outroPlayer = player == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
        if(vantagem[player]){
            pontos[player]++;
        } else if (vantagem[outroPlayer]){
            vantagem[outroPlayer] = false;
        } else {
            vantagem[player] = true;
        }
    } else { // ponto normal
        pontos[player]++;
    }

    // vitoria
    if(pontos[player] == pointsToWin){
        sets[player]++;
        ret = player == PLAYER_ONE ? SET_PLAYER_ONE : SET_PLAYER_TWO;
        if(sets[player] == setsToWin){
            ret = player == PLAYER_ONE ? WIN_PLAYER_ONE : WIN_PLAYER_TWO;
            // win the match
        }
        this->reiniciaPontos();
    }

    return ret;
}

int placar::getPontos(int player){
    return pontos[player];
}

void placar::atualiza(){

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaBg);
    glBegin(GL_TRIANGLE_FAN);

        glTexCoord2f(0, 0);
        glVertex3f(  0,   0,  0);

        glTexCoord2f(1, 0);
        glVertex3f(200,   0,  0);

        glTexCoord2f(1, 1);
        glVertex3f(200, 100,  0);

        glTexCoord2f(0, 1);
        glVertex3f(  0, 100,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaVantagem);

    if(vantagem[PLAYER_ONE]){
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);
            glVertex3f(25, -15,  0);

            glTexCoord2f(1, 0);
            glVertex3f(35, -15,  0);

            glTexCoord2f(1, 1);
            glVertex3f(35, -5,  0);

            glTexCoord2f(0, 1);
            glVertex3f(25, -5,  0);
        glEnd();
    } else if (vantagem[PLAYER_TWO]) {
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);
            glVertex3f(165, -15,  0);

            glTexCoord2f(1, 0);
            glVertex3f(175, -15,  0);

            glTexCoord2f(1, 1);
            glVertex3f(175, -5,  0);

            glTexCoord2f(0, 1);
            glVertex3f(165, -5,  0);
        glEnd();
    }

    desenhaLetra(sets[PLAYER_ONE], 35, -10, 3, 3);
    desenhaLetra((pontos[PLAYER_ONE] / 10), 10, -5, 4, 4);
    desenhaLetra((pontos[PLAYER_ONE] % 10), 18, -5, 4, 4);

    desenhaLetra(sets[PLAYER_TWO], 165, -10, 3, 3);
    desenhaLetra((pontos[PLAYER_TWO] / 10), 182, -5, 4, 4);
    desenhaLetra((pontos[PLAYER_TWO] % 10), 190, -5, 4, 4);
}
