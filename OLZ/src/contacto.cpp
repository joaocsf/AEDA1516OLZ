#include "contacto.h"


Contacto::Contacto(string mensagem, DadosPessoais dados){
	_mensagem=mensagem;
	_dados=dados;
}

Contacto::Contacto(){

}

string Contacto::ObterInfo(){
	return _dados.getInfo();
}

void Contacto::setMensagem(string mensagem){
	_mensagem = mensagem;
}