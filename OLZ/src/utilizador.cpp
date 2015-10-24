#include "utilizador.h"

Utilizador::Utilizador(DadosPessoais contacto, Localizacao loc){
	_contacto = contacto;
	_local = loc;
}

bool Utilizador::AdicionarAnuncio(Anuncio* anuncio){
	//excepçao o anuncio pode ja existir neste utilizador;
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
	//criar a excepçao de AnuncioInexistente;
	return false;
}

bool Utilizador::RemoverAnuncio(int id){
	for (unsigned int var = 0; var < _anuncios.size(); var++) {
			if (_anuncios[var]->_ID == id){
				_anuncios.erase(_anuncios.begin() + var);
				return true;
			}
		}
	//Anuncio Inexistente;
	return false;
}

DadosPessoais Utilizador::getDadosPessoais(){
	return this->_contacto;
}

Localizacao Utilizador::getLocalizacao(){
	return this->_local;
}

bool Utilizador::FecharNegocio (Anuncio* anuncio, float montante){
	Negocio* neg = new Negocio(anuncio, montante);
	_negociosConcluidos.push_back(neg);
