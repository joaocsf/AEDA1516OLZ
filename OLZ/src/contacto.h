#ifndef CONTACTO_H_
#define CONTACTO_H_

#include "utilidades.h"
#include "dadospessoais.h"



class Contacto{

	string _mensagem;
	DadosPessoais _dados;
public:
	Contacto();
	Contacto(string mensagem, DadosPessoais dados);
	string ObterInfo();
	void setMensagem(string mensagem);
};



#endif
