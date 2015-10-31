#include "contacto.h"


Contacto::Contacto(string mensagem, DadosPessoais dados){
	_mensagem=mensagem;
	_dados=dados;
}

Contacto::Contacto(){

}

string Contacto::getInfo() const{
	string info = _mensagem;
	info += "\n";
	info +=_dados.getInfo();
	return info;
}

void Contacto::setMensagem(string mensagem){
	_mensagem = mensagem;
}

void Contacto::ler(ifstream& in,bool escreve){
	string linha;
	int index = 0;
	while(getline(in, linha)){
		switch (index) {
			case 0:
				_mensagem = linha;
				break;
			default:
				if(linha == "D"){
					_dados.ler(in);
				}else if(linha == "#C"){
					return;
				}else{
					cout <<"ContactoMerdou";
				}
				break;
		}
		index++;
	}
}
void Contacto::escrever(ofstream& out){
	out << "C"<< endl;
	out << _mensagem<< endl;
	_dados.escrever(out);
	out << "#C"<< endl;
}
