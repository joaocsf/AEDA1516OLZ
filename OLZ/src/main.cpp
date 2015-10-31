#include <iostream>
#include <fstream>
#include <vector>
#include "dadospessoais.h"
#include "utilizador.h"

using namespace std;




int main(){
	vector<DadosPessoais> dadosPessoais;
	dadosPessoais.push_back(DadosPessoais("Nuno", "123", ""));
	dadosPessoais.push_back(DadosPessoais("Manel", "321", "aff@blup.com"));
	dadosPessoais.push_back(DadosPessoais("Carlota", "nA", "c@c.c"));
	dadosPessoais.push_back(DadosPessoais("Andreia", "", "naoSei@cenas.com"));


	Localizacao loc1;
	loc1.concelho="Penafiel";
	loc1.distrito="Porto";
	loc1.freguesia="Pieres";
	Localizacao loc2;
	loc2.freguesia="123";
	loc2.concelho="345";
	loc2.distrito="6789";
	Localizacao loc[] ={loc1, loc2};
	ofstream file("testeDados.txt");
	ifstream file1("testeDados.txt");



	vector<Utilizador> utilizadores;

	for (int i = 0; i < dadosPessoais.size(); ++i) {
		utilizadores.push_back(Utilizador(dadosPessoais[i], loc[i%2]));
	}


	for (int i = 0; i < utilizadores.size(); ++i) {
		utilizadores[i].escrever(file);
	}


	string linha;

	vector<Utilizador> utilizadores2;

	while(getline(file1,linha)){
		if(linha == "U"){

			Utilizador uTemp;
			uTemp.ler(file1);
			utilizadores2.push_back(uTemp);
		}
	}
	cout  <<endl;
	if(utilizadores.size() != utilizadores2.size()){
		cout <<"WTF?";
		return 0;
	}

	for (int i = 0; i < utilizadores.size(); ++i) {
		if(utilizadores[i].getInfo()!= utilizadores2[i].getInfo())
			cout<<"WTF MATE!";
		else
			cout << "Tudo Bom";
	}


	return 0;
}
