#ifndef NEGOCIO_H_
#define NEGOCIO_H_

#include "anuncio.h"

class Negocio{
	Anuncio *_ptr_anuncio;
	float _montante; // montatne da compra/venda
	//data da venda
public:
	Negocio();
	Negocio(Anuncio* anun,float valor){
		_ptr_anuncio = anun;
		_montante = valor;
	};
	~Negocio();
};


#endif
