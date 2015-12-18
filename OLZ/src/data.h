#ifndef DATA_H_
#define DATA_H_

#include "utilidades.h"
#include "dados.h"

#define DATA_ANO 0
#define DATA_MES 1
#define DATA_DIA 2
#define DATA_HORA 3
#define DATA_MINUTOS 4



//!Class Data
/*!
 * Classe data para realizacao de operacoes com data, tal como anuncio e negocio.
 \sa Dados
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
	//! Funcao set para a hora.
	/*!
		 \param h hora.
	 */
	void setHora(unsigned int h);
	//! Funcao set para a minutos.
	/*!
			 \param m minutos.
	 */
	void setMinutos(unsigned int m);
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
	//!Funcao get para a hora.
	unsigned int getHora()const;
	//!Funcao get para a minutos.
	unsigned int getMinutos()const;

	//!Funcao para imprimir a data.
	void imprime();
	//!Funcao para ler a data de um ficheiro.
	virtual void ler(ifstream& in, bool escreve = false);
	//!Funcao para escrever a data para um ficheiro.
	virtual void escrever(ofstream& out);
	//!Funcao que adiciona um mes a data atual.
	/*!
	 * Esta funcao recebe a data atual e soma 1 mes a data
	 * E usada quando um utilizador paga para ter o seu anuncio com destaque
	 * A funcao calcula a data ate ao qual o anuncio vai ter destaque.
	 */
	void addMes();
	//!Overload do operator < para a classe data.
	bool operator< (const Data & d) const;
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
	//! hora
	/*!
	 * Variavel Hora.
	 */
	unsigned int hora;
	//! minuto
	/*!
	 * Variavel Minuto.
	 */
	unsigned int minutos;


};

//!Overload do operador de comparacao de igualdade para a classe Data.
bool operator==(const Data& d1, const Data& d2);
//!Overload do operator de insercao para a classe Data.
std::ostream & operator<<(ostream & o, const Data & d);


#endif
