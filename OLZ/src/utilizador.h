#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

//#include "anuncio.h"
#include "contacto.h"
#include "utilidades.h"
#include "negocio.h"
#include "dadospessoais.h"
#include "data.h"
#include "comum.h"
#include "website.h"

#define UT_CONTACTO 0
#define UT_FREGUESIA 1
#define UT_CONCELHO 2
#define UT_DISTRITO 3
#define UT_IDENTIFICADOR 4
#define UT_NEGOCIOS 5
#define UT_TOTAL 6


//! Classe Utilizador
/*!
 * Esta classe encarrega-se dos atributos de cada utilizador e da gestao dos seus anuncios
 */
class Utilizador : public Dados{
	//! ID
	/*!
	 * Variavel global da classe com o numero de identificacao do proximo utilizador
	 */
	static int _ID;
	//! identificador
	/*!
	 * Numero de identificacao do utilizador
	 */
	int _identificador;
	//! Contacto
	/*!
	 * Informacoes de contato do utilizador
	 */
	DadosPessoais _contacto;
	//! Localizacao
	/*!
	 * localizacao do utilizador
	 */
	Localizacao _local;
	//! Anuncios
	/*!
	 * Vector de anuncios do utilizador (anuncios de venda e de compra)
	 */
	vector<Anuncio *> _anuncios;
	//! NegociosConcluidos
	/*!
	 * Vector com os negocios concluidos do utilizador
	 */
	vector<Negocio *> _negociosConcluidos;
public:

	Utilizador();
	Utilizador(DadosPessoais contacto, Localizacao loc);
	//~Utilizador();
	bool AdicionarAnuncio(Anuncio* anuncio);//Adiciona um anuncio ao utilizador
	bool RemoverAnuncio(Anuncio* anuncio);//Remove um anicio do utilizador
	bool RemoverAnuncio(int id);//Remove um anuncio por id
	bool FecharNegocio (Anuncio* anuncio, float montante);
	bool AlteraContacto(string telefone, string email);

	DadosPessoais getDadosPessoais();
	Localizacao getLocalizacao();
	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);
	string getInfo() const;
	Anuncio* procurarAnuncio(int id);
	int getID() const;
	static int getIDGlobal();
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
