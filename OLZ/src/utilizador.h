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


//! Class Utilizador
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
	
	~Utilizador();
	

	Utilizador();
	//! Overload do Construtor que recebe dois argumentos.
		    /*!
		      \param contacto com os dados pessoais do utilizador.
		      \param loc a localizacao do utilizador.
		    */
	Utilizador(DadosPessoais contacto, Localizacao loc);
	//~Utilizador();
	//! Funcao que adiciona um anuncio ao utilizador.
		/*!
		 \param anuncio que vai ser adicionado.
		 \return um booleano que indica se o anuncio foi adicionado ou não.
		 */
	bool AdicionarAnuncio(Anuncio* anuncio);
	//! Funcao que remove um anuncio do utilizador.
			/*!
			 \param anuncio que vai ser removido.
			 \return um booleano que indica se o anuncio foi removido ou não.
			 */
	bool RemoverAnuncio(Anuncio* anuncio);
	//! Funcao que remove um anuncio ao utilizador por id.
			/*!
			 \param id do anuncio que vai removido.
			 \return um booleano que indica se o anuncio foi removido ou não.
			 */
	bool RemoverAnuncio(int id);
	//! Funcao que fecha um negocio
			/*!
			 \param anuncio que ira ser fechado
			 \param montante valor que foi pago ao utilizador.
			 \param data data em que o negocio se concretizou.
			 \return um booleano que indica se foi posivel fechar o negocio ou nao.
			 */
	bool FecharNegocio (Anuncio* anuncio, float montante, Data data);
	//! Funcao que altera o contacto do utilizador.
			/*!
			 \param telefone novo telefone do utlizador
			 \param email novo email do utilizador.
			 \return um booleano que indica se o contacto foi alterado ou não.
			 */
	bool AlteraContacto(string telefone, string email);

	//!Funcao get para os dados pessoais.
	DadosPessoais getDadosPessoais();

	//!Funcao get para a localizacao.
	Localizacao getLocalizacao();

	//!Funcao para ler as informacoes de um ficheiro.
	virtual void ler(ifstream& in,bool escreve= false);

	//!Funcao que escreve as informacoes num ficheiro.
	virtual void escrever(ofstream& out);

	//!Funcao get para a informacao do utilizador.
	string getInfo() const;

	//!Funcao de pesquisa no vector anuncios para um dado id.
	/*!v
	 \param id do anuncio a ser procurado
	 \return apontador para o anuncio no caso deste ser encontrado.
	 */
	Anuncio* procurarAnuncio(int id);

	//!Funcao get para o ID.
	int getID() const;

	//!Funcao global para devolver o valor atual da variavel global ID.
	static int getIDGlobal();
	//!Funcao global para defenir o valor da variavel global ID.
	static int setIDGlobal(int id);

	//!Funcao retorna os anuncios do vetor anuncios conforme sejam de venda ou de compra.
	/*!
	 \param venda boleano que indica se o tipo de anuncios a retornar e de venda ou de compra.
	 \return vetor de apontadores do tipo de anuncio.
	 */
	vector<Anuncio*> getAnuncios(bool venda);
	vector<Anuncio*> getAnuncios();
	vector<Negocio*> getNegocios();
};

//! Class AnuncioInexistente
/*!
 * Excepcao de anuncio inexistente no caso do anuncio nao existir
 */
class AnuncioInexistente{
	//! id
		/*!
		 * id do anuncio que nao foi encontrado.
		 */
	int _id;
	//! anuncio
	/*!
	 * anuncio que nao foi encontrado.
	 */
	Anuncio* _anuncio;
public:
	//! Construtor default.
	AnuncioInexistente() { _id = 0; _anuncio = NULL;}
	//! Overload do construtor para id.
	/*!
	 \param iD do anuncio que nao foi encontrado.
	 */
	AnuncioInexistente(int iD) {_id = iD; _anuncio = NULL;}
	//!Overload do construtor para anuncio.
	/*!
	 \param anuncio que nao foi encontrado.
	 */
	AnuncioInexistente(Anuncio* anuncio) {_anuncio = anuncio; _id = anuncio->getID();}
	//! Funcao get para o id do anuncio inexistente.
	int getID() { return (_anuncio == NULL)? _id : _anuncio->getID();}
};

#endif
