#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include <gl\glut.h>
#include "global.h"

void CalcDxDy_Left(void) {
    bool sign = dx<0;
    dx=speed*0.5f;
    if (sign) dx*=-1;
}

void CalcDxDy_Up(void) {
    bool sign = dy<0;
    dy=speed*0.5f;
    if (sign) dy*=-1;
}

void (*CalcDxDy[CountDirections])(void) = {
    CalcDxDy_Left,
    CalcDxDy_Left,
    CalcDxDy_Left,
    CalcDxDy_Up,
    CalcDxDy_Up,
    CalcDxDy_Up
};

// =============================================================================

void MoveToStart_Left(void) {
    PosX = windowWidth;
    PosY = -rsize/2;
    CalcDxDy[current_direction]();
}

void MoveToStart_Right(void) {
    PosX = -windowWidth-rsize;
    PosY = -rsize/2;
    CalcDxDy[current_direction]();
}

void MoveToStart_Up(void) {
    PosY = -windowHeight-rsize;
    PosX = -rsize/2;
    CalcDxDy[current_direction]();
}

void MoveToStart_Down(void) {
    PosY = windowHeight;
    PosX = -rsize/2;
    CalcDxDy[current_direction]();
}

void (*MoveToStartPos[CountDirections])(void) = {
    MoveToStart_Left,
    MoveToStart_Right,
    MoveToStart_Right,
    MoveToStart_Up,
    MoveToStart_Down,
    MoveToStart_Down
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

void Idle_up(void) {
	OldTick=glutGet(GLUT_ELAPSED_TIME);

    if (PosY > windowHeight) {
        MoveToStartPos[current_direction]();
    }

    PosY += dy;

    if (PosY > (windowHeight+dy))
        PosY = windowHeight-dfd;

	glutPostRedisplay();
}

void Idle_down(void) {
    OldTick=glutGet(GLUT_ELAPSED_TIME);

    if (PosY < -windowHeight-rsize) {
        MoveToStartPos[current_direction]();
    }

    PosY -= dy;

    if (PosY < (-windowHeight-rsize-dy))
        PosY = -windowHeight-rsize-dfd;

	glutPostRedisplay();
}

void Idle_updown(void) {
	OldTick=glutGet(GLUT_ELAPSED_TIME);

    if (PosY > windowHeight - rsize || PosY < -windowHeight)
        dy = -dy;

    PosY += dy;

    if (PosY > (windowHeight-rsize+dy))
        PosY = windowHeight-rsize-dfd;
    else if (PosY < -(windowWidth+dy))
        PosY = -windowHeight-dfd;
	glutPostRedisplay();
}

void (*Idles[CountDirections])(void) = {
    Idle_left,
    Idle_right,
    Idle_leftright,
    Idle_up,
    Idle_down,
    Idle_updown
};

#endif // SET_H_INCLUDED
