#include "functions.h"

GLuint idTexturaFonte;

GLuint carregaTextura(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0)
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());

    return idTextura;
}

void inicializaTextura(){
    idTexturaFonte = carregaTextura("img/font.png");
}

int randomPoint(int x, int y){
    int ret;
    srand(time(NULL));
    if(x == velocidadeInicial || y == velocidadeInicial){
        ret = rand() % 2;
        if(ret == 0)
            ret = -velocidadeInicial;
        else
            ret = velocidadeInicial;
    }else
        ret = (rand() % (y-x)) + x;

    return ret;
}

/*void escreve(void* fonte, const char* texto, float x, float y) {
  glRasterPos2f(x, y);

  for (int i = 0; i < strlen(texto); i++) {
     glutBitmapCharacter(fonte, texto[i]);
  }
}*/

void desenhaLetra(int letra, int x, int y, int sizex, int sizey){
    float calcx, calcy, calcx2, calcy2;

    calcx = (1.0 / 9.0 * (letra % 9));
    calcy = (1.0 / 5.0 * (letra / 9));
    calcx2 = (1.0 / 9.0 * (letra % 9 + 1));
    calcy2 = (1.0 / 5.0 * (letra / 9 + 1));

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT, GL_FILL);
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
    glBindTexture(GL_TEXTURE_2D, 0);
}

void escreveFrase(std::string str, int x, int y, int sizex, int sizey)
{
    if (str.length() % 2 == 0)
        x += 3;

    x -= (str.length() / 2) * sizex * 2;

    for(char& letra : str) {
        if(letra >= 48 && letra <= 57){
            letra -= 48;
        } else if (letra >= 97 && letra <= 122){
            letra -= 87;
        } else if (letra == 33){
            letra = FONT_EXCLAMACAO;
        } else if (letra == ' '){
            letra = FONT_NONE;
        } else if (letra == 34){
            letra = FONT_ASPASDUPLA;
        } else if (letra == 39){
            letra = FONT_ASPAS;
        } else if (letra == 46){
            letra = FONT_PONTO;
        } else if (letra == 63){
            letra = FONT_INTERROGACAO;
        }

        desenhaLetra(letra, x, y, sizex, sizey);
        x += 2 * sizex;
    }
}

void escreveFraseInicio(std::string str, int x, int y, int sizex, int sizey)
{

    for(char& letra : str) {
        if(letra >= 48 && letra <= 57){
            letra -= 48;
        } else if (letra >= 97 && letra <= 122){
            letra -= 87;
        } else if (letra == 33){
            letra = FONT_EXCLAMACAO;
        } else if (letra == ' '){
            letra = FONT_NONE;
        } else if (letra == 34){
            letra = FONT_ASPASDUPLA;
        } else if (letra == 39){
            letra = FONT_ASPAS;
        } else if (letra == 46){
            letra = FONT_PONTO;
        } else if (letra == 63){
            letra = FONT_INTERROGACAO;
        }

        desenhaLetra(letra, x, y, sizex, sizey);
        x += 2 * sizex;
    }
}
