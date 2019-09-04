#include "placar.h"

placar::placar(){
    p1 = 0;
    p2 = 0;
    idTexturaBg = carregaTextura("img/bg.png");
    idTexturaFonte = carregaTextura("img/font.png");
}

void placar::atualiza(){

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaBg);
    glBegin(GL_TRIANGLE_FAN);
        //desenha uma barra
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

    this->desenhaLetra((p1 / 10), 10, -20, 4, 4);
    this->desenhaLetra((p1 % 10), 18, -20, 4, 4);

    this->desenhaLetra((p2 / 10), 182, -20, 4, 4);
    this->desenhaLetra((p2 % 10), 190, -20, 4, 4);
}

void placar::pontua(int player){
    if(player == 1)
        p1++;
    else if (player == 2)
        p2++;
}

void placar::desenhaLetra(int letra, int x, int y, int sizex, int sizey){
    float calcx, calcy, calcx2, calcy2;

    calcx = (1.0 / 9.0 * (letra % 9));
    calcy = (1.0 / 5.0 * (letra / 9));
    calcx2 = (1.0 / 9.0 * (letra % 9 + 1));
    calcy2 = (1.0 / 5.0 * (letra / 9 + 1));

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaFonte);
    glBegin(GL_TRIANGLE_FAN);

        glTexCoord2f(calcx , calcy);
        glVertex3f(x - sizex, y - sizey,  0);

        glTexCoord2f(calcx2, calcy);
        glVertex3f(x + sizex, y - sizey,  0);

        glTexCoord2f(calcx2, calcy2);
        glVertex3f(x + sizex, y + sizey,  0);

        glTexCoord2f(calcx , calcy2);
        glVertex3f(x - sizex, y + sizey,  0);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

// todo void placar::escreveFrase(...)
