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
	Data d(ltm->tm_year+1900,ltm->tm_mon+1,ltm->tm_mday);
	d.setHora(ltm->tm_hour);
	d.setMinutos(ltm->tm_min);
	Website::setData(d);

	ifstream fileI("testeDados.txt");

	Website::lerFicheiro(fileI);

	//Website::menuTopNegocios();

	Menu::InterfaceSeletor();
	ofstream fileO("testeDados.txt");
	Website::guardarFicheiro(fileO);

	system("pause");
	return 0;
}
