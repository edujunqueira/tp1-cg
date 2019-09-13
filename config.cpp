#include "config.h"

config::config()
{
    idTexturaBgConfig = carregaTextura("img/menu-bg.png");
    /*int posx = 100, posy = 7, distancia = 21;
    botaoPlay = new botao("play", posx, posy, 50, 20);
    posy += distancia;
    botaoConfig = new botao("config", posx, posy, 50, 20);
    posy += distancia;
    botaoRecords = new botao("records", posx, posy, 50, 20);
    posy += distancia;
    botaoExit = new botao("exit", posx, posy, 50, 20);*/
}

void config::atualiza()
{
    this->desenhaMenuBg();
    /*
    botaoPlay->desenhaBotao();
    botaoConfig->desenhaBotao();
    botaoRecords->desenhaBotao();
    botaoExit->desenhaBotao();
    */
}

int config::mouseApertado(int button, int state, int x, int y)
{
    int ret = BUTTON_CONFIG_NONE;
    /*if(button == GLUT_LEFT_BUTTON){
        if (botaoPlay->checaClique(state, x, y))
            ret = BUTTON_MENU_PLAY;
        if (botaoConfig->checaClique(state, x, y))
            ret = BUTTON_MENU_CONFIG;
        if (botaoRecords->checaClique(state, x, y))
            ret = BUTTON_MENU_RECORDS;
        if (botaoExit->checaClique(state, x, y))
            ret = BUTTON_MENU_EXIT;
    }*/
    return ret;
}

void config::mousePassivo(int x, int y)
{
    /*botaoPlay->checaHover(x, y);
    botaoConfig->checaHover(x, y);
    botaoRecords->checaHover(x, y);
    botaoExit->checaHover(x, y);*/
}

void config::desenhaConfig()
{
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPolygonMode(GL_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaBgConfig);
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
}