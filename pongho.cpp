#include "barra.h"
#include "bola.h"

#define posmaxx 100
#define posmaxy 200
#define raioBola 5

// cria a variavel global ball
bola* ball = nullptr;
barra* user1 = nullptr;
barra* user2 = nullptr;

void desenhaCena()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // desenha a bola
    ball->desenhaBola();
    user1->desenhaBarra();
    user2->desenhaBarra();

	glutSwapBuffers();
}

void atualizaCena(int periodo)
{
    // faz a bola se movimentar
    ball->movimenta(user1->getPosX(), user2->getPosX());

    // chama o postredisplay
    glutPostRedisplay();
    glutTimerFunc(25, atualizaCena, 0);
}

void setup()
{
    // define users
    user1 = new barra(1);
    user2 = new barra(2);
    // define ball
    ball = new bola(5);
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
   glOrtho(0, posmaxx, posmaxy, 0, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'a':
        user2->mover(-5);
        glutPostRedisplay();
        break;
    case 'd':
        user2->mover(5);
        glutPostRedisplay();
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
    case GLUT_KEY_LEFT:
        user1->mover(-5);
        break;
    case GLUT_KEY_RIGHT:
        user1->mover(5);
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
   glutInitWindowSize(400, 800);
   glutInitWindowPosition(500, 25);

   glutCreateWindow("Hello World - callbacks");

   // Registra callbacks para eventos
   glutDisplayFunc(desenhaCena);
   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);
   glutSpecialFunc(flechaPressionada);
   glutTimerFunc(0, atualizaCena, 33);

   setup();

   glutMainLoop();
   return 0;
}
