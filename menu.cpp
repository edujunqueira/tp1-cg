#include "menu.h"

menu::menu()
{
    idTexturaBgMenu = carregaTextura("img/menu-bg.png");
}

void menu::inicia()
{
    this->desenhaMenuBg();
    escreveFrase("press 'g' to play", 100, 40, 3, 3);
}

void menu::desenhaMenuBg()
{
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPolygonMode(GL_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaBgMenu);
    glBegin(GL_TRIANGLE_FAN);

        glTexCoord2f(0, 0);
        glVertex3f(0, -scoreboardHeight, 0);

        glTexCoord2f(1, 0);
        glVertex3f(sizeTelaJogoX, -scoreboardHeight, 0);

        glTexCoord2f(1, 1);
        glVertex3f(sizeTelaJogoX, sizeTelaJogoY,  0);

        glTexCoord2f(0, 1);
        glVertex3f(0, sizeTelaJogoY, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor4f(0.0, 0.0, 0.0, 0.5);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(50, 0, 0);
        glVertex3f(150, 0, 0);
        glVertex3f(150, 80,  0);
        glVertex3f(50, 80, 0);
    glEnd();
}
