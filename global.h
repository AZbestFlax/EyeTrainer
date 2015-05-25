#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

enum dir {Left, Right, leftright, up, down, updown, leftup, leftdown,
          rightup, rightdown, leftuprev, leftdownrev, rightuprev,
          rightdownrev, roundcw, rounducw, squarecw, squareucw};

enum style {front, back};

const unsigned short int CountDirections = 10;
const short int CountColorThemes = 4;

long long ddd = 0;

dir current_direction = Left;        // Спосіб руху

int WinWidth=640;		// Ширина вікна
int WinHeight=480;		// Висота вікна

GLuint list=0;
GLuint OldTick;			//Старое время

GLuint FramesCount;		//Счётчик кадров
GLuint StartTick;		//Начало отсчёта

GLfloat speed = 0.5f;
GLfloat windowWidth, windowHeight;
GLfloat rsize = 40.0f;
GLfloat nRange = 100.0f;
GLfloat PosX = 500, PosY = 500, angle=0.0f;
GLfloat radius;
GLfloat dfd = 0.1f;
GLfloat dx=speed*0.5f, dy=speed*0.5f, dr=speed*0.1f;
GLboolean bTimer=0;		// Состояние анимации

int colorTheme = 0;

GLfloat colorPreset[CountColorThemes][2][3] = {
 { {0.1,0.7,0.2},{0.5,0.5,0.75} },
 { {0.2,0.8,0.3},{0.6,0.6,0.85} },
 { {1.0,1.0,1.0},{0.0,0.0,0.00} },
 { {0.0,0.0,0.0},{1.0,1.0,1.00} }
};

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

int StringWidth(void* font, char* str)	//Определение ширины строки
{
	int Width=0;
	char *c=str;
	while (*c)
	{
		Width+=glutBitmapWidth(font, *c);
		c++;
	}
	return Width;
};

void PrintString(void* font, char* str)	//Вывод строки на экран
{
	char* c=str;
	while (*c)
	{
		glutBitmapCharacter(font, *c);
		c++;
	}
}

void incrColor(void) {
    colorTheme++;
    if (colorTheme >= CountColorThemes) colorTheme=0;
}

void decrColor(void) {
    colorTheme--;
    if (colorTheme < 0) colorTheme=CountColorThemes-1;
}

#endif // GLOBAL_H_INCLUDED
