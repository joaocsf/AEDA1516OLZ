#include "utilidades.h"

void setcolor(unsigned int color)		//define a cor da letra
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void setcolor(unsigned int color, unsigned int background_color)	//define a cor da letra e a cor do fundo
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (background_color == 0)
		SetConsoleTextAttribute(hCon, color);
	else
		SetConsoleTextAttribute(hCon, color + 16*background_color);
}


