#include "functions.h"

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

int randomPoint(int x, int y){
    int ret;
    srand(time(NULL));
    if(x == 1 || y == 1){
        ret = rand() % 2;
        if(ret == 0)
            ret = -1;
    }else
        ret = (rand() % (y-x)) + x;

    return ret;
}

void escreve(void* fonte, const char* texto, float x, float y) {
  glRasterPos2f(x, y);

  for (int i = 0; i < strlen(texto); i++) {
     glutBitmapCharacter(fonte, texto[i]);
  }
}
