#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include "anuncio.h"
#include "contacto.h"
#include "utilidades.h"
#include "negocio.h"

class Utilizador{
	Contacto _contacto;
	vector<Anuncio *> _anuncios;
	Localizacao _local;
	vector<Negocio> _negociosConcluidos;
public:

	bool AdicionarAnuncio(Anuncio* anuncio);//Adiciona um anuncio ao utilizador
	bool RemoverAnuncio(Anuncio* anuncio);//Remove um anicio do utilizador
	bool RemoverAnuncio(int id);//Remove um anuncio por id

};


#endif
