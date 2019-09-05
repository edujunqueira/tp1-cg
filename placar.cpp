#include "placar.h"

placar::placar(){
    p1 = 0;
    p2 = 0;
    idTexturaBg = carregaTextura("img/bg.png");
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

    desenhaLetra((p1 / 10), 10, -10, 4, 4);
    desenhaLetra((p1 % 10), 18, -10, 4, 4);

    desenhaLetra((p2 / 10), 182, -10, 4, 4);
    desenhaLetra((p2 % 10), 190, -10, 4, 4);
}

void placar::pontua(int player){
    if(player == 1)
        p1++;
    else if (player == 2)
        p2++;
}

// todo void placar::escreveFrase(...)
