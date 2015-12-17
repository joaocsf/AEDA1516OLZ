#include <iostream>
#include <fstream>
#include <vector>
#include "dadospessoais.h"
#include "utilizador.h"
#include "data.h"
#include "menus.h"
#include <time.h>
using namespace std;


int main() {

	Website::AtualizarData();

	ifstream fileI("testeDados.txt");

	Website::lerFicheiro(fileI);

	//Website::menuTopNegocios();

	Menu::InterfaceSeletor();
	ofstream fileO("testeDados.txt");
	Website::guardarFicheiro(fileO);

	system("pause");
	return 0;
}
