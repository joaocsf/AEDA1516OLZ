#include "negocio.h"
#include "utilizador.h"

int Negocio::_ID = 1;

Negocio::Negocio(Anuncio* anun, float valor, Data data){
	_ptr_anuncio = anun;
	_montante = valor;
	_identificador = _ID++;
	_data=data;
}

Negocio::~Negocio(){
	_user=NULL;
	_ptr_anuncio=NULL;
}

int Negocio::getID() {
	return _identificador;
}
int Negocio::getIDGlobal() {
	return _ID;
}

int Negocio::setIDGlobal(int id){
	_ID=id;
}

void Negocio::setUser(Utilizador* user) {
	_user = user;
}

string Negocio::getInfo() const {
	string info;
	stringstream ss;
	ss << "NEGOCIO:" << endl;
	ss << " ID: " << _identificador << endl;
	ss << " AnuncioID: " << _ptr_anuncio->getID() << endl;
	ss << " Montante: " << _montante << endl;
	ss << " Data: " << _data.getDia() << "/" << _data.getMes() << "/"
			<< _data.getAno() << endl;

	return ss.str() + info;
}

void Negocio::ler(ifstream& in, bool escreve) {
	int index = 0;
	string linha;
	while (getline(in, linha)) {
		switch (index) {
		case N_MONTANTE:
			stringstream(linha) >> _montante;
			break;
		case N_IDENTIFICADOR:
			stringstream(linha) >> _identificador;
			break;
		case N_ANUNCIO_ID:
			int id;
			stringstream(linha) >> id;
			_ptr_anuncio = _user->procurarAnuncio(id);
			break;
		default:
			if (linha == "DAT") {
				_data.ler(in);
			} else if (linha == "#N") {
				return;
			} else {
				stringstream ss;
				ss << "Erro Leitura Negocio. Encontrado:" << linha <<" Esperado:#N / DAT";
				throw ErroLeitura(ss.str());
			}
			break;
		}
		index++;
	}
}
void Negocio::escrever(ofstream& out) {
	out << "N" << endl;
	out << _montante << endl;
	out << _identificador << endl;
	if (_ptr_anuncio != NULL)
		out << _ptr_anuncio->getID();
	out << endl;
	_data.escrever(out);
	out << "#N" << endl;
}

Anuncio* Negocio::getAnuncio(){
	return _ptr_anuncio;
}

float Negocio::getMontante() const{
	return _montante;
}

bool Negocio::trocou(){

	if(_ptr_anuncio->getTipo()==TIPO_VENDA){
		return false;
	}else{
		AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(_ptr_anuncio);
		if(ac->getAnuncioVenda() == NULL)
			return false;
	}
	return true;
}

Data Negocio::getData()const{
	return _data;
}

ostream & operator<<(ostream & o, Negocio& n){

	o<<"Finalizado em:"<<n.getData()<<endl;
	if(!n.trocou()){
		o<<"Montante: "<<n.getMontante()<<endl;
		if(n.getAnuncio()->getTipo() == TIPO_COMPRA){
			AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(n.getAnuncio());
			o << (*ac);
		}else{
			AnuncioVenda* av = dynamic_cast<AnuncioVenda*>(n.getAnuncio());
			o<<(*av);
		}
	}
	else{
		o<<"Este negocio resultou de uma toca."<<endl;
		AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(n.getAnuncio());
		o << (*ac);
		cout << "Trocou por:-----------------------------------------------"<< endl;
		o << (*ac->getAnuncioVenda());
	}

	return o;

}
