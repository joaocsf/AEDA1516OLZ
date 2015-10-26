#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include "anuncio.h"
#include "contacto.h"
#include "utilidades.h"
#include "negocio.h"
#include "dadospessoais.h"
#include "data.h"



class Utilizador{
	DadosPessoais _contacto;
	vector<Anuncio *> _anuncios;
	Localizacao _local;
	vector<Negocio *> _negociosConcluidos;
public:
	Utilizador();
	Utilizador(DadosPessoais contacto, Localizacao loc);
	//~Utilizador();
	bool AdicionarAnuncio(Anuncio* anuncio);//Adiciona um anuncio ao utilizador
	bool RemoverAnuncio(Anuncio* anuncio);//Remove um anicio do utilizador
	bool RemoverAnuncio(int id);//Remove um anuncio por id
	bool FecharNegocio (Anuncio* anuncio, float montante);
	DadosPessoais getDadosPessoais();
	Localizacao getLocalizacao();

};

class AnuncioInexistente{
	int _id;
	Anuncio* _anuncio;
public:
	AnuncioInexistente() { _id = 0; _anuncio = NULL;}
	AnuncioInexistente(int iD) {_id = iD; _anuncio = NULL;}
	AnuncioInexistente(Anuncio* anuncio) {_anuncio = anuncio; _id = anuncio->getID();}
	int getID() { return (_anuncio == NULL)? _id : _anuncio->getID();}
};

#endif
