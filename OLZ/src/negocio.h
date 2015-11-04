#ifndef NEGOCIO_H_
#define NEGOCIO_H_

#include "data.h"
#include "dados.h"
//#include "comum.h"
#include "anuncio.h"
//#include "utilizador.h"

#define N_MONTANTE 0
#define N_IDENTIFICADOR 1
#define N_ANUNCIO_ID 2

//!Class Negocio
/*!
 * Esta classe estancia um negocio que foi concliudo quer seja uma venda, compra ou troca.
 */
class Negocio: public Dados {
	//! ptr_anuncio
	/*!
	 * Apontador para o anuncio do negocio
	 */
	Anuncio *_ptr_anuncio;
	//! montante
	/*!
	 * Valor pago ou recebido no negocio.
	 */
	float _montante; // montatne da compra/venda
	//! data
	/*!
	 * Data da realizacao do negocio.
	 */
	Data _data;
	//! user
	/*!
	 * Utilizador referente ao negocio.
	 */
	Utilizador* _user;
	//! ID
	/*!
	 * Variavel global com o numero de identificacao do proximo negocio a ser criado.
	 */
	static int _ID;
	//! identificador
	/*!
	 * numero de identificacao do negocio.
	 */
	int _identificador;
public:
	//! Construtor default.
	Negocio() {
	}

	//! Overload do construtor com 3 parametros.
	/*!
	 \param anun Anuncio do negocio.
	 \param valor o valor que foi pago/recebido.
	 \param data de quando concluiu o negocio
	 */
	Negocio(Anuncio* anun, float valor, Data data);
	//virtual ~Negocio();
	//! Funcao get para o ID
	/*!
	 \return numero de identificacao do negocio.
	 */
	int getID();
	//!Funcao para alterar o utilizador.
	/*!
	 \param user Novo utilizador.
	 */
	void setUser(Utilizador* user);

	//!Funcao global para devolver o valor atual da variavel global ID.
	static int getIDGlobal();

	static int setIDGlobal(int id);

	//!Funcao de leitura das informacoes de um ficheiro.
	virtual void ler(ifstream& in, bool escreve = false);
	//! Funcao de escrita das informacoes para um ficheiro.
	virtual void escrever(ofstream& out);
	//!Funcao get para a informacao referente ao negocio.
	string getInfo() const;
	Anuncio* getAnuncio();
	float getMontante() const;
	Data getData()const;
	bool trocou();
};

ostream & operator<<(ostream & o, Negocio& n);

#endif
