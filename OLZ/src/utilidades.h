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
#include "math.h"

using namespace std;


//! Estrutura Localizacao.
/*!
 *Serve para organizaçao a localizacao de cada utilizador
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

//! Funcao que altera a cor das letras que irão ser impressas na consola.
	    /*!
	      \param color a cor para a qual vai alterar.
	    */
void setcolor(unsigned int color);
//! Funcao que altera a cor das letras que irão ser impressas na consola e o fundo.
	    /*!
	      \param color a cor para a qual se vai alterar as letras.
	      \param background_color a cor para a qual se vai alterar o fundo.
	    */
void setcolor(unsigned int color, unsigned int background_color);

//!Excepcao de Erro na leitura.
class ErroLeitura{
	//!erro
	/*!
	 * Descricao do erro que ocorreu.
	 */
	string erro;
public:
	//!Construtor default.
	ErroLeitura();
	//!Overload do construtor com 1 parametro.
	/*!
	 \param erro descricao do erro que ocorreu na leitura.
	 */
	ErroLeitura(string erro);
	//!Funcao get para o erro.
	string getErro();
};







#endif
