#ifndef DADOSPESSOAIS_H_
#define DADOSPESSOAIS_H_

#include "utilidades.h"
#include "dados.h"


using namespace std;

#define VIS_NOME 0
#define VIS_TELEFONE 1
#define VIS_EMAIL 2
#define VIS_TOTAL 3

//! Class DadosPessoais
/*!
 * Esta classe contem os dados pessoais relativos a um dado utilizador.
 */
class DadosPessoais : public Dados {
	//! nome
	/*!
	 * Nome do utlizador.
	 */
	string nome;
	//! telefone
	/*!
	 * Numero de telefone do utilizador.
	 */
	string telefone;
	//! email
	/*!
	 * email do utilizador.
	 */
	string email;
	//!visiveis
	/*!
	 * Vector referente a visibilidade de cada uma das variaveis da classe.
	 */
	bool visiveis[VIS_TOTAL]; //podemos por aqui os dados que são visiveis e quando queremos fazer display fazemos display do vetor
public:
	//!Funcao get para a informacao dos dados pessoais.
	/*!
	 \return Esta funcao retorna apenas os membros visiveis, apartir do vetor de visibilidade.
	 */
	string getInfo() const;
	//!Funcao get para o nome do utilizador
	/*!
	 \return Nome do Utilizador.
	 */
	string getNome() const;
	//!Funcao get para o telefone do utilizador.
	/*!
	 \return O numero de telefone do utilizador.
	 */
	string getTelefone() const;
	//!Funcao get para o email do utlizador.
	/*!
	 \return O email do utilizador.
	 */
	string getEmail() const;
	//!Funcao get para o vector de visibilidade.
	/*!
	 \return um apontador para os elementos booleanos relativos à visibilidade dos membros-dado.
	 */
	bool* getVisiveis();
	//!Construtor default.
	DadosPessoais();
	//!Overload do construtor com 3 parametros.
	/*!
	 \param nome do utilizador.
	 \param telefone do utilizador.
	 \param email do utilizador.
	 */
	DadosPessoais(string nome, string telefone, string email);
	//! Funcao para alterar o nome.
	/*!
	 \param novoNome do utilizador.
	 */
	void alterarNome(string novoNome);
	//!Funcao para alterar o telefone.
	/*!
	 \param novoTelefone do utilizador.
	 */
	void alterarTelefone(string novoTelefone);
	//!Funcao para alterar o email.
	/*!
	 \param novoEmail do utilizador.
	 */
	void alterarEmail(string novoEmail);
	//!Funcao para definir a visibilidade do parametro email.
	void visibilidadeEmail(bool visivel);
	//!Funcao para definir a visibilidade do parametro nome.
	void visibilidadeNome(bool visivel);
	//!Funcao para definir a visibilidade do parametro telefone.
	void visibilidadeTelefone(bool visivel);
	//!Funcao de leitura das informacoes dos dados pessoais de um ficheiro.
	virtual void ler(ifstream& in, bool escreve = false);
	//!Funcao de escrita das infromacoes dos dados pessoais para um ficheiro.
	virtual void escrever(ofstream& out);

};
//!Overload do operador de insercao para os dados pessoais
ostream & operator<<(ostream & o,DadosPessoais & dados);

#endif
