#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

enum dir {Left, Right, leftright, up, down, updown, leftup, leftdown,
          rightup, rightdown, leftuprev, leftdownrev, rightuprev,
          rightdownrev, roundcw, rounducw, squarecw, squareucw};

const unsigned short int CountDirections = 18;

dir current_direction = leftright;//Right;        // ����� ����

int WinWidth=640;		// ������ ����
int WinHeight=480;		// ������ ����

GLuint list=0;
GLuint OldTick;			//������ �����

GLuint FramesCount;		//������� ������
GLuint StartTick;		//������ �������

GLfloat speed = 0.5f;
GLfloat windowWidth, windowHeight;
GLfloat rsize = 40.0f;
GLfloat nRange = 100.0f;
GLfloat PosX = 500, PosY = 500;
GLfloat dfd = 0.1f;
GLfloat dx=speed*0.5f, dy=speed*0.5f;
GLboolean bTimer=0;		// ��������� ��������

#endif // GLOBAL_H_INCLUDED
