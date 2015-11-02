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
#include "limits.h"

using namespace std;

void intro();



//! Estrutura localizacao.
/*!
 *Serve para organiza�ao a localizacao de cada utilizador
 */
struct Localizacao{
	//! Uma variavel publica.
	string freguesia;
	//! Uma variavel publica.
	string concelho;
	//! Uma variavel publica.
	string distrito;
};

//! Estrutura Imagem.
struct Imagem{
	string conteudo;
};

//! Funcao que altera a cor das letras que ir�o ser impressas na consola.
	    /*!
	      \param color a cor para a qual vai alterar.
	    */
void setcolor(unsigned int color);
//! Funcao que altera a cor das letras que ir�o ser impressas na consola e o fundo.
	    /*!
	      \param color a cor para a qual se vai alterar as letras.
	      \param background_color a cor para a qual se vai alterar o fundo.
	    */
void setcolor(unsigned int color, unsigned int background_color);









#endif
