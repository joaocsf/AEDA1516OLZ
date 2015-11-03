#ifndef DADOS_H_
#define DADOS_H_
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//! Class Dados
/*!
 * Classe mae que trata de todo o tipo de dados relativos aos ficheiros (Leitura e Escrita).
 */
class Dados{
public:
	//! Declaracao da funcao de leitura a ser usada em todas as outras classes.
	virtual void ler(ifstream& in ,bool escreve = false) =0;
	//! Declaracao da funcao de escrita a ser usada em todas as outras classes.
	virtual void escrever(ofstream& out) = 0;
};

#endif
