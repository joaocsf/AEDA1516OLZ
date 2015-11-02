#ifndef NEGOCIO_H_
#define NEGOCIO_H_


#include "data.h"
#include "dados.h"
//#include "comum.h"
#include "anuncio.h"
//#include "utilizador.h"


#define N_MONTANTE 0
#define N_IDENTIFICADOR 1
#define N_ANUNCIO_ID 2


class Negocio : public Dados{
	Anuncio *_ptr_anuncio;
	float _montante; // montatne da compra/venda
	Data _data;
	Utilizador* _user;
	static int _ID;
	int _identificador;
public:
	Negocio(){}
	Negocio(Anuncio* anun,float valor);
	//virtual ~Negocio();
	int getID();
	void setUser(Utilizador* user);
	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);
	string getInfo()const;
};


#endif
