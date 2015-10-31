#include "negocio.h"

int Negocio::_ID=1;


Negocio::Negocio(Anuncio* anun,float valor){
	_ptr_anuncio = anun;
	_montante = valor;
	_identificador=(_ID++);
};

int Negocio::getID(){
	return _identificador;
}
