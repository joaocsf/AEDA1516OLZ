#ifndef DATA_H_
#define DATA_H_

#include "utilidades.h"
#include "dados.h"

class Data : public Dados {
public:
	Data(){}
	Data(unsigned int a, unsigned int m, unsigned int d);
	void setAno(unsigned int a);
	void setMes(unsigned int m);
	void setDia(unsigned int d);
	void setData(unsigned int a, unsigned int m, unsigned int d);
	unsigned int getAno();
	unsigned int getMes();
	unsigned int getDia();
	void imprime();

	virtual void ler(ifstream& in, bool escreve = false);
	virtual void escrever(ofstream& out);

private:
	unsigned int ano;
	unsigned int mes;
	unsigned int dia;

};

#endif
