#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include "utilidades.h"
#include "contacto.h"
#include "data.h"
#include <string>
#include <vector>

using namespace std;

class Anuncio{
public:
	Anuncio();
	Anuncio(string titulo,string categ_produto,string descricao,Data date);
	//~Anuncio();
	static int getID();
private:
	static int _ID;
	string _titulo;
	string _categ_produto;
	string _descricao;

	Data _data;
	vector<Contacto> _contactos;//contatos realizados pelo site entre comprador e anunciante
	int _indentificador;
	int _num_vizualizacoes;
};

enum EstadoProduto{
	NOVO,
	USADO_COMO_NOVO,
	FUNCIONAL,
	PARA_PECAS
};

class AnuncioVenda: public Anuncio{
	float _preco;
	bool _negociavel;
	EstadoProduto _estado;
public:
	AnuncioVenda(string titulo,string categ_produto,string descricao,Data date,float preco,bool negociavel, EstadoProduto estado);
};

class AnuncioCompra: public Anuncio{
	AnuncioVenda *_anuncioVenda; //anuncio de venda quando é diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
public:
	AnuncioCompra(string titulo,string categ_produto,string descricao,Data date);
};





#endif
