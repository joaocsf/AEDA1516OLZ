#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <conio.h>


using namespace std;

void intro();




struct Localizacao{
	string freguesia;
	string concelho;
	string distrito;
};

struct Imagem{
	string conteudo;
};


void setcolor(unsigned int color);

void setcolor(unsigned int color, unsigned int background_color);









#endif
