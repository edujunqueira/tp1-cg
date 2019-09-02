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
int randomPoint(int x, int y);
void escreve(void* fonte, const char* texto, float x, float y);

#endif /* _FUNCTIONS_H */
