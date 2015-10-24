#ifndef CONTACTO_H_
#define CONTACTO_H_

#include <iostream>
#include <vector>
#include <string>


class Contacto{
	std::string _nome;
	std::string _email;
	std::string _telefone;

	vector<std::string*> _visiveis; //podemos por aqui os dados que são visiveis e quando queremos fazer display fazemos display do vetor (Ocupar 2x espaco na memoria?)
	//bool _visiveis[3]; < sempre poupamos na memoria
public:
	Contacto(std::string nome,std::string mail, std::string ntelefone);
	//Mostra todas as Informacoes visiveis do utilizador
	std::string ObterInfo();


};



#endif
