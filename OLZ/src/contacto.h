#ifndef CONTACTO_H_
#define CONTACTO_H_

#include "utilidades.h"
#include "dadospessoais.h"



class Contacto{

	string mensagem;
	DadosPessoais dados;
public:
	Contacto(string nome,string mail, string ntelefone);
	//Mostra todas as Informacoes visiveis do utilizador
	string ObterInfo();


};



#endif
