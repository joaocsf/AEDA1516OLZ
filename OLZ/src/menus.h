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

//!Funcao que coloca os "[" "]" no sitio correto.
string Highlight(string frase, int select, int ops);

//!Class Menu
/*!
 * Esta classe implementa as funcoes relativas a interface e ao seu funcionamento.
 * Estas funcoes sao um conjunto de couts que organizam no ecra aquilo que e possivel ao utilizador de fazer.
 * O menu funciona apartir de um inteiro (y) que indica qual o atual/proximo menu a ser exibido.
 */
class Menu{

public:
//!Menu principal.
static int menu(int tamanho,int menuSelect);
//menu print
//!Menu Inicial.
static void menuInicial(int y);
//!Menu de login.
static void menuLogin(int y);
//!Menu para anunciar.
static void menuAnunciar(int y);
//!Menu para realizar uma pesquisa.
static void menuPesquisar(int y);
//!Menu para ordenar uma pesquisa.
static void menuOrdemPesq(int y);
//!Menu da conta do utilizador.
static void menuConta(int y);
//!Menu do anuncio.
static void menuAnuncio(int y);
//!Menu das definicoes do anuncio.
static void menuAnuncioDefinicoes(int y);
//!Menu para escolher o tipo de anuncio.
static void menuTipoAnuncio(int y);
//!Menu para escolher o estado do produto.
static void menuCategProd(int y);
//!Menu para editar um anuncio de compra.
static void menuEditar_AC(int y);
//!Menu para editar um anuncio de venda.
static void menuEditar_AV(int y);
//!Menu para editar as definicoes de um utilizador.
static void menuEditarUtilizador(int y);
//interface
//!Interface
static int menuInterface();
//!Interface de login.
static int interfaceLog();
//!Interface da conta.
static int interfaceConta();
//!Interface de pesquisa.
static int interfacePesquisar(bool log);
//!Interface de ordenacao da pesquisa.
static int interfaceOrdemPesq();
//!Interface para o tipo de anuncio.
static int interfaceTipoAnuncio();
//!Interface para a categoria do produto.
static int interfaceCategProd();
//!Interface para as definicoes do anuncio.
static int interfaceAnuncioDefinicoes();
//!Interface para o menu de anuncio.
static int interfacemenuAnuncio();
//!Interface para editar um anuncio de venda.
static int interfaceEditarAnuncio_AV();
//!Interface para editar um anuncio de compra.
static int interfaceEditarAnuncio_AC();
//!Interface para editar um utilizador.
static int interfaceEditarUtilizador();
//selector
//!Selector da interface.
static void InterfaceSeletor();
//!Variavel que indica se o usuario está logado.
static bool logado;
//!Id do anuncio no vetor anuncios onde que o utilizador esta a visualizar no momento
static int idAnuncio;
//menu dos anuncios
//!Menu dos anuncios.
static Anuncio* menuAnuncioInterface(vector<Anuncio*>& anuncios);
//!Funcao para desenhar a thumbnail de um anuncio.
static void desenharAnuncioThumbnail(Anuncio* anuncio, int sel, int pos);
//menu negocios
//!Funcao para desenhar a thumbnail de negocios.
static void desenharNegocioThumbnail(Negocio *n, int sel, int pos);
//!Menu para os negocios.
static Negocio* menuNegocioInterface(const vector<Negocio*>& negocios);
//menu visibilidade
//!Menu da visibilidade dos dados do utilizador.
static void menuVisibilidade(int y);
//!Interface para alterar a visibilidade dos dados.
static int interfaceMudarVisibilidade();

//---------------------David Compõe a cena ---------------
static Utilizador* menuTopNegociantesInterface(vector<Utilizador*>& util);

static void desenharUtilizadorThumbnail(Utilizador* util, int sel, int pos);

static void menuPesquisarNegocios(int y);
static int interfacePesquisarNegocios();

};

#endif
