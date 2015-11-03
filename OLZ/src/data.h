#ifndef DATA_H_
#define DATA_H_

#include "utilidades.h"
#include "dados.h"

#define DATA_ANO 0
#define DATA_MES 1
#define DATA_DIA 2


//!Class Data
/*!
 * Classe data para realizacao de operacoes com data, tal como anuncio e negocio.
 */
class Data : public Dados {
public:
	//! Construtor Default.
	Data(){}
	//!Overload do construtor com 3 parametros.
	/*!
	 \param a ano.
	 \param m mes.
	 \param d dia.
	 */
	Data(unsigned int a, unsigned int m, unsigned int d);
	//! Funcao set para o ano.
	/*!
	 \param a ano.
	 */
	void setAno(unsigned int a);
	//!Funcao set para o mes.
	/*!
	 \param m mes.
	 */
	void setMes(unsigned int m);
	//!Funcao set para o dia.
	/*!
	 \param d dia.
	 */
	void setDia(unsigned int d);
	//!Funcao set para a data.
	/*!
	 \param a ano.
	 \param m mes.
	 \param d dia.
	 */
	void setData(unsigned int a, unsigned int m, unsigned int d);
	//!Funcao get para o ano.
	unsigned int getAno()const;
	//!Funcao get para o mes.
	unsigned int getMes()const;
	//!Funcao get para o dia.
	unsigned int getDia()const;
	//!Funcao para imprimir a data.
	void imprime();
	//!Funcao para ler a data de um ficheiro.
	virtual void ler(ifstream& in, bool escreve = false);
	//!Funcao para escrever a data para um ficheiro.
	virtual void escrever(ofstream& out);
private:
	//! ano
	/*!
	 * Varivel Ano.
	 */
	unsigned int ano;
	//! mes
	/*!
	 * Variavel Mes.
	 */
	unsigned int mes;
	//! dia
	/*!
	 * Variavel Dia.
	 */
	unsigned int dia;

};

//!Overload do operador de igualdade para a classe Data.
bool operator==(const Data& d1, const Data& d2);
//!Overload do operator de insercao para a classe Data.
std::ostream & operator<<(ostream & o, const Data & d);


#endif
