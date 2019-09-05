#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

GLuint carregaTextura(const char* arquivo);
void inicializaTextura();
int randomPoint(int x, int y);
//void escreve(void* fonte, const char* texto, float x, float y);
void desenhaLetra(int letra, int x, int y, int sizex, int sizey);
void escreveFrase(std::string str, int x, int y, int sizex, int sizey);

enum GAME_STATE {
        STATE_MENU,
        STATE_PLAY,
        STATE_PAUSE,
        STATE_GOAL,
        STATE_RESTART
};

enum PLAYERS {
    PLAYER_NONE,
    PLAYER_ONE,
    PLAYER_TWO
};

enum DIR_KEYS {
    LEFT_UP,
    LEFT_DOWN,
    RIGHT_UP,
    RIGHT_DOWN
};

enum FONT {
    FONT_0,
    FONT_1,
    FONT_2,
    FONT_3,
    FONT_4,
    FONT_5,
    FONT_6,
    FONT_7,
    FONT_8,
    FONT_9,
    FONT_A,
    FONT_B,
    FONT_C,
    FONT_D,
    FONT_E,
    FONT_F,
    FONT_G,
    FONT_H,
    FONT_I,
    FONT_J,
    FONT_K,
    FONT_L,
    FONT_M,
    FONT_N,
    FONT_O,
    FONT_P,
    FONT_Q,
    FONT_R,
    FONT_S,
    FONT_T,
    FONT_U,
    FONT_V,
    FONT_W,
    FONT_X,
    FONT_Y,
    FONT_Z,
    FONT_TRACO,
    FONT_ASPASDUPLA,
    FONT_ASPAS,
    FONT_UNDERLINE,
    FONT_PONTO,
    FONT_INTERROGACAO,
    FONT_EXCLAMACAO,
    FONT_CHAPEU,
    FONT_NONE
};

// gerais
#define sizeTelaJogoX 200
#define sizeTelaJogoY 100
#define scoreboardHeight 20

// bola
#define raioBola 5
#define aumentoVelocidade 1.1
#define pontoAleatorioX1 80
#define pontoAleatorioX2 20
#define pontoAleatorioY1 120
#define pontoAleatorioY2 80

// barras
#define sizeBarraX 5
#define sizeBarraY 20
#define posPlayer1X 15
#define posPlayer2X 185
#define posPlayerInicialY 50
#define velocidadeBarra 2

#endif /* _FUNCTIONS_H */
