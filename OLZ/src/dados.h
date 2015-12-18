#ifndef DADOS_H_
#define DADOS_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>

class Anuncio;
class Utilizador;
class Negocio;

using namespace std;

//! Class Dados
/*!
 * Classe mae que trata do tipo de dados. Esta classe contem as declaracoes dos membros e funcoes do programa principal.
 */
class Dados{

public:

	//!Funcao para a leitura de toda a informacao contida no ficheiro de dados relativos ao programa.
	static vector<Utilizador*> lerFicheiro(ifstream& in);
	//!Funcao para a escrito de toda a informacao para o ficheiro de dados relativos ao programa.
	static void escreverFicheiro(ofstream& out, vector<Utilizador*> vetorUtilizadores);


	//! Declaracao da funcao de leitura a ser usada em todas as outras classes.
	virtual void ler(ifstream& in ,bool escreve = false) =0;
	//! Declaracao da funcao de escrita a ser usada em todas as outras classes.
	virtual void escrever(ofstream& out) = 0;
};

#endif
