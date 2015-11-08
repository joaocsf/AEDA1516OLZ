#include "dados.h"
#include "anuncio.h"
#include "utilizador.h"
#include "negocio.h"

vector<Anuncio *>* Dados::vetorAnuncios= NULL;
vector<Utilizador*>* Dados::vetorUtilizadores= NULL;
vector<Negocio* >* Dados::vetorNegocios = NULL;

void Dados::setVetorAnuncio(vector<Anuncio*>* anuncios){
	vetorAnuncios=anuncios;
}
void Dados::setVetorUtilizadores(vector<Utilizador*>* utilizadores){
	vetorUtilizadores=utilizadores;
}
void Dados::setVetorNegocios(vector<Negocio*>* negocios){
	vetorNegocios=negocios;
}

vector<Anuncio*>* Dados::getVetorAnuncio(){
	return vetorAnuncios;
}
vector<Utilizador*>* Dados::getVetorUtilizadores(){
	return vetorUtilizadores;
}
vector<Negocio*>* Dados::getVetorNegocios(){
	return vetorNegocios;
}

void Dados::lerFicheiro(ifstream& in){
	int n = 0;
	string linha;
	getline(in, linha);
	int temp;
	stringstream ss(linha);
	ss >> temp;
	Anuncio::setIDGlobal(temp);
	ss >> temp;
	Utilizador::setIDGlobal(temp);
	ss >> temp;
	Negocio::setIDGlobal(temp);

	while (getline(in, linha)) {

		if (linha == "U") {
			try {
				Utilizador* uTemp = new Utilizador();
				uTemp->ler(in);
				vetorUtilizadores->push_back(uTemp);
				n++;
			} catch (ErroLeitura erro) {
				cout << erro.getErro();
				getch();
			}

		}
	}
}

void Dados::escreverFicheiro(ofstream& out){
	out << Anuncio::getIDGlobal() << " ";
	out << Utilizador::getIDGlobal() << " ";
	out << Negocio::getIDGlobal() << endl;
	for (unsigned int i = 0; i < vetorUtilizadores->size(); ++i) {
		(*vetorUtilizadores)[i]->escrever(out);
	}
}
