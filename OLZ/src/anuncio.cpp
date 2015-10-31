#include "anuncio.h"
#include "data.h"

int Anuncio::_ID = 1;

int Anuncio::getID() {
	return _ID;
}


Anuncio::Anuncio(string titulo, string categ_produto, string descricao,
		Data date) :
		_num_vizualizacoes(0), _titulo(titulo), _categ_produto(categ_produto), _descricao(
				descricao), _data(date), _identificador(_ID++), _user(NULL) {
}

void Anuncio::ler(ifstream& in, bool escreve) {
	string linha;
	int index = 0;
	while (getline(in, linha)) {
		switch (index) {
		case A_IDENFICADOR:
			stringstream(linha)>>_identificador;
			break;
		case A_TITULO:
			_titulo = linha;
			break;
		case A_CATEG:
			_categ_produto = linha;
			break;
		case A_DESC:
			_descricao = linha;
			break;
		case A_VIS:
			stringstream(linha)>>_num_vizualizacoes;
			break;
		case A_DATA:
			_data.ler(in);
			break;
		default:
			if(linha == "I"){
				getline(in,linha);
				Imagem temp;
				temp.conteudo=linha;
				_imagens.push_back(temp);
				getline(in,linha);
			}else if(linha == "C"){
				Contacto cTemp;
				cTemp.ler(in);
				_contactos.push_back(cTemp);
			}else if(linha == "#V"){
				return;
			}else{
				cout <<"Merdou Anuncio \n";
			}
			break;
		}
		index++;
	}

}

void Anuncio::escrever(ofstream& out) {
	out << _identificador << endl;
	out << _titulo << endl;
	out << _categ_produto << endl;
	out << _descricao << endl;
	out << _num_vizualizacoes << endl;
	_data.escrever(out);
	for (int i = 0; i < _imagens.size(); ++i) {
		out << "I" << endl << _imagens[i].conteudo << endl << "#I" << endl;
	}
	for (int i = 0; i < _contactos.size(); ++i) {
		_contactos[i].escrever(out);
	}
	out <<"#V";//Sinaliza Fim vetor
}
void Anuncio::setUser(Utilizador* user){
	_user = user;
}

Utilizador* Anuncio::getUser(){
	return _user;
}


//anuncio venda
AnuncioVenda::AnuncioVenda(string titulo, string categ_produto,
		string descricao, Data date, float preco, bool negociavel, int estado) :
		Anuncio(titulo, categ_produto, descricao, date), _preco(preco), _negociavel(
				negociavel), _estado(estado) {
}

void AnuncioVenda::ler(ifstream& in, bool escreve) {
	Anuncio::ler(in);
	string linha;
	int index = 0;
	while (getline(in, linha)) {
		switch (index) {
		case A_PRECO:
			stringstream(linha)>>_preco;
			break;
		case A_NEGOCIAVEL:
			int temp;
			stringstream(linha)>>temp;
			_negociavel = temp;
			break;
		case A_ESTADO:
			stringstream(linha)>>_estado;
			break;
		default:
			if(linha == "#AV")
				return;
			else
				cout <<"Merdou Venda \n";
			break;
		}

		index++;
	}

}
void AnuncioVenda::escrever(ofstream& out) {
	out << "AV" << endl;
	Anuncio::escrever(out);
	out << _preco << endl;
	out << ((_negociavel)? 1: 0) << endl;
	out << _estado << endl;
	out << "#AV" << endl;

}

//anuncio compra
AnuncioCompra::AnuncioCompra(string titulo, string categ_produto,
		string descricao, Data date) :
		Anuncio(titulo, categ_produto, descricao, date), _anuncioVenda(NULL) {
}

void AnuncioCompra::ler(ifstream& in, bool escreve) {
	Anuncio::ler(in);
	string
	while(getline(in,))

}
void AnuncioCompra::escrever(ofstream& out) {
	out << "AC"<<endl;
	out << _anuncioVenda->getID();
	out <<"#AC"<<endl;
}

