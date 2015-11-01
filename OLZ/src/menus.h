#ifndef MENUS_H_
#define MENUS_H_

#include "utilidades.h"

/*cores
BLACK 0
BLUE 1
GREEN 2
CYAN 3
RED 4
MAGENTA 5
BROWN 6
LIGHTGRAY 7
DARKGRAY 8
LIGHTBLUE 9
LIGHTGREEN 10
LIGHTCYAN 11
LIGHTRED 12
LIGHTMAGENTA 13
YELLOW 14
WHITE 15
 */

void intro();

string Highlight();

void menuInicial(int y);
void menuLogin(int y);
void menuAnunciar(int y);
void menuPesquisar(int y);
void menuOrdemPesq(int y);
void menuConta(int y);
void menuAnuncio(int y);


int menu(int tamanho,int menuSelect);




#endif
