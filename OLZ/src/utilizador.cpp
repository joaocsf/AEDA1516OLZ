#include "utilizador.h"


Utilizador::Utilizador(){

}

Utilizador::Utilizador(DadosPessoais contacto, Localizacao loc){
	_local = loc;
	_contacto = contacto;
}

bool Utilizador::AdicionarAnuncio(Anuncio* anuncio){
	_anuncios.push_back(anuncio);
	return true;
}

bool Utilizador::RemoverAnuncio(Anuncio* anuncio){
	for (unsigned int var = 0; var < _anuncios.size(); var++) {
		if (_anuncios[var] == anuncio){
			_anuncios.erase(_anuncios.begin() + var);
			return true;
		}
	}
	throw AnuncioInexistente(anuncio);
}

bool Utilizador::RemoverAnuncio(int id){
	for (unsigned int var = 0; var < _anuncios.size(); var++) {
			if (_anuncios[var]->Anuncio::getID() == id){
				_anuncios.erase(_anuncios.begin() + var);
				return true;
			}
		}
	throw AnuncioInexistente(id);
}

DadosPessoais Utilizador::getDadosPessoais(){
	return this->_contacto;
}

Localizacao Utilizador::getLocalizacao(){
	return _local;
}

bool Utilizador::FecharNegocio (Anuncio* anuncio, float montante){
	Negocio* neg = NULL;
	for (unsigned int i = 0; i < _anuncios.size(); i++) {
		if(_anuncios[i] == anuncio){
			neg = new Negocio(anuncio, montante);//Se encontrou o anuncio então cria o negocio;
			break;
		}
	}
	if (neg == NULL){
		throw AnuncioInexistente(anuncio);
	}
	_negociosConcluidos.push_back(neg);
	return RemoverAnuncio(anuncio);
}













