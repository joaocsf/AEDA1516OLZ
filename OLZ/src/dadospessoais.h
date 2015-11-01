#ifndef DADOSPESSOAIS_H_
#define DADOSPESSOAIS_H_

#include "utilidades.h"
#include "dados.h"


using namespace std;

#define VIS_NOME 0
#define VIS_TELEFONE 1
#define VIS_EMAIL 2
#define VIS_TOTAL 3

class DadosPessoais : public Dados {

	string nome;
	string telefone;
	string email;

	bool visiveis[VIS_TOTAL]; //podemos por aqui os dados que são visiveis e quando queremos fazer display fazemos display do vetor
public:
	string getNome();
	DadosPessoais();
	DadosPessoais(string nome, string telefone, string email);

	/* "Altera 'O' nome"
	 */
	void alterarNome(string novoNome);

	/* "Altera 'O' telefone"
	 */
	void alterarTelefone(string novoTelefone);

	/* "Altera 'O' e-mail"
	 */
	void alterarEmail(string novoEmail);

	/*Define a visibilidade do email.
	 */
	void visibilidadeEmail(bool visivel);

	/*Define a visibilidade do Nome.
	 */
	void visibilidadeNome(bool visivel);

	/*Define a visibilidade do Telefone
	 */
	void visibilidadeTelefone(bool visivel);
	/*Devolve informacao visivel
	 */

	string getInfo() const;

	virtual void ler(ifstream& in, bool escreve = false);
	virtual void escrever(ofstream& out);

};

#endif
