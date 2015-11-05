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
 * Classe mae que trata de todo o tipo de dados. Esta classe contem as declaracoes dos membros e funcoes do programa principal.
 */
class Dados{
protected:
	//!Declaracao global do vetor de anuncios do programa.
	/*!
	 \sa Anuncio
	 */
	static vector<Anuncio *>* vetorAnuncios;
	//!Declaracao global do vetor de utilizadores do programa.
	/*!
	 \sa Utilizador
	 */
	static vector<Utilizador*>* vetorUtilizadores;
	//!Declaracao global do vetor de negocios do programa.
	/*!
	 \sa Negocio
	 */
	static vector<Negocio* >* vetorNegocios;
public:
	//!Funcao set para o vetor de anuncios.
	static void setVetorAnuncio(vector<Anuncio*>* anuncios);
	//!Funcao set para o vetor de utilizadores.
	static void setVetorUtilizadores(vector<Utilizador*>* utilizadores);
	//!Funcao set para o vetor de negocios.
	static void setVetorNegocios(vector<Negocio*>* negocios);

	//!Funcao get para o vetor de anuncios.
	static vector<Anuncio*>* getVetorAnuncio();
	//!Funcao get para o vetor de utilizadores.
	static vector<Utilizador*>* getVetorUtilizadores();
	//!Funcao get para o vetor de negocios.
	static vector<Negocio*>* getVetorNegocios();

	//!Funcao para a leitura de toda a informacao contida no ficheiro de dados relativos ao programa.
	static void lerFicheiro(ifstream& in);
	//!Funcao para a escrito de toda a informacao para o ficheiro de dados relativos ao programa.
	static void escreverFicheiro(ofstream& out);


	//! Declaracao da funcao de leitura a ser usada em todas as outras classes.
	virtual void ler(ifstream& in ,bool escreve = false) =0;
	//! Declaracao da funcao de escrita a ser usada em todas as outras classes.
	virtual void escrever(ofstream& out) = 0;
};

#endif
