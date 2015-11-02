#include "utilizador.h"

int Utilizador::_ID = 1;

Utilizador::Utilizador() {
	_identificador = _ID++;
}

Utilizador::Utilizador(DadosPessoais contacto, Localizacao loc) {
	_local = loc;
	_contacto = contacto;
	_identificador = _ID++;
}

int Utilizador::getID() const {
	return _identificador;
}

int Utilizador::getIDGlobal() {
	return _ID;
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
	for (int i = 0; i < _anuncios.size(); ++i) {
		if (_anuncios[i]->getID() == id)
			return _anuncios[i];
	}
	return NULL;
}

bool Utilizador::FecharNegocio(Anuncio* anuncio, float montante) {
	Negocio* neg = NULL;
	for (unsigned int i = 0; i < _anuncios.size(); i++) {
		if (_anuncios[i]->getID() == anuncio->getID()) {
			neg = new Negocio(anuncio, montante); //Se encontrou o anuncio ent�o cria o negocio;
			if (dynamic_cast<AnuncioVenda*>(_anuncios[i]) != NULL)
				break;
		}
		AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(_anuncios[i]);
		if (ac != NULL) {
			if (ac->getAnuncioVenda()->getID() == anuncio->getID()) {
				ac->setAnuncioVenda(NULL);
			}
		}
	}
	if (neg == NULL) {
		throw AnuncioInexistente(anuncio);
	}
	_negociosConcluidos.push_back(neg);
	anuncio->alterarVisibilidade(false);
}

bool Utilizador::AlteraContacto(string telefone, string email) {
	this->_contacto.alterarEmail(email);
	this->_contacto.alterarTelefone(telefone);
	return true;
}

void Utilizador::ler(ifstream& in, bool escreve) {

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
				if (A->getVisibilidade())
					Website::addAnuncio(A);
			} else if (linha == "AC") {
				Anuncio* AC = new AnuncioCompra();
				AC->setUser(this);
				AC->ler(in);
				AdicionarAnuncio(AC);
				if (AC->getVisibilidade())
					Website::addAnuncio(AC);
			} else if (linha == "N") {
				Negocio* N = new Negocio();
				N->setUser(this);
				N->ler(in);
				_negociosConcluidos.push_back(N);
			} else if (linha != "#U") {
				cout << "MERDOU UTILIZADOR!" << linha << endl;
			} else {
				return;
			}
			break;
		}

		index++;
	}

}
void Utilizador::escrever(ofstream& out) {
	out << "U" << endl;
	_contacto.escrever(out);
	out << _local.freguesia << endl;
	out << _local.concelho << endl;
	out << _local.distrito << endl;
	out << _identificador << endl;
	for (int i = 0; i < _anuncios.size(); ++i) {
		if (dynamic_cast<AnuncioVenda*>(_anuncios[i]) != NULL) {
			_anuncios[i]->escrever(out);
		}
	}
	for (int i = 0; i < _anuncios.size(); ++i) {
		if (dynamic_cast<AnuncioCompra*>(_anuncios[i]) != NULL) {
			_anuncios[i]->escrever(out);
		}
	}
	for (int i = 0; i < _negociosConcluidos.size(); ++i) {
		_negociosConcluidos[i]->escrever(out);
	}

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
	for (int i = 0; i < _anuncios.size(); ++i) {
		info += _anuncios[i]->getInfo();
	}
	for (int i = 0; i < _negociosConcluidos.size(); ++i) {
		info += _negociosConcluidos[i]->getInfo();
	}
	info += "\n";

	return info;
}
