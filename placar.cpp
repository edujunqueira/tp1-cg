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

    glColor4f(0.0, 0.0, 0.0, 1.0);
    escreve(GLUT_BITMAP_HELVETICA_18, std::to_string(p1).c_str(), 20, -20);
    escreve(GLUT_BITMAP_HELVETICA_18, std::to_string(p2).c_str(), 180, -20);
}

void placar::pontua(int player){
    if(player == 1)
        p1++;
    else if (player == 2)
        p2++;
}
