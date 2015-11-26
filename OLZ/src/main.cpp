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

	time_t agora= time(0);
	tm *ltm = localtime(&agora);
	Website::setData(Data(ltm->tm_year+1900,ltm->tm_mon+1,ltm->tm_mday));

	ifstream fileI("testeDados.txt");

	Website::lerFicheiro(fileI);

	//Website::menuTopNegocios();

	Menu::InterfaceSeletor();
	ofstream fileO("testeDados.txt");
	Website::guardarFicheiro(fileO);

	system("pause");
	return 0;
}
