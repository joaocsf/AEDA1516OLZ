#include "website.h"

vector<Utilizador*> Website::utilizadores;
vector<Anuncio *> Website::anuncios;
vector<Negocio*> Website::negocios;

vector<Utilizador*>  Website::getUtilizadores(){
	return utilizadores;
}

vector<Anuncio *>  Website::getAnuncios(){
	return anuncios;
}

vector<Negocio*>  Website::getNegocios(){
	return negocios;
}

void Website::addUtilizador(Utilizador *u){
	utilizadores.push_back(u);
}

void Website::addAnuncio(Anuncio *a){
	anuncios.push_back(a);
}

void Website::addNegocio(Negocio *n){
	negocios.push_back(n);
}

void Website::RemoveAnuncio(int id){
	for (unsigned int i = 0; i < anuncios.size(); ++i) {
		if(anuncios[i]->getID()==id){
			anuncios.erase(anuncios.begin()+i);
			break;
		}
	}
}

void Website::RemoveUtilizador(int id){

}

void	Website::RemoveNegocio(int id){

}
