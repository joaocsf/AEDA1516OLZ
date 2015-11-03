#ifndef WEBSITE_H_
#define WEBSITE_H_

#include "utilidades.h"
#include "utilizador.h"
#include "anuncio.h"
#include "negocio.h"


class Website{
	static vector<Utilizador *> utilizadores;
	static vector<Anuncio *> anuncios;
	static vector<Negocio *> negocios;
	static int indiceUtilizador;
	static Data _data;
public:
	Website();
	static void login();
	static void logout();
	static void Registar();
	static void Anunciar_AC();
	static void Anunciar_AV();
	static vector<Utilizador*>  getUtilizadores();
	static vector<Anuncio *>  getAnuncios();
	static vector<Negocio*>  getNegocios();
	static void addUtilizador(Utilizador *u);
	static void addAnuncio(Anuncio *a);
	static void addNegocio(Negocio *n);
	static void RemoveAnuncio(int id);
	static void RemoveUtilizador(int id);
	static void	RemoveNegocio(int id);
	static int getIndiceUtilizador();
	//procura
	static vector<int> procurarPalavraChave(string palavra);
	static vector<int> procurarData(Data data);
	static vector<int> procurarCategoria(string categoria);
	static vector<int> procurarLocalizacao(string loc);
	static vector<int> procurarPreco(int min, int max);
	//menu pesquisa
	static int menuAnuncioPalavra();
	static int menuAnuncioData();
	static int menuAnuncioCategoria();
	static int menuAnuncioLocalizacao();
	static int menuAnuncioPreco(bool crescente);
	static void ordenaPreco(vector<int>& v,bool crescente);
	static void intro();
	static void contactar(int id);
	static void guardarFicheiro(ofstream& file);
	static void lerFicheiro(ifstream& file);
	//menu definicoes
	static vector<int> anunciosParaIndices(const vector<Anuncio*>& aTemp);
	static vector<int> retornarMeusAnuncios(bool venda);
	static int MenuAnuncioConta(bool venda);
};

class UtilizadorInixestente{
	string mail;
public:
	UtilizadorInixestente(string mail){
		this->mail=mail;
	}
	string getMail(){
		return mail;
	}
};

#endif
