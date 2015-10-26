#ifndef DADOSPESSOAIS_H_
#define DADOSPESSOAIS_H_

#include "utilidades.h"
#include <string>

using namespace std;

#define VIS_NOME 0
#define VIS_TELEFONE 1
#define VIS_EMAIL 2
#define VIS_TOTAL 3

class DadosPessoais {

	string nome;
	string telefone;
	string email;

	bool visiveis[VIS_TOTAL]; //podemos por aqui os dados que são visiveis e quando queremos fazer display fazemos display do vetor
public:

	DadosPessoais(){}
	DadosPessoais(string nome, string telefone, string email);

	/* "Altera 'O' nome" by Martins
	 */
	void alterarNome(string novoNome);

	/* "Altera 'O' telefone" by Martins
	 */
	void alterarTelefone(string novoTelefone);

	/* "Altera 'O' e-mail" by Martins
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

};

#endif
