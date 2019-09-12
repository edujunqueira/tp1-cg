#include "barra.h"
#include "bola.h"
#include "menu.h"
#include "placar.h"
#include "records.h"

int gWidth, gHeight;
int gameState = GS_MENU;
int scorer;
int scoreResult = SCORE_NONE;
std::string scorerName;

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

// cria a interface de records
records* record = nullptr;

void desenhaCena()
{
    glClear(GL_COLOR_BUFFER_BIT);


    if(gameState == GS_MENU){

        mainMenu->atualiza();

    } else if(gameState == GS_PLAY || gameState == GS_RECORDS){ // se o jogo estiver rolando

        cenario->atualiza();
        ball->desenhaBola();
        user1->desenhaBarra();
        user2->desenhaBarra();

    } else if(gameState == GS_PAUSE){

        // pause

    }

	glutSwapBuffers();
}

void atualizaCena(int periodo)
{
    if(gameState == GS_PLAY){
        // faz a bola se movimentar
        scorer = ball->movimenta(user1->getPosY(), user2->getPosY());

        if(scorer != PLAYER_NONE){
            scoreResult = cenario->pontua(scorer);
            ball->reinicia();
            // gol!
        }

        if(scoreResult >= WIN_PLAYER_ONE){
            gameState = GS_RECORDS;
            //cenario->askPlayerName();
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
    //define records
    record = new records();
    // define qual é a cor do fundo
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void passaMouse(int x, int y)
{
    if(gameState == GS_MENU){
        float myX, myY;
        myX = (x / (float) gWidth) * sizeTelaJogoX;
        myY = (y / (float) gHeight) * (sizeTelaJogoY + scoreboardHeight) - scoreboardHeight;
        mainMenu->mousePassivo( myX, myY);
    }
}

void apertaMouse(int button, int state, int x, int y)
{
    if(gameState == GS_MENU){
        float myX, myY;
        myX = (x / (float) gWidth) * sizeTelaJogoX;
        myY = (y / (float) gHeight) * (sizeTelaJogoY + scoreboardHeight) - scoreboardHeight;

        switch(mainMenu->mouseApertado(button, state, myX, myY)){
            case(BUTTON_MENU_NONE):
                break;
            case(BUTTON_MENU_PLAY):
                gameState = GS_PLAY;
                break;
            case(BUTTON_MENU_EXIT):
                exit(0);
                break;
            default:
                break;
        }
    }
}

void redimensionada(int width, int height)
{
   // left, bottom, right, top
   glViewport(0, 0, width, height);
   gWidth = width;
   gHeight = height;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, sizeTelaJogoX, sizeTelaJogoY, -scoreboardHeight, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y)
{
    if(gameState == GS_RECORDS){
        // se estiver na tela de setar os recordes, pede para o usuário digitar seu nome, para adcionar aos recordes
        if(record->processName(key))
            gameState = GS_MENU;
        // só sai dessa tela quando o usuário apertar ESC (para cancelar) ou preencher os 5 dígitos
    }

    switch(key)
    {
    case 'p':
        if(gameState == GS_PLAY)
            gameState = GS_PAUSE;
        else if (gameState == GS_PAUSE)
            gameState = GS_PLAY;
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
   glutMouseFunc(apertaMouse);
   glutPassiveMotionFunc(passaMouse);

   setup();

   glutMainLoop();
   return 0;
}
