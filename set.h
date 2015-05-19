#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include <gl\glut.h>
#include "global.h"

void MoveToStart_Left(void) {
    PosX = windowWidth;
    PosY = -rsize/2;
    dx=speed*0.5f;
}

void MoveToStart_Right(void) {
    PosX = -windowWidth-rsize;
    PosY = -rsize/2;
    dx=speed*0.5f;
}

void (*MoveToStartPos[CountDirections])(void) = {
    MoveToStart_Left,
    MoveToStart_Right,
    MoveToStart_Right
};

// ==================================================================

void Idle_left(void) {
    OldTick=glutGet(GLUT_ELAPSED_TIME);

    if (PosX < -windowWidth-rsize) {
        MoveToStartPos[current_direction]();
    }

    PosX -= dx;

    if (PosX < (-windowWidth-rsize-dx))
        PosX = -windowWidth-rsize-dfd;

	glutPostRedisplay();
}

void Idle_right(void) {
	OldTick=glutGet(GLUT_ELAPSED_TIME);

    if (PosX > windowWidth) {
        MoveToStartPos[current_direction]();
    }

    PosX += dx;

    if (PosX > (windowWidth+dx))
        PosX = windowWidth-dfd;

	glutPostRedisplay();
}

void Idle_leftright(void) {
	OldTick=glutGet(GLUT_ELAPSED_TIME);

    if (PosX > windowWidth - rsize || PosX < -windowWidth)
        dx = -dx;

    PosX += dx;

    if (PosX > (windowWidth-rsize+dx))
        PosX = windowWidth-rsize-dfd;
    else if (PosX < -(windowWidth+dx))
        PosX = -windowWidth-dfd;
	glutPostRedisplay();
}

void (*Idles[CountDirections])(void) = {
    Idle_left,
    Idle_right,
    Idle_leftright
};

#endif // SET_H_INCLUDED