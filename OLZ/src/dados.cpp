#include "dados.h"
#include "anuncio.h"
#include "utilizador.h"
#include "negocio.h"


vector<Utilizador*> Dados::lerFicheiro(ifstream& in){
	if(!in.good()){
		Anuncio::setIDGlobal(1);
		Utilizador::setIDGlobal(1);
		Negocio::setIDGlobal(1);
		return vector<Utilizador*>();
	}
	vector<Utilizador*> utilizadores;

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
				utilizadores.push_back(uTemp);
				n++;
			} catch (ErroLeitura erro) {
				cout << erro.getErro();
				getch();
			}

		}
	}

	return utilizadores;
}

void Dados::escreverFicheiro(ofstream& out, vector<Utilizador*> vetorUtilizadores){
	out << Anuncio::getIDGlobal() << " ";
	out << Utilizador::getIDGlobal() << " ";
	out << Negocio::getIDGlobal() << endl;
	for (unsigned int i = 0; i < vetorUtilizadores.size(); ++i) {
		vetorUtilizadores[i]->escrever(out);
	}
}
