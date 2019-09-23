#include "barra.h"
#include "bola.h"
#include "config.h"
#include "menu.h"
#include "pause.h"
#include "placar.h"
#include "records.h"

int gWidth, gHeight;
int gameState = GS_MENU;
int scorer;
int scoreResult = SCORE_NONE;

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

// cria a interface de pause
pause* pauseMenu = nullptr;

config* configMenu = nullptr;

void desenhaCena() // funcao responsavel por desenhar o jogo, no estado determinado atual
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ele desenha o jogo com base na maquina de estados

    if(gameState == GS_MENU){ // se estiver no menu principal

        mainMenu->atualiza();

    } else if(gameState == GS_PLAY || gameState == GS_RECORDS || gameState == GS_PAUSE){ // se estiver na tela de jogo

        cenario->atualiza();
        ball->desenhaBola();
        user1->desenhaBarra();
        user2->desenhaBarra();

        if(gameState ==  GS_RECORDS){ // popup de inserir recorde
            record->desenhaPopUp(scorer);
        }

        if(gameState ==  GS_PAUSE){ // popup de pause
            pauseMenu->atualiza();
        }

    } else if(gameState == GS_RECORDS_SCREEN){ // se estiver na tela de ver os records

        record->atualizaTela();

    } else if(gameState == GS_CONFIG){

        configMenu->atualiza();

    }

	glutSwapBuffers();
}

void atualizaCena(int periodo) // funcao responsavel por atualizar o jogo com base no fps
{
    // atualiza a cena de jogo, porem somente faz o jogo rolar se estiver no estado de play, se nao so manda redisplay

    if(gameState == GS_PLAY){
        // faz a bola se movimentar
        scorer = ball->movimenta(user1->getPosY(), user2->getPosY());

        if(scorer != PLAYER_NONE){ // se for gol
            scoreResult = cenario->pontua(scorer); // informa o placar quem foi o goleador
            ball->reinicia(); // reinicia a posição da bola
        }

        if(scoreResult >= WIN_PLAYER_ONE){ // se o placar informar que há vencedor da partida
            gameState = GS_RECORDS; // muda para a tela de recordes
            scoreResult = SCORE_NONE; // reseta o goleador
        }
        // faz com que as barras se movam
        user1->mover(keys[LEFT_UP], keys[LEFT_DOWN]);
        user2->mover(keys[RIGHT_UP], keys[RIGHT_DOWN]);
    }
    // gera o fps
    glutPostRedisplay();
    glutTimerFunc(33, atualizaCena, 0);
}

void setup() // inicializa diversas coisas, como os objetos e texturas
{
    inicializaTextura();

    user1 = new barra(PLAYER_ONE); // define users
    user2 = new barra(PLAYER_TWO);
    ball = new bola(raioBola); // define a bola do jogo
    cenario = new placar(); // define o cenario e placar
    mainMenu = new menu(); // define o menu principal do jogo
    record = new records(); // define a interface de recordes
    pauseMenu = new pause(); // define a interface de pause
    configMenu = new config();

    glClearColor(1.0, 1.0, 1.0, 0.0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void reiniciaJogo() // funcao para reinicar a partida atual
{
    ball->reinicia();
    cenario->reiniciaPontos();
    cenario->reiniciaSets();
}

void passaMouse(int x, int y) // funcao para receber o movimento do mouse; usada para verificar o hover do mouse sobre botoes
{
    float myX, myY;
    myX = (x / (float) gWidth) * sizeTelaJogoX;
    myY = (y / (float) gHeight) * (sizeTelaJogoY + scoreboardHeight) - scoreboardHeight;
    if(gameState == GS_MENU){
        mainMenu->mousePassivo( myX, myY);
    } else if(gameState == GS_RECORDS_SCREEN) {
        record->mousePassivo( myX, myY);
    } else if(gameState == GS_CONFIG) {
        configMenu->mousePassivo( myX, myY);
    } else if(gameState == GS_PAUSE) {
        pauseMenu->mousePassivo( myX, myY);
    }
}

void apertaMouse(int button, int state, int x, int y) // funcao para receber o clique do mouse; usada para verificar o clique sobre botoes
{
    float myX, myY;
    myX = (x / (float) gWidth) * sizeTelaJogoX;
    myY = (y / (float) gHeight) * (sizeTelaJogoY + scoreboardHeight) - scoreboardHeight;

    // aqui se checa se algum botao esta sendo apertado
    // se estiver, ele faz a sua funcao dependendo de qual foi apertado e qual o estado atual do jogo

    if(gameState == GS_MENU){

        switch(mainMenu->mouseApertado(button, state, myX, myY)){
            case(BUTTON_MENU_NONE):
                break;
            case(BUTTON_MENU_PLAY):
                gameState = GS_PLAY;
                break;
            case(BUTTON_MENU_CONFIG):
                gameState = GS_CONFIG;
                configMenu->toGame(false);
                break;
            case(BUTTON_MENU_RECORDS):
                record->atualizaRecords();
                gameState = GS_RECORDS_SCREEN;
                break;
            case(BUTTON_MENU_EXIT):
                exit(0);
                break;
            default:
                break;
        }
    } else if(gameState == GS_RECORDS_SCREEN) {

        if(record->mouseApertado(button, state, myX, myY) == BUTTON_RECORDS_BACK)
            gameState = GS_MENU;

    } else if(gameState == GS_CONFIG) {

        switch(configMenu->mouseApertado(button, state, myX, myY)) {
            case(BUTTON_CONFIG_NONE):
                break;
            case(BUTTON_CONFIG_BACK_TO_GAME):
                gameState = GS_PAUSE;
                break;
            case(BUTTON_CONFIG_BACK):
                gameState = GS_MENU;
                break;
        }

    } else if(gameState == GS_PAUSE){

        switch(pauseMenu->mouseApertado(button, state, myX, myY)){
            case(BUTTON_PAUSE_NONE):
                break;
            case(BUTTON_PAUSE_RESUME):
                gameState = GS_PLAY;
                break;
            case(BUTTON_PAUSE_CONFIG):
                gameState = GS_CONFIG;
                configMenu->toGame(true);
                break;
            case(BUTTON_PAUSE_RESTART):
                pauseMenu->confirma(BUTTON_PAUSE_RESTART);
                break;
            case(BUTTON_PAUSE_EXIT):
                pauseMenu->confirma(BUTTON_PAUSE_EXIT);
                break;
            case(BUTTON_PAUSE_Y_RESTART):
                reiniciaJogo();
                gameState = GS_PLAY;
                break;
            case(BUTTON_PAUSE_Y_EXIT):
                reiniciaJogo();
                gameState = GS_MENU;
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

void teclaPressionada(unsigned char key, int x, int y) // funcao de receber o clique de teclas normais do teclado
{
    if(gameState == GS_RECORDS){
        // se estiver na tela de setar os recordes, pede para o usuário digitar seu nome, para adcionar aos recordes
        if(record->processName(key))
            gameState = GS_MENU;
        // só sai dessa tela quando o usuário apertar ESC (para cancelar) ou preencher os 5 dígitos
        return;
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

void flechaPressionada(int key, int x, int y) // funcao para receber clique de setas do teclado
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

void teclaSolta(unsigned char key, int x, int y) // funcao para receber o release da tecla do teclado
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

void flechaSolta(int key, int x, int y) // funcao para receber o release das setas do teclado
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
