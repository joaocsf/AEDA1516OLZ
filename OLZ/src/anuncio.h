#include <iostream>
#include <vector>
#include <string>


#ifndef ANUNCIO_H_
#define ANUNCIO_H_

using namespace std;

class anuncio{
public:
	anuncio();
	anuncio(string Titulo,string categ_produto,string descricao,string estado,float preco,bool negociavel);

protected:
	string Titulo;
	string categ_produto;
	string descricao;
	//vetor imagens??
	//data criacao criar classe DATA?? e assim fica mais facil para fazermos comparaçoes de datas e podemos fazer procura por data tambem
	static int indentificador;
	static int num_vizualizacoes;
	string estado;
	float preco;
	bool negociavel;
}

class anuncioCompra: public anuncio{
	anuncioVenda *a; //anuncio de venda quando é diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
public:
}


class anuncioVenda: public anuncio{
	//menbros-dado
public:
}


#endif
