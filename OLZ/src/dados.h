#ifndef DADOS_H_
#define DADOS_H_
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Dados{
public:

	virtual void ler(ifstream& in ,bool escreve = false) =0;
	virtual void escrever(ofstream& out) = 0;
};

#endif
