#include "config.h"

config::config()
{
    idTexturaBgConfig = carregaTextura("img/menu-bg.png");
    botaoBack = new botao("voltar", 20, 0, 20, 20);
    backToGame = false;
}

void config::atualiza()
{
    this->desenhaConfig();
    botaoBack->desenhaBotao();
}

int config::mouseApertado(int button, int state, int x, int y)
{
    if (botaoBack->checaClique(state, x, y)){
        if(backToGame)
            return BUTTON_CONFIG_BACK_TO_GAME;
        else
            return BUTTON_CONFIG_BACK;
    }

    return BUTTON_CONFIG_NONE;
}

void config::mousePassivo(int x, int y)
{
    botaoBack->checaHover(x, y);
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

    escreveFraseInicio("velocidade inicial", 20, 20, 2, 2);
    escreveFrase(std::to_string(velocidadeInicial), 180, 20, 2, 2);
    escreveFraseInicio("aumento de velocidade", 20, 40, 2, 2);
    escreveFrase(std::to_string(aumentoVelocidade), 180, 40, 2, 2);
    escreveFraseInicio("pontos para ganhar", 20, 60, 2, 2);
    escreveFrase(std::to_string(pointsToWin), 180, 60, 2, 2);
    escreveFraseInicio("sets para ganhar", 20, 80, 2, 2);
    escreveFrase(std::to_string(setsToWin), 180, 80, 2, 2);
}
