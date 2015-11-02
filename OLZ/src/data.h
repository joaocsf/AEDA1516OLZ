#ifndef DATA_H_
#define DATA_H_

#include "utilidades.h"
#include "dados.h"

#define DATA_ANO 0
#define DATA_MES 1
#define DATA_DIA 2



class Data : public Dados {
public:
	Data(){}
	Data(unsigned int a, unsigned int m, unsigned int d);
	void setAno(unsigned int a);
	void setMes(unsigned int m);
	void setDia(unsigned int d);
	void setData(unsigned int a, unsigned int m, unsigned int d);
	unsigned int getAno()const;
	unsigned int getMes()const;
	unsigned int getDia()const;
	void imprime();

	virtual void ler(ifstream& in, bool escreve = false);
	virtual void escrever(ofstream& out);
private:
	unsigned int ano;
	unsigned int mes;
	unsigned int dia;

};

bool operator==(const Data& d1, const Data& d2);
std::ostream & operator<<(ostream & o, const Data & d);


#endif
