#include <iostream>
#include <windows.h>
#include <gl\glut.h>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>

#include "set.h"
#include "global.h"
using namespace std;

void Init()				// Инициализация OpenGL
{

}

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1,0.7,0.2);
	glClearColor(0.5, 0.5, 0.75, 1);
    glRectf(PosX,PosY,PosX+rsize,PosY+rsize);
    glutSwapBuffers();
}

void Reshape(GLsizei w, GLsizei h) {
    GLfloat aspectRatio;
    if (h==0) h=1;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    aspectRatio = (GLfloat)w / GLfloat(h);
    if (w <= h) {
        windowWidth = nRange;
        windowHeight = nRange / aspectRatio;
        glOrtho(-nRange,nRange,-windowHeight, windowWidth,1.0,-1.0);
    } else {
        windowWidth = nRange * aspectRatio;
        windowHeight = nRange;
        glOrtho(-windowWidth,windowWidth,-nRange,nRange,1.0,-1.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SetupRC(void) {
    glClearColor(0.5, 0.5, 0.75, 1);
}


void Keyboard(unsigned char key,int x,int y)			//Обработка сообщений от клавиатуры
{
	switch (key)
	{
		case VK_ESCAPE:		//Если нажата клавиша ESC - выход
			exit(0);
			break;
	}
}

void KeyboardSpecial(int key, int x, int y) {
    switch (key)
	{
		case GLUT_KEY_F2:
        bTimer=!bTimer;
			if (bTimer)
			{
	 			OldTick=glutGet(GLUT_ELAPSED_TIME);
				StartTick=OldTick;
				MoveToStartPos[current_direction]();
				glutIdleFunc(Idles[current_direction]);
				//glutMouseFunc(NULL);
				//glutMotionFunc(NULL);
			}
			else
			{
				//glutMouseFunc(Mouse);
				//glutMotionFunc(MouseMotion);
				glutIdleFunc(NULL);
			}
        break;
	}
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WinWidth,WinHeight);
	glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN)-WinWidth)/2,
		                   (GetSystemMetrics(SM_CYSCREEN)-WinHeight)/2);
    glutCreateWindow("Follow the Cube");
    glutFullScreen();

    glutDisplayFunc(RenderScene);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(KeyboardSpecial);
    glutReshapeFunc(Reshape);

    SetupRC();
    glutMainLoop();
    return 0;
}
