#include "pause.h"

pause::pause()
{
    int posx = 100, posy = 7, distancia = 21;
    botaoResume = new botao("resume", posx, posy, 50, 20);
    posy += distancia;
    botaoConfig = new botao("config", posx, posy, 50, 20);
    posy += distancia;
    botaoRestart = new botao("restart", posx, posy, 50, 20);
    posy += distancia;
    botaoExit = new botao("exit", posx, posy, 50, 20);

    confirmaAtual = BUTTON_PAUSE_NONE;

    botaoSim = new botao("sim", 85, 40, 20, 10);
    botaoNao = new botao("nao", 115, 40, 20, 10);
}

void pause::confirma(int botao)
{
    confirmaAtual = botao;
}

void pause::atualiza()
{
    this->desenhaPause();
    botaoResume->desenhaBotao();
    botaoConfig->desenhaBotao();
    botaoRestart->desenhaBotao();
    botaoExit->desenhaBotao();

    if(confirmaAtual != BUTTON_PAUSE_NONE){
        this->desenhaPopUp();
        botaoSim->desenhaBotao();
        botaoNao->desenhaBotao();
    }
}

int pause::mouseApertado(int button, int state, int x, int y)
{
    int ret = BUTTON_PAUSE_NONE;
    if(button == GLUT_LEFT_BUTTON){
        if(confirmaAtual == BUTTON_PAUSE_NONE){
            if (botaoResume->checaClique(state, x, y))
                ret = BUTTON_PAUSE_RESUME;
            if (botaoConfig->checaClique(state, x, y))
                ret = BUTTON_PAUSE_CONFIG;
            if (botaoRestart->checaClique(state, x, y))
                ret = BUTTON_PAUSE_RESTART;
            if (botaoExit->checaClique(state, x, y))
                ret = BUTTON_PAUSE_EXIT;
        } else {

            if (botaoSim->checaClique(state, x, y)){
                switch(confirmaAtual){
                    case BUTTON_PAUSE_RESTART:
                        ret = BUTTON_PAUSE_Y_RESTART;
                        break;
                    case BUTTON_PAUSE_EXIT:
                        ret = BUTTON_PAUSE_Y_EXIT;
                        break;
                }
                confirmaAtual = BUTTON_PAUSE_NONE;
            }

            if (botaoNao->checaClique(state, x, y)){
                ret = BUTTON_PAUSE_NO;
                confirmaAtual = BUTTON_PAUSE_NONE;
            }
        }
    }
    return ret;
}

void pause::mousePassivo(int x, int y)
{
    if(confirmaAtual == BUTTON_PAUSE_NONE){
        botaoResume->checaHover(x, y);
        botaoConfig->checaHover(x, y);
        botaoRestart->checaHover(x, y);
        botaoExit->checaHover(x, y);
    } else {
        botaoSim->checaHover(x, y);
        botaoNao->checaHover(x, y);
    }
}

void pause::desenhaPause()
{
    glColor4f(0.0, 0.0, 0.0, 0.5);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, -20, 0);
        glVertex3f(200, -20, 0);
        glVertex3f(200, 100,  0);
        glVertex3f(0, 100, 0);
    glEnd();
}

void pause::desenhaPopUp()
{
    glColor4f(0.5, 0.5, 0.5, 0.8);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(45, 10, 0);
        glVertex3f(155, 10, 0);
        glVertex3f(155, 50,  0);
        glVertex3f(45, 50, 0);
    glEnd();

    if(confirmaAtual == BUTTON_PAUSE_RESTART)
        escreveFrase("reiniciar o jogo?", 100, 25, 3, 3);
    else if (confirmaAtual == BUTTON_PAUSE_EXIT)
        escreveFrase("sair do jogo?", 100, 25, 3, 3);
}
