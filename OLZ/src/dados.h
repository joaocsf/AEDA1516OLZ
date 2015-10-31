#ifndef DADOS_H_
#define DADOS_H_
#include <iostream>
#include <fstream>

using namespace std;

class Dados{
public:

	virtual void ler(ifstream& in) =0;
	virtual void escrever(ofstream& out) = 0;
};

#endif
