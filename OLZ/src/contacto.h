#ifndef CONTACTO_H_
#define CONTACTO_H_

#include "utilidades.h"
#include "dadospessoais.h"
#include "dados.h"


class Contacto: public Dados{

	string _mensagem;
	DadosPessoais _dados;
public:
	Contacto();
	Contacto(string mensagem, DadosPessoais dados);
	string getInfo()const;
	void setMensagem(string mensagem);

	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);

};



#endif
