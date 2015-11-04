#ifndef DADOS_H_
#define DADOS_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Anuncio;
class Utilizador;
class Negocio;

using namespace std;

//! Class Dados
/*!
 * Classe mae que trata de todo o tipo de dados relativos aos ficheiros (Leitura e Escrita).
 */
class Dados{
protected:
	static vector<Anuncio *>* vetorAnuncios;
	static vector<Utilizador*>* vetorUtilizadores;
	static vector<Negocio* >* vetorNegocios;
public:

	static void setVetorAnuncio(vector<Anuncio*>* anuncios);
	static void setVetorUtilizadores(vector<Utilizador*>* utilizadores);
	static void setVetorNegocios(vector<Negocio*>* negocios);

	static vector<Anuncio*>* getVetorAnuncio();
	static vector<Utilizador*>* getVetorUtilizadores();
	static vector<Negocio*>* getVetorNegocios();

	static void lerFicheiro(ifstream& in);
	static void escreverFicheiro(ofstream& out);


	//! Declaracao da funcao de leitura a ser usada em todas as outras classes.
	virtual void ler(ifstream& in ,bool escreve = false) =0;
	//! Declaracao da funcao de escrita a ser usada em todas as outras classes.
	virtual void escrever(ofstream& out) = 0;
};

#endif
