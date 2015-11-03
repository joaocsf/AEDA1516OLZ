#include "dadospessoais.h"

DadosPessoais::DadosPessoais(){
	for (int i = 0; i < VIS_TOTAL; ++i)
			visiveis[i]=true;
}

DadosPessoais::DadosPessoais(string nome, string telefone, string email) {
	this->nome = nome;
	this->telefone = telefone;
	this->email = email;
	for (int i = 0; i < VIS_TOTAL; ++i)
		visiveis[i]=true;
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

void DadosPessoais::ler(ifstream& in, bool escreve) {
	string linha;
	int index = 0;
	while (getline(in, linha)) {
		//cout <<"["<< index<< "]" << linha << endl;
		switch (index) {
		case VIS_NOME:
			nome = linha;
			break;
		case VIS_TELEFONE:
			telefone = linha;
			break;
		case VIS_EMAIL:
			email = linha;
			break;
		case VIS_TOTAL:
			if (linha != "#D") {
				cout<<"MERDOU DADOSPESSOAIS! "<<linha<<endl ;
			} else{
				return; //tudo bem pode continuar.
			}
			break;
		default:
			break;
		}
		index++;
	}
}
void DadosPessoais::escrever(ofstream& out) {

	out <<"D"<< endl<< nome << endl << telefone << endl << email << endl << "#D" << endl;

}

//get

string DadosPessoais::getNome() const{
	return nome;
}

string DadosPessoais::getTelefone() const{
	 return telefone;
}

string DadosPessoais::getEmail() const{
	return email;
}

bool* DadosPessoais::getVisiveis(){
	return visiveis;
}

ostream & operator<<(ostream & o, DadosPessoais & dados){
	string info;
	for (int i = 0; i < 3; ++i) {
		if (dados.getVisiveis()[i]) {
			switch (i) {
			case VIS_NOME:
				info += "Nome: " + dados.getNome() + "\n";
				break;
			case VIS_TELEFONE:
				info += "Telefone: " + dados.getTelefone() + "\n";
				break;
			case VIS_EMAIL:
				info += "Email: " + dados.getEmail() + "\n";
				break;
			}
		}
	}

	o << info;

	return o;
}
