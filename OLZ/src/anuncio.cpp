#include "anuncio.h"

int Anuncio::_ID=1;


Anuncio::Anuncio(string titulo,string categ_produto,string descricao,string estado,float preco,bool negociavel){
	_num_vizualizacoes=0;
	_titulo=titulo;
	_categ_produto=categ_produto;
	_descricao=descricao;
	_indentificador=_ID;
	_ID++;
}



