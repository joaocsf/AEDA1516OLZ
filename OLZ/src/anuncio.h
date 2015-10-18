#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Anuncio{
	static int _proxID;
public:
	Anuncio();
	Anuncio(string Titulo,string categ_produto,string descricao,string estado,float preco,bool negociavel);
	~Anuncio();

protected:
	string _titulo;
	string _categ_produto;
	string _descricao;
	//vetor imagens??
	//data criacao criar classe DATA?? e assim fica mais facil para fazermos comparaçoes de datas e podemos fazer procura por data tambem
	int _indentificador;
	int _num_vizualizacoes;
	string _estado;
	float _preco;
	bool _negociavel;
};

enum EstadoProduto{
	NOVO,
	USADO_COMO_NOVO,
	FUNCIONAL,
	PARA_PECAS
};

class AnuncioVenda: public Anuncio{
	//membros-dado
	EstadoProduto _estado;
public:
};

class AnuncioCompra: public Anuncio{
	AnuncioVenda *_anuncioVenda; //anuncio de venda quando é diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
public:
};





#endif
