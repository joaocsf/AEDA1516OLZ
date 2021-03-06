#include "utilizador.h"

int Utilizador::_ID = 1;

Utilizador::Utilizador() {
}

Utilizador::Utilizador(DadosPessoais contacto, Localizacao loc) {
	_local = loc;
	_contacto = contacto;
	_identificador = _ID++;
}

Utilizador::~Utilizador(){//alterei Tabneg
	for (unsigned int i = 0; i < _anuncios.size(); ++i) {
		delete(_anuncios[i]);

	}
	TabNeg::iterator it=_negociosConcluidos.begin();

	while(it != _negociosConcluidos.end()){
		delete(*it);
		it++;
	}


	/*
	for (unsigned int i = 0; i< _negociosConcluidos.size(); ++i){
		delete(_negociosConcluidos[i]);
	}
*/
}

int Utilizador::getID() const {
	return _identificador;
}

int Utilizador::getIDGlobal() {
	return _ID;
}

int Utilizador::setIDGlobal(int id) {
	_ID = id;
}

bool*  Utilizador::getDadosVisiveis(){
	return _contacto.getVisiveis();
}

bool Utilizador::AdicionarAnuncio(Anuncio* anuncio) {
	_anuncios.push_back(anuncio);
	return true;
}

bool Utilizador::RemoverAnuncio(Anuncio* anuncio) {
	for (unsigned int var = 0; var < _anuncios.size(); var++) {
		if (_anuncios[var] == anuncio) {
			_anuncios.erase(_anuncios.begin() + var);
			return true;
		}
	}
	throw AnuncioInexistente(anuncio);
}

bool Utilizador::RemoverAnuncio(int id) {

	for (unsigned int var = 0; var < _anuncios.size(); var++) {
		if (_anuncios[var]->Anuncio::getID() == id) {

			if (_anuncios[var]->getTipo() == TIPO_VENDA) {
				for (unsigned int i = 0; i < _anuncios.size(); ++i) {
					if (_anuncios[i]->getTipo() == TIPO_COMPRA) {
						AnuncioCompra* ac =dynamic_cast<AnuncioCompra*>(_anuncios[i]);
						if(ac->getAnuncioVenda() != NULL){
							if (ac->getAnuncioVenda()->getID() == id) {
								ac->setAnuncioVenda(NULL);
								break;
							}
						}
					}
				}
			}else{
				AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(_anuncios[var]);
				ac->setAnuncioVenda(NULL);
			}


			free(_anuncios[var]);
			_anuncios.erase(_anuncios.begin() + var);
			return true;
		}
	}

	throw AnuncioInexistente(id);
}

DadosPessoais Utilizador::getDadosPessoais() {
	return this->_contacto;
}

Localizacao Utilizador::getLocalizacao() {
	return _local;
}

Anuncio* Utilizador::procurarAnuncio(int id) {
	for (unsigned int i = 0; i < _anuncios.size(); ++i) {
		if (_anuncios[i]->getID() == id)
			return _anuncios[i];
	}
	return NULL;
}

bool Utilizador::FecharNegocio(Anuncio* anuncio, float montante, Data data) {//alterei
	Negocio* neg = NULL;
	/*
	for (unsigned int i = 0; i < vetorAnuncios->size(); ++i) {

		if(anuncio->getID() == (*vetorAnuncios)[i]->getID()){
			vetorAnuncios->erase(vetorAnuncios->begin() + i--);
			if(anuncio->getTipo() == TIPO_VENDA)
				break;
			else if(anuncio->getTipo() == TIPO_COMPRA)
				if(dynamic_cast<AnuncioCompra*>(anuncio)->getAnuncioVenda() == NULL)
					break;
		}
		if(anuncio->getTipo() == TIPO_COMPRA){
			AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(anuncio);
			if(ac->getAnuncioVenda() !=NULL)
				if(ac->getAnuncioVenda()->getID() == (*vetorAnuncios)[i]->getID())
					vetorAnuncios->erase(vetorAnuncios->begin() + i--);
		}
	}
	/**/

	for (unsigned int i = 0; i < _anuncios.size(); i++) {

		if (_anuncios[i]->getID() == anuncio->getID()) {

			_anuncios[i]->setVisibilidade(false);
			neg = new Negocio(anuncio, montante,data);

			if (_anuncios[i]->getTipo() == TIPO_COMPRA){
				AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(_anuncios[i]);
				if(ac->getAnuncioVenda() != NULL)
					ac->getAnuncioVenda()->setVisibilidade(false);
				break;
			}
		}

		if(anuncio->getTipo() == TIPO_VENDA){
			AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(_anuncios[i]);
			if (ac != NULL){
				if(ac->getAnuncioVenda()!=NULL){
					if (ac->getAnuncioVenda()->getID() == anuncio->getID()) {
						ac->setAnuncioVenda(NULL);
					}
				}
			}
		}
	}
	if (neg == NULL) {
		throw AnuncioInexistente(anuncio);
	}
//alterrei aqui
	_negociosConcluidos.insert(neg);
	//_negociosConcluidos.push_back(neg);
	return true;
}

