#include "anuncio.h"

int Anuncio::_ID=1;

//anuncio
Anuncio::Anuncio(string titulo,string categ_produto,string descricao,Data date){
	_num_vizualizacoes=0;
	_titulo=titulo;
	_categ_produto=categ_produto;
	_descricao=descricao;
	_data=date;
	_indentificador=_ID;
	_ID++;
}

//anuncio venda
AnuncioVenda::AnuncioVenda(string titulo,string categ_produto,string descricao,Data date,float preco,bool negociavel, EstadoProduto estado):
		Anuncio(titulo,categ_produto,descricao,date){
	_preco=preco;
	_negociavel= negociavel;
	_estado	= estado;
}

//anuncio compra
AnuncioCompra::AnuncioCompra(string titulo,string categ_produto,string descricao,Data date):
	Anuncio(titulo,categ_produto,descricao,date){
	_anuncioVenda=NULL;
}


