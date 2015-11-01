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
public:
	Website();
	static void login();
	static void logout();
	static void Registar();
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
