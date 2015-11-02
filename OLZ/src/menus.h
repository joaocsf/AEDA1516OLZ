#ifndef MENUS_H_
#define MENUS_H_

#include "utilidades.h"
#include "website.h"

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


string Highlight();

class Menu{

public:
static int menu(int tamanho,int menuSelect);
//menu print
static void menuInicial(int y);
static void menuLogin(int y);
static void menuAnunciar(int y);
static void menuPesquisar(int y);
static void menuOrdemPesq(int y);
static void menuConta(int y);
static void menuAnuncio(int y);
static void menuAnuncioDefinicoes(int y);
static void menuTipoAnuncio(int y);
static void menuCategProd(int y);
//interface
static int menuInterface();
static int interfaceLog();
static int interfaceConta();
static int interfacePesquisar(bool log);
static int interfaceOrdemPesq();
static int interfaceTipoAnuncio();
static int interfaceCategProd();
static int interfaceAnuncioDefinicoes();
//selector
static void InterfaceSeletor();
static bool logado; //variavel que indica se o usuario está logado
};

#endif