//retirar n�o � preciso
bool Utilizador::AlteraContacto(string telefone, string email) {
	this->_contacto.alterarEmail(email);
	this->_contacto.alterarTelefone(telefone);
	return true;
}

void Utilizador::ler(ifstream& in, bool escreve) {//alterei

	string linha;
	int index = 0;
	while (getline(in, linha)) {
		switch (index) {
		case UT_CONTACTO:
			if (linha == "D")
				_contacto.ler(in);
			else
				cout << "MERDOU CONTACTO" << linha << endl;
			break;
		case UT_FREGUESIA:
			_local.freguesia = linha;
			break;
		case UT_CONCELHO:
			_local.concelho = linha;
			break;
		case UT_DISTRITO:
			_local.distrito = linha;
			break;
		case UT_IDENTIFICADOR:
			stringstream(linha) >> _identificador;
			break;
		default:

			if (linha == "AV") {
				Anuncio* A = new AnuncioVenda();
				A->setUser(this);
				A->ler(in);
				AdicionarAnuncio(A);
				//if (A->getVisibilidade())
					//vetorAnuncios->push_back(A);
			} else if (linha == "AC") {
				Anuncio* AC = new AnuncioCompra();
				AC->setUser(this);
				AC->ler(in);
				AdicionarAnuncio(AC);
				//if (AC->getVisibilidade())
					//vetorAnuncios->push_back(AC);
			} else if (linha == "N") {
				Negocio* N = new Negocio();
				N->setUser(this);
				N->ler(in);
				//alterei aqui
				_negociosConcluidos.insert(N);
				//_negociosConcluidos.push_back(N);
			} else if (linha != "#U") {
				stringstream ss;
				ss << "Erro Leitura Utilizador. Encontrado:" << linha
						<< " Esperado:#U / N / AC / AV";
				throw ErroLeitura(ss.str());
			} else {
				return;
			}
			break;
		}

		index++;
	}

}
void Utilizador::escrever(ofstream& out) {//alterei
	out << "U" << endl;
	_contacto.escrever(out);
	out << _local.freguesia << endl;
	out << _local.concelho << endl;
	out << _local.distrito << endl;
	out << _identificador << endl;
	for (unsigned int i = 0; i < _anuncios.size(); ++i) {
		if (dynamic_cast<AnuncioVenda*>(_anuncios[i]) != NULL) {
			_anuncios[i]->escrever(out);
		}
	}
	for (unsigned int i = 0; i < _anuncios.size(); ++i) {
		if (dynamic_cast<AnuncioCompra*>(_anuncios[i]) != NULL) {
			_anuncios[i]->escrever(out);
		}
	}
//alterei aqui
	TabNeg::iterator it=_negociosConcluidos.begin();

	while(it !=_negociosConcluidos.end()){
		(*it)->escrever(out);
		it++;
	}

/*
	for (unsigned int i = 0; i < _negociosConcluidos.size(); ++i) {
		_negociosConcluidos[i]->escrever(out);
	}
*/
	out << "#U" << endl;

}

