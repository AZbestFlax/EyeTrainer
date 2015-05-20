#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

enum dir {Left, Right, leftright, up, down, updown, leftup, leftdown,
          rightup, rightdown, leftuprev, leftdownrev, rightuprev,
          rightdownrev, roundcw, rounducw, squarecw, squareucw};

const unsigned short int CountDirections = 6;

long long ddd = 0;

dir current_direction = Left;        // Спосіб руху

int WinWidth=640;		// Ширина вікна
int WinHeight=480;		// Висота вікна

GLuint list=0;
GLuint OldTick;			//Старое время

GLuint FramesCount;		//Счётчик кадров
GLuint StartTick;		//Начало отсчёта

GLfloat speed = 1.0f;
GLfloat windowWidth, windowHeight;
GLfloat rsize = 40.0f;
GLfloat nRange = 100.0f;
GLfloat PosX = 500, PosY = 500;
GLfloat dfd = 0.1f;
GLfloat dx=speed*0.5f, dy=speed*0.5f;
GLboolean bTimer=0;		// Состояние анимации

inline dir& operator++(dir& eDOW, int)  // <--- note -- must be a reference
{
   int i = static_cast<int>(eDOW);
   i++;
   if (i>=CountDirections) i=0;
   eDOW = static_cast<dir>(i);
   return eDOW;
}

inline dir& operator--(dir& eDOW, int)  // <--- note -- must be a reference
{
   int i = static_cast<int>(eDOW);
   i--;
   if (i<0) i=CountDirections-1;
   eDOW = static_cast<dir>(i);
   return eDOW;
}

#endif // GLOBAL_H_INCLUDED
