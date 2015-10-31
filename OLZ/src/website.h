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
public:
	static vector<Utilizador*>  getUtilizadores();
	static vector<Anuncio *>  getAnuncios();
	static vector<Negocio*>  getNegocios();
	static void addUtilizador(Utilizador *u);
	static void addAnuncio(Anuncio *a);
	static void addNegocio(Negocio *n);
	static void RemoveAnuncio(int id);
	static void RemoveUtilizador(int id);
	static void	RemoveNegocio(int id);
};



#endif