string Utilizador::getInfo() const {
	string info;
	stringstream ss;
	ss << _identificador;
	info += "Identificador: " + ss.str() + "\n";
	info += "Contacto \n" + _contacto.getInfo();
	info += "LOC \n" + _local.freguesia + "\n";
	info += _local.concelho + "\n";
	info += _local.distrito + "\n";
	for (unsigned int i = 0; i < _anuncios.size(); ++i) {
		info += _anuncios[i]->getInfo();
	}

	//alterei aqui-------------

	TabNeg::const_iterator it=_negociosConcluidos.begin();

	while(it !=_negociosConcluidos.end()){
		info += (*it)->getInfo();
		it++;
	}
	//----------------
	/*
	for (unsigned int i = 0; i < _negociosConcluidos.size(); ++i) {
		info += _negociosConcluidos[i]->getInfo();
	}
	 */

	info += "\n";

	return info;
}

vector<Anuncio*> Utilizador::getAnuncios(bool venda) {
	vector<Anuncio*> res;
	for (int i = 0; i < _anuncios.size(); ++i) {
		if (_anuncios[i]->getTipo() == TIPO_VENDA && venda){
			if(_anuncios[i]->getVisibilidade())
				res.push_back(_anuncios[i]);
		}
		else if (_anuncios[i]->getTipo() == TIPO_COMPRA && !venda)
			if(_anuncios[i]->getVisibilidade())
				res.push_back(_anuncios[i]);
	}

	return res;

}

vector<Anuncio*> Utilizador::getAnuncios(){
	return _anuncios;
}

//alterei
TabNeg Utilizador::getNegocios() const{
	return _negociosConcluidos;
}

//set
void Utilizador::setNome(string var){
	_contacto.alterarNome(var);
}
void Utilizador::setTelefone(string var){
	_contacto.alterarTelefone(var);
}
void Utilizador::setEmail(string var){
	_contacto.alterarEmail(var);
}
void Utilizador::setFreguesia(string var){
	_local.freguesia=var;
}
void Utilizador::setConcelho(string var){
	_local.concelho=var;
}
void Utilizador::setDistrito(string var){
	_local.distrito=var;
}


Negocio* Utilizador::getUltimoNegocio() const{
	Negocio *n;
	n= *(_negociosConcluidos.begin());

	TabNeg::const_iterator it=_negociosConcluidos.begin();
	it++;

	while(it != _negociosConcluidos.end()){
		if((*it)->getIdentificador() > n->getIdentificador())
			n= (*it);
		it++;
	}

	return n;
}

bool Utilizador::operator< (const Utilizador & u) const{//alterei
	if(this->_negociosConcluidos.size() < u.getNegocios().size())
		return true;

	if(this->_negociosConcluidos.size() == u.getNegocios().size()){
		//alterei
		return (getUltimoNegocio()->getData() < u.getUltimoNegocio()->getData());
		//return (this->_negociosConcluidos[this->_negociosConcluidos.size()-1]->getData() < u.getNegocios()[u.getNegocios().size()-1]->getData());
	}

	return false;

}

//getvetor negocios---------------------
vector<Negocio*> Utilizador::getVetorNegocios() const{
	vector<Negocio*> res;

	TabNeg::const_iterator it = _negociosConcluidos.begin();

	while(it != _negociosConcluidos.end()){
		res.push_back(*it);
		it++;
	}

	return res;
}


vector<Negocio*> Utilizador::getVetorNegociosCategoria(string categoria) const{
	vector<Negocio*> res;

	TabNeg::const_iterator it = _negociosConcluidos.begin();

	while(it != _negociosConcluidos.end()){
		if((*it)->getAnuncio()->getCategoria() == categoria)
			res.push_back(*it);
		it++;
	}

	return res;
}

vector<Negocio*> Utilizador::getVetorNegociosTipo(int tipo) const{
	vector<Negocio*> res;

	TabNeg::const_iterator it = _negociosConcluidos.begin();

	while(it != _negociosConcluidos.end()){
		if((*it)->getAnuncio()->getTipo() == tipo)
			res.push_back(*it);
		it++;
	}

	return res;
}


ostream & operator<<(ostream & o, Utilizador & u){
	DadosPessoais dados= u.getDadosPessoais();

	o << dados << endl;
	o << "Distrito: " << u.getLocalizacao().distrito << endl;
	o << "Concelho: " << u.getLocalizacao().concelho << endl;
	o << "Freguesia: " << u.getLocalizacao().freguesia<< endl;

	return o;
}

















