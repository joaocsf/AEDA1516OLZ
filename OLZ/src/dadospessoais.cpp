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
	visiveis[VisibilidadeDados::EMAIL] = visivel;
}

void DadosPessoais::visibilidadeNome(bool visivel) {
	visiveis[VisibilidadeDados::NOME] = visivel;
}

void DadosPessoais::visibilidadeTelefone(bool visivel) {
	visiveis[VisibilidadeDados::TELEFONE] = visivel;
}


string DadosPessoais::getInfo() const {
	string info;
	for (int i = 0; i < VisibilidadeDados::TOTAL; ++i) {
		if (visiveis[i]) {
			switch (i) {
			case VisibilidadeDados::NOME:
				info += nome + "\n";
				break;
			case VisibilidadeDados::TELEFONE:
				info += telefone + "\n";
				break;
			case VisibilidadeDados::EMAIL:
				info += email + "\n";
				break;
			}
		}
	}
	return info;
}

