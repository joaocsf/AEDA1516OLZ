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
	visiveis[VIS_EMAIL] = visivel;
}

void DadosPessoais::visibilidadeNome(bool visivel) {
	visiveis[VIS_NOME] = visivel;
}

void DadosPessoais::visibilidadeTelefone(bool visivel) {
	visiveis[VIS_TELEFONE] = visivel;
}



string DadosPessoais::getInfo() const {
	string info;
	for (int i = 0; i < 3; ++i) {
		if (visiveis[i]) {
			switch (i) {
			case VIS_NOME:
				info += nome + "\n";
				break;
			case VIS_TELEFONE:
				info += telefone + "\n";
				break;
			case VIS_EMAIL:
				info += email + "\n";
				break;
			}
		}
	}
	return info;
}

