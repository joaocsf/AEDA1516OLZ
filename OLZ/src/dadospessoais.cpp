#include "dadospessoais.h"

DadosPessoais::DadosPessoais(string nome, string telefone, string email) {
	this->nome = nome;
	this->telefone = telefone;
	this->email = email;
}

void DadosPessoais::alterarNome(string novoNome) {
	nome = novoNome;
}

void DadosPessoais::alterarTelefone(string novoTelefone) {
	telefone = novoTelefone;
}

void DadosPessoais::alterarEmail(string novoEmail) {
	email = novoEmail;
}

void DadosPessoais::visibilidadeEmail(bool visivel) {
	visiveis[2] = visivel;
}

void DadosPessoais::visibilidadeNome(bool visivel) {
	visiveis[0] = visivel;
}

void DadosPessoais::visibilidadeTelefone(bool visivel) {
	visiveis[1] = visivel;
}


string DadosPessoais::getInfo() const {
	string info;
	for (int i = 0; i < 3; ++i) {
		if (visiveis[i]) {
			switch (i) {
			case 0:
				info += nome + "\n";
				break;
			case 1:
				info += telefone + "\n";
				break;
			case 2:
				info += email + "\n";
				break;
			}
		}
	}
	return info;
}

