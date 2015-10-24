#ifndef CONTACTO_H_
#define CONTACTO_H_

#include "utilidades.h"
#include "dadospessoais.h"



class Contacto{

	string mensagem;
	DadosPessoais dados;
public:
	Contacto(std::string nome,std::string mail, std::string ntelefone);
	//Mostra todas as Informacoes visiveis do utilizador
	std::string ObterInfo();


};



#endif
