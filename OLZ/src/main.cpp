#include <iostream>
#include <fstream>
#include <vector>
#include "dadospessoais.h"
#include "utilizador.h"
#include "data.h"
#include "menus.h"
#include <time.h>
using namespace std;

void GetKeys() {

	while (true) {
		if (kbhit()) {

			cout << getch() << endl;

		}
	}

}

void NovosDados() {
	vector<DadosPessoais> dadosPessoais;
	dadosPessoais.push_back(DadosPessoais("Nuno", "123", "."));
	dadosPessoais.push_back(DadosPessoais("Manel", "321", "aff@blup.com"));
	dadosPessoais.push_back(DadosPessoais("Carlota", "nA", "c@c.c"));
	dadosPessoais.push_back(DadosPessoais("Andreia", "", "naoSei@cenas.com"));

	Localizacao loc1;
	loc1.concelho = "Penafiel";
	loc1.distrito = "Porto";
	loc1.freguesia = "Pieres";
	Localizacao loc2;
	loc2.freguesia = "123";
	loc2.concelho = "345";
	loc2.distrito = "6789";
	Localizacao loc[] = { loc1, loc2 };
	ofstream file("testeDados.txt");
	ifstream file1("testeDados.txt");

	vector<Utilizador> utilizadores;

	for (int i = 0; i < dadosPessoais.size(); ++i) {
		utilizadores.push_back(Utilizador(dadosPessoais[i], loc[i % 2]));
	}

	Anuncio* a1 = new AnuncioVenda("Pasta para os dentes", "Produtos", "Cenas",
			Data(2015, 02, 12), 0.12f, false, ESTADO_FUNCIONAL);
	Anuncio* a2 = new AnuncioVenda("Bolachas", "Comida",
			"Bolachas com chocolate", Data(1111, 11, 11), 2.00f, false,
			ESTADO_NOVO);
	Anuncio* a3 = new AnuncioVenda("Peluche Bacalhau", "Decoracao",
			"Experimenta ;D", Data(2222, 22, 21), 15.00f, false, ESTADO_USADO);
	Anuncio* a4 = new AnuncioVenda("Shampu Para Tu", "Limpeza",
			"Ate te limpa a careca ho belho!", Data(2121, 21, 21), 0.01f, true,
			ESTADO_FUNCIONAL);
	Anuncio* a5 = new AnuncioVenda("uNave Espacial", "O que ser isto?", "Fake",
			Data(9999, 9999, 9999), 999.99f, true, ESTADO_PECAS);

	utilizadores[0].AdicionarAnuncio(a1);
	utilizadores[1].AdicionarAnuncio(a2);
	utilizadores[2].AdicionarAnuncio(a3);
	utilizadores[2].AdicionarAnuncio(a4);
	utilizadores[0].AdicionarAnuncio(a5);

	vector<Utilizador*> utils;
	for (int i = 0; i < utilizadores.size(); ++i) {
		utils.push_back(&utilizadores[i]);
	}

	Dados::setVetorUtilizadores(&utils);
	Dados::escreverFicheiro(file);
	string linha;

	vector<Utilizador*> utilizadores2;
	vector<Anuncio*> anuncios;

	Dados::setVetorUtilizadores(&utilizadores2);
	Dados::setVetorAnuncio(&anuncios);

	Dados::lerFicheiro(file1);
}

int main() {
	//NovosDados();

	time_t agora= time(0);
	tm *ltm = localtime(&agora);
	Website::setData(Data(ltm->tm_year+1900,ltm->tm_mon+1,ltm->tm_mday));

	cout<<Website::getData();
	//system("mode con:cols=60 lines=45");
	ifstream fileI("testeDados.txt");
	Website::lerFicheiro(fileI);
	Menu::InterfaceSeletor();
	ofstream fileO("testeDados.txt");
	Website::guardarFicheiro(fileO);

	system("pause");
	return 0;
	/**/
}
