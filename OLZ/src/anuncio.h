#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Anuncio{
public:
	Anuncio();
	Anuncio(string Titulo,string categ_produto,string descricao,string estado,float preco,bool negociavel);
	~Anuncio();

protected:
	string titulo;
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

class AnuncioVenda: public Anuncio{
	//membros-dado
public:
}

class AnuncioCompra: public Anuncio{
	AnuncioVenda *a; //anuncio de venda quando é diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
public:
}





#endif
