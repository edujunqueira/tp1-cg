#include "barra.h"
#include "bola.h"
#include "menu.h"
#include "placar.h"


int gameState = STATE_MENU;
int gol;
// cria o vetor de caracteres
bool keys[4]; // 0 = w, 1 = s, 2 = up, 3 = down

// cria o menu
menu* mainMenu = nullptr;

// cria a variavel global ball
bola* ball = nullptr;

// cria as variaveis globais dos usuarios
barra* user1 = nullptr;
barra* user2 = nullptr;

// cria o placar
placar* cenario = nullptr;


void desenhaCena()
{
    glClear(GL_COLOR_BUFFER_BIT);


    if(gameState == STATE_MENU){

        mainMenu->inicia();

    } else if(gameState == STATE_PLAY){ // se o jogo estiver rolando

        cenario->atualiza();

        ball->desenhaBola();
        user1->desenhaBarra();
        user2->desenhaBarra();

    } else if(gameState == STATE_PAUSE){

    }

	glutSwapBuffers();
}

void atualizaCena(int periodo)
{
    if(gameState == STATE_PLAY){
        // faz a bola se movimentar
        gol = ball->movimenta(user1->getPosY(), user2->getPosY());

        if(gol != PLAYER_NONE){
            cenario->pontua(gol);
            ball->reinicia();
            // gol!
        }

        // faz com que as barras se movam
        user1->mover(keys[LEFT_UP], keys[LEFT_DOWN]);
        user2->mover(keys[RIGHT_UP], keys[RIGHT_DOWN]);
    }
    // gera o fps
    glutPostRedisplay();
    glutTimerFunc(33, atualizaCena, 0);
}

void setup()
{
    inicializaTextura();
    // define users
    user1 = new barra(PLAYER_ONE);
    user2 = new barra(PLAYER_TWO);
    // define ball
    ball = new bola(raioBola);
    // define cenario
    cenario = new placar();
    // define menu
    mainMenu = new menu();

    // define qual é a cor do fundo
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void redimensionada(int width, int height)
{
   // left, bottom, right, top
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, sizeTelaJogoX, sizeTelaJogoY, -scoreboardHeight, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'g':
        gameState = STATE_PLAY;
        break;
    case 'm':
        gameState = STATE_MENU;
        break;
    case 'w':
        keys[LEFT_UP] = true;
        break;
    case 's':
        keys[LEFT_DOWN] = true;
        break;
    case 27:      // Tecla "ESC"
        exit(0);
        break;
    default:
        break;
    }
}

void flechaPressionada(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        keys[RIGHT_UP] = true;
        break;
    case GLUT_KEY_DOWN:
        keys[RIGHT_DOWN] = true;
        break;
    default:
        break;
    }
}

void teclaSolta(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'w':
        keys[LEFT_UP] = false;
        break;
    case 's':
        keys[LEFT_DOWN] = false;
        break;
    default:
        break;
    }
}

void flechaSolta(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        keys[RIGHT_UP] = false;
        break;
    case GLUT_KEY_DOWN:
        keys[RIGHT_DOWN] = false;
        break;
    default:
        break;
    }
}

// Função principal
int main(int argc, char** argv)
{
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize(sizeTelaJogoX * 3, sizeTelaJogoY * 3 + scoreboardHeight * 3);
   glutInitWindowPosition(500, 25);

   glutCreateWindow("Ping-Pongho");

   glutSetKeyRepeat(0); // seta que segurar uma tecla não a faz repetir
   // Registra callbacks para eventos
   glutDisplayFunc(desenhaCena);
   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);
   glutSpecialFunc(flechaPressionada);
   glutKeyboardUpFunc(teclaSolta);
   glutSpecialUpFunc(flechaSolta);
   glutTimerFunc(0, atualizaCena, 33);

   setup();

   glutMainLoop();
   return 0;
}
