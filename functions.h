#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cmath>

GLuint carregaTextura(const char* arquivo);
void inicializaTextura();
int randomPoint(int x, int y);
//void escreve(void* fonte, const char* texto, float x, float y);
void desenhaLetra(int letra, int x, int y, int sizex, int sizey);
void escreveFrase(std::string str, int x, int y, int sizex, int sizey);
void escreveFraseInicio(std::string str, int x, int y, int sizex, int sizey);
void popRegisterWin();

enum GAME_STATE {
    GS_MENU,
    GS_PLAY,
    GS_PAUSE,
    GS_RECORDS,
    GS_RECORDS_SCREEN,
    GS_CONFIG
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

enum POINT_RESULT {
    SCORE_NONE,
    SCORE_PLAYER_ONE,
    SCORE_PLAYER_TWO,
    SET_PLAYER_ONE,
    SET_PLAYER_TWO,
    WIN_PLAYER_ONE,
    WIN_PLAYER_TWO
};

enum BUTTON_STATE {
    BUTTON_NORMAL,
    BUTTON_HOVERED,
    BUTTON_CLICKED,
    BUTTON_BLOCKED
};

enum MENU_BUTTONS {
    BUTTON_MENU_NONE,
    BUTTON_MENU_PLAY,
    BUTTON_MENU_CONFIG,
    BUTTON_MENU_RECORDS,
    BUTTON_MENU_EXIT
};

enum PAUSE_BUTTONS {
    BUTTON_PAUSE_NONE,
    BUTTON_PAUSE_RESUME,
    BUTTON_PAUSE_CONFIG,
    BUTTON_PAUSE_RESTART,
    BUTTON_PAUSE_EXIT,
    BUTTON_PAUSE_YES,
    BUTTON_PAUSE_NO,
    BUTTON_PAUSE_Y_RESTART,
    BUTTON_PAUSE_Y_EXIT
};

enum RECORDS_BUTTONS {
    BUTTON_RECORDS_NONE,
    BUTTON_RECORDS_BACK
};

enum CONFIG_BUTTONS {
    BUTTON_CONFIG_NONE,
    BUTTON_CONFIG_BACK,
    BUTTON_CONFIG_BACK_TO_GAME
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

// placar

#define pointsToWin 2
#define setsToWin 2

// bola
#define raioBola 5
#define velocidadeInicial 2
#define velocidadeMaxima 3
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
