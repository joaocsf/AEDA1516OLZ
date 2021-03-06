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
#include <tr1/unordered_set>

#define UT_CONTACTO 0
#define UT_FREGUESIA 1
#define UT_CONCELHO 2
#define UT_DISTRITO 3
#define UT_IDENTIFICADOR 4
#define UT_NEGOCIOS 5
#define UT_TOTAL 6

//!Struct NegocioHash
/*!
 * Estrutura para a tabela de dispers�o
 */
struct NegocioHash
{
	//!Funcao hash para a tabela de dispersao
	int operator() (const Negocio *neg) const{
		return neg->getIdentificador();
	}

	//!Funcao de igualdade para a tabela de dispersao
	bool operator() (const Negocio *neg1, const Negocio *neg2) const{
		return (*neg1)==(*neg2);
	}
};

typedef tr1::unordered_set<Negocio*,NegocioHash,NegocioHash> TabNeg;




//! Class Utilizador
/*!
 * Esta classe encarrega-se dos atributos de cada utilizador e da gestao dos seus anuncios
 \sa Dados
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
	 \sa DadosPessoais
	 */
	DadosPessoais _contacto;
	//! Localizacao
	/*!
	 * localizacao do utilizador
	 \sa Localizacao
	 */
	Localizacao _local;
	//! Anuncios
	/*!
	 * Vector de anuncios do utilizador (anuncios de venda e de compra)
	 \sa Anuncio
	 */
	vector<Anuncio *> _anuncios;
	//! NegociosConcluidos
	/*!
	 * Tabela de dispersao que contem os negocios concluidos
	 \sa Negocio
	 */
	TabNeg _negociosConcluidos;
public:
	//!Destrutor
	~Utilizador();
	
	//!Construtor default
	Utilizador();
	//! Overload do Construtor que recebe dois argumentos.
		    /*!
		      \param contacto com os dados pessoais do utilizador.
		      \param loc a localizacao do utilizador.
		    */
	Utilizador(DadosPessoais contacto, Localizacao loc);
	//! Funcao que adiciona um anuncio ao utilizador.
		/*!
		 \param anuncio que vai ser adicionado.
		 \return um booleano que indica se o anuncio foi adicionado ou n�o.
		 */
	bool AdicionarAnuncio(Anuncio* anuncio);
	//! Funcao que remove um anuncio do utilizador.
		/*!
		\param anuncio que vai ser removido.
		\return um booleano que indica se o anuncio foi removido ou n�o.
		*/
	bool RemoverAnuncio(Anuncio* anuncio);
	//! Funcao que remove um anuncio ao utilizador por id.
			/*!
			 \param id do anuncio que vai removido.
			 \return um booleano que indica se o anuncio foi removido ou n�o.
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
			 \return um booleano que indica se o contacto foi alterado ou n�o.
			 */
	bool AlteraContacto(string telefone, string email);
	//!Funcao global para defenir o valor da variavel global ID.
	static int setIDGlobal(int id);
	//!Funcao para ler as informacoes de um ficheiro.
	virtual void ler(ifstream& in,bool escreve= false);

	//!Funcao que escreve as informacoes num ficheiro.
	virtual void escrever(ofstream& out);

	//!Funcao de pesquisa no vector anuncios para um dado id.
	/*!v
	 \param id do anuncio a ser procurado
	 \return apontador para o anuncio no caso deste ser encontrado.
	 */
	Anuncio* procurarAnuncio(int id);

	//!Funcao get para os dados pessoais.
	DadosPessoais getDadosPessoais();

	//!Funcao get para a localizacao.
	Localizacao getLocalizacao();

	//!Funcao get para a informacao do utilizador.
	string getInfo() const;

	//!Funcao get para o ID.
	int getID() const;

	//!Funcao global para devolver o valor atual da variavel global ID.
	static int getIDGlobal();


	//!Funcao retorna os anuncios do vetor anuncios conforme sejam de venda ou de compra.
	/*!
	 \param venda boleano que indica se o tipo de anuncios a retornar e de venda ou de compra.
	 \return vetor de apontadores do tipo de anuncio.
	 */
	vector<Anuncio*> getAnuncios(bool venda);
	//!Funcao get para os anuncios do utilizador.
	vector<Anuncio*> getAnuncios();
	//!Funcao get para os negocios do utilizador.
	TabNeg getNegocios() const;
	//!Funcao get para os dados do utilizador que sao visiveis.
	/*!
	 \sa Contacto -> getVisiveis()
	 */
	bool* getDadosVisiveis();
	//!!Funcao set para o nome.
	void setNome(string var);
	//!Funcao set para o numero de telefone.
	void setTelefone(string var);
	//!Funcao set para o email.
	void setEmail(string var);
	//!Funcao set para a freguesia.
	void setFreguesia(string var);
	//!Funcao set para o concelho.
	void setConcelho(string var);
	//!Funcao set para o distrito.
	void setDistrito(string var);

	//!Funcao get para o negocio mais recente
	Negocio* getUltimoNegocio() const;
	//!Funcao get para o vetor de negocios
	vector<Negocio*> getVetorNegocios() const;
	//!Funcao get que devolve um vetor de negocios de uma dada categoria
	vector<Negocio*> getVetorNegociosCategoria(string categoria) const;
	//!Funcao get que devolve um vetor de negocios de um determinado tipo
	vector<Negocio*> getVetorNegociosTipo(int tipo) const;

	//!Overload do operador < para o Utilizador
	bool operator< (const Utilizador & u) const;

};


//!Overload do operador de inser��o para guardar dados relativos aos utilizadores
ostream & operator<<(ostream & o, Utilizador & u);



//! Excepcao Anuncio Inexistente
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
	 \sa Anuncio
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
