#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include "anuncio.h"
#include "contacto.h"
#include "utilidades.h"
#include "negocio.h"

class Utilizador{
	Contacto cont;
	vector<Anuncio *> anuncios;
	Localizacao local;
	vector<Negocio> negociosConcluidos;
public:


};


#endif
