#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Anuncio{
	static int proxID;
public:
	Anuncio();
	Anuncio(string Titulo,string categ_produto,string descricao,string estado,float preco,bool negociavel);
	~Anuncio();

protected:
	string titulo;
	string categ_produto;
	string descricao;
	//vetor imagens??
	//data criacao criar classe DATA?? e assim fica mais facil para fazermos compara�oes de datas e podemos fazer procura por data tambem
	int indentificador;
	int num_vizualizacoes;
	string estado;
	float preco;
	bool negociavel;
};

enum EstadoProduto{
	NOVO,
	USADO_COMO_NOVO,
	FUNCIONAL,
	PARA_PECAS
};

class AnuncioVenda: public Anuncio{
	//membros-dado
	EstadoProduto estado;
public:
};

class AnuncioCompra: public Anuncio{
	AnuncioVenda *a; //anuncio de venda quando � diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
public:
};





#endif
