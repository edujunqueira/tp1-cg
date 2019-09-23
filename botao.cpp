#include "botao.h"

botao::botao(std::string text, float x, float y, int sizex, int sizey)
{
    texto = text;
    pos = new ponto(x, y);
    size = new ponto(sizex, sizey);
    estado = BUTTON_NORMAL;

    if(text == "voltar"){
        idTexturaBotao = carregaTextura("img/back.png");
        texto = "";
    } else
        idTexturaBotao = carregaTextura("img/botao.png");
}

bool botao::checaClique(int state, int x, int y)
{
    if(
        x >= (pos->getX() - size->getX()/2) &&
        x <= (pos->getX() + size->getX()/2) &&
        y >= (pos->getY() - size->getY()/2) &&
        y <= (pos->getY() + size->getY()/2)
    ){
        if(state == GLUT_DOWN){
            // se estiver na posição do botão atual, e apertar, muda o estado para clicado
            estado = BUTTON_CLICKED;
        }
    }

    if (state == GLUT_UP && estado == BUTTON_CLICKED){
        // se estiver apertado, e soltar, volta para o estado normal
        estado = BUTTON_NORMAL;
        if(
            x >= (pos->getX() - size->getX()/2) && x <= (pos->getX() + size->getX()/2) &&
            y >= (pos->getY() - size->getY()/2) && y <= (pos->getY() + size->getY()/2)
        ){
            // mas, se ainda estiver no botão, retorna true, e executa as funções do botão
            return true;
        }
    }

    return false;
}

void botao::checaHover(int x, int y)
{
    if(
        x >= (pos->getX() - size->getX()/2) &&
        x <= (pos->getX() + size->getX()/2) &&
        y >= (pos->getY() - size->getY()/2) &&
        y <= (pos->getY() + size->getY()/2)
    )
        estado = BUTTON_HOVERED;
    else
        if(estado != BUTTON_CLICKED)
            estado = BUTTON_NORMAL;

}

void botao::desenhaBotao()
{
    float x1 = estado * 0.25, x2 = (estado + 1) * 0.25; // recorta o estado desejado, entre os 4
    glPushMatrix();
        glTranslatef(pos->getX(), pos->getY(), 0.0);
        glColor4f(1.0, 1.0, 1.0, 1.0);
        glPolygonMode(GL_BACK, GL_FILL);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTexturaBotao);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(x1, 0);
            glVertex3f(-(size->getX()/2), -(size->getY()/2), 0);

            glTexCoord2f(x2, 0);
            glVertex3f(size->getX()/2, -(size->getY()/2), 0);

            glTexCoord2f(x2, 1);
            glVertex3f(size->getX()/2, size->getY()/2,  0);

            glTexCoord2f(x1, 1);
            glVertex3f(-(size->getX()/2), size->getY()/2, 0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        escreveFrase(texto, 0, 0, 3, 3);
    glPopMatrix();
}
