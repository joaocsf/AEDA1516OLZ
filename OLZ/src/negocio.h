#ifndef NEGOCIO_H_
#define NEGOCIO_H_

#include "anuncio.h"


class Negocio{
	Anuncio *_ptr_anuncio;
	float _montante; // montatne da compra/venda
	Data _data;
	static int _ID;
	int _identificador;
public:
	Negocio();
	Negocio(Anuncio* anun,float valor);
	~Negocio();
};


#endif
