#include "dados.h"

vector<Anuncio *>* Dados::vetorAnuncios= NULL;
vector<Utilizador*>* Dados::vetorUtilizadores= NULL;
vector<Negocio* >* Dados::vetorNegocios = NULL;

void Dados::setVetorAnuncio(vector<Anuncio*>* anuncios){
	vetorAnuncios=anuncios;
}
void Dados::setVetorUtilizadores(vector<Utilizador*>* utilizadores){
	vetorUtilizadores=utilizadores;
}
void Dados::setVetorNegocios(vector<Negocio*>* negocios){
	vetorNegocios=negocios;
}

vector<Anuncio*>* Dados::getVetorAnuncio(){
	return vetorAnuncios;
}
vector<Utilizador*>* Dados::getVetorUtilizadores(){
	return vetorUtilizadores;
}
vector<Negocio*>* Dados::getVetorNegocios(){
	return vetorNegocios;
}
