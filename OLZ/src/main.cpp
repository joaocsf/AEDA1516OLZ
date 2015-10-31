#include <iostream>
#include <fstream>
#include <vector>
#include "dadospessoais.h"
using namespace std;




int main(){
	vector<DadosPessoais> dadosPessoais;
	dadosPessoais.push_back(DadosPessoais("Nuno", "123", ""));
	dadosPessoais.push_back(DadosPessoais("Manel", "321", "aff@blup.com"));
	dadosPessoais.push_back(DadosPessoais("Carlota", "nA", "c@c.c"));
	dadosPessoais.push_back(DadosPessoais("Andreia", "", "naoSei@cenas.com"));

	ofstream file("testeDados.txt");

	for (int i = 0; i < dadosPessoais.size(); ++i) {
		dadosPessoais[i].escrever(file);
	}

	ifstream file1("testeDados.txt");
	string linha;

	vector<DadosPessoais> dadosPessoais2;
	while(getline(file1,linha)){
		if(linha == "D"){
			DadosPessoais dTemp;
			dTemp.ler(file1);
			dadosPessoais2.push_back(dTemp);
		}
	}
	for (int i = 0; i < dadosPessoais2.size(); ++i) {
		cout <<dadosPessoais[i].getInfo() <<endl;
		cout <<dadosPessoais2[i].getInfo() <<endl;
	}


	return 0;
}
