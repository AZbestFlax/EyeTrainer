#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include <gl\glut.h>
#include "global.h"
#include <cmath>

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

void CalcDxDy_Round(void) {
    dr = speed*0.1f;
}

void CalcDxDy_Square(void) {
    dx=speed*0.0f;
    dy=speed*0.5f;
}

void CalcDxDy_SquareU(void) {
    dx=speed*0.0f;
    dy=-speed*0.5f;
}

void (*CalcDxDy[CountDirections])(void) = {
    CalcDxDy_Left,
    CalcDxDy_Left,
    CalcDxDy_Left,
    CalcDxDy_Up,
    CalcDxDy_Up,
    CalcDxDy_Up,
    CalcDxDy_Round,
    CalcDxDy_Round,
    CalcDxDy_Square,
    CalcDxDy_SquareU
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

void MoveToStart_Round(void) {
    radius = (windowHeight<windowWidth)?windowHeight:windowWidth;
    radius -= (rsize - rsize/2 + 10);
    PosX = -radius-rsize/2;
    PosY = -rsize/2;
    angle = 180.0f;
}

void MoveToStart_Squarecw(void) {
    radius = (windowHeight<windowWidth)?windowHeight:windowWidth;
    radius -= (rsize/2+10);
    PosX = -rsize/2-radius-rsize;
    PosY = -rsize/2;
}

void MoveToStart_Squareucw(void) {
    radius = (windowHeight<windowWidth)?windowHeight:windowWidth;
    radius -= (rsize/2+10);
    PosX = -rsize/2-radius-rsize;
    PosY = -rsize/2;
}

void (*MoveToStartPos[CountDirections])(void) = {
    MoveToStart_Left,
    MoveToStart_Right,
    MoveToStart_Right,
    MoveToStart_Up,
    MoveToStart_Down,
    MoveToStart_Down,
    MoveToStart_Round,
    MoveToStart_Round,
    MoveToStart_Squarecw,
    MoveToStart_Squareucw
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

void Idle_roundcw(void) {
    OldTick=glutGet(GLUT_ELAPSED_TIME);

    angle -= dr;
    if (angle<0) angle=360;

    PosX = (radius)*cos(angle*M_PI/180.0)-rsize/2;
    PosY = (radius)*sin(angle*M_PI/180.0)-rsize/2;

    glutPostRedisplay();
}

void Idle_rounducw(void) {
    OldTick=glutGet(GLUT_ELAPSED_TIME);

    angle += dr;
    if (angle>360) angle=0;

    PosX = (radius)*cos(angle*M_PI/180.0)-rsize/2;
    PosY = (radius)*sin(angle*M_PI/180.0)-rsize/2;

    glutPostRedisplay();
}

void Idle_squarecw(void) {
    OldTick=glutGet(GLUT_ELAPSED_TIME);

    PosX += dx;
    PosY += dy;

    if (PosY > radius-rsize/2) {
        PosY = radius-rsize/2;
        dy = 0.0f;
        dx = speed*0.5f;
    }
    if (PosX > radius-rsize/2) {
        PosX = radius-rsize/2;
        dy = -speed*0.5f;
        dx = 0.0f;
    }
    if (PosY < -radius-rsize/2) {
        PosY = -radius-rsize/2;
        dy = 0.0f;
        dx = -speed*0.5f;
    }
    if (PosX < -radius-rsize/2) {
        PosX = -radius-rsize/2;
        dy = speed*0.5f;
        dx = 0.0f;
    }

    glutPostRedisplay();
}

void Idle_squareucw(void) {
    OldTick=glutGet(GLUT_ELAPSED_TIME);

    PosX += dx;
    PosY += dy;

    if (PosY > radius-rsize/2) {
        PosY = radius-rsize/2;
        dy = 0.0f;
        dx = -speed*0.5f;
    }
    if (PosX > radius-rsize/2) {
        PosX = radius-rsize/2;
        dy = speed*0.5f;
        dx = 0.0f;
    }
    if (PosY < -radius-rsize/2) {
        PosY = -radius-rsize/2;
        dy = 0.0f;
        dx = speed*0.5f;
    }
    if (PosX < -radius-rsize/2) {
        PosX = -radius-rsize/2;
        dy = -speed*0.5f;
        dx = 0.0f;
    }

    glutPostRedisplay();
}

void (*Idles[CountDirections])(void) = {
    Idle_left,
    Idle_right,
    Idle_leftright,
    Idle_up,
    Idle_down,
    Idle_updown,
    Idle_roundcw,
    Idle_rounducw,
    Idle_squarecw,
    Idle_squareucw
};

#endif // SET_H_INCLUDED
