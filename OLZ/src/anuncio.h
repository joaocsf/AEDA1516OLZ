#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include "utilidades.h"
#include "contacto.h"

class Anuncio{
public:
	Anuncio();
	Anuncio(string titulo,string categ_produto,string descricao,string estado,float preco,bool negociavel);
	~Anuncio();

protected:
	static int _ID;
	string _titulo;
	string _categ_produto;
	string _descricao;
	//vetor imagens??
	//data criacao criar classe DATA?? e assim fica mais facil para fazermos comparaçoes de datas e podemos fazer procura por data tambem
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

};

class AnuncioCompra: public Anuncio{
	AnuncioVenda *_anuncioVenda; //anuncio de venda quando é diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
public:
};





#endif
