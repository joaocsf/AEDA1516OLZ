#include "utilizador.h"

int Utilizador::_ID = 1;

Utilizador::Utilizador() {

}

Utilizador::Utilizador(DadosPessoais contacto, Localizacao loc) {
	_local = loc;
	_contacto = contacto;
	_identificador=_ID++;
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

bool Utilizador::FecharNegocio(Anuncio* anuncio, float montante) {
	Negocio* neg = NULL;
	for (unsigned int i = 0; i < _anuncios.size(); i++) {
		if (_anuncios[i] == anuncio) {
			neg = new Negocio(anuncio, montante); //Se encontrou o anuncio então cria o negocio;
			break;
		}
	}
	if (neg == NULL) {
		throw AnuncioInexistente(anuncio);
	}
	_negociosConcluidos.push_back(neg);
	return RemoverAnuncio(anuncio);
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
				cout << "Throw bla bla";
			break;
		case UT_FREGUESIA:
			_local.freguesia=linha;
			break;
		case UT_CONCELHO:
			_local.concelho = linha;
			break;
		case UT_DISTRITO:
			_local.distrito = linha;
			break;
		case UT_NEGOCIOS:
			break;
		case UT_ANUNCIOS:
			break;
		case UT_TOTAL:
			if(linha != "#U")
				cout <<"Throw BlaBle";
			else
				return;
		default:
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

	for (int i = 0; i < _anuncios.size(); ++i) {
		out << _anuncios[i]->getID();
	}
	out << endl;
	/*for (int i = 0; i <_negociosConcluidos.size(); ++i) {
	 out << _negociosConcluidos[i]->getID();
	 }*/
	 out <<endl;

	out << "#U" << endl;

}

string Utilizador::getInfo() const{
	string info;
	info +="Contacto \n" + _contacto.getInfo();
	info +="LOC \n"+ _local.freguesia +"\n";
	info += _local.concelho +"\n";
	info += _local.distrito +"\n";
	for (int i = 0; i < _anuncios.size(); ++i) {
		info += _anuncios[i]->getID() + " ";
	}
	info += "\n";
	info += "\n"; //negocios;

	return info;
}
