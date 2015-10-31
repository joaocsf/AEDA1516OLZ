#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include "utilidades.h"
#include "contacto.h"
#include "data.h"
#include "comum.h"
#include "dados.h"

#define ESTADO_NOVO
#define ESTADO_USADO
#define ESTADO_FUNCIONAL
#define ESTADO_PECAS

class Anuncio : public Dados{
public:
	Anuncio();
	Anuncio(string titulo,string categ_produto,string descricao,Data date);
	//~Anuncio();
	static int getID();
	Utilizador* _user;
private:
	static int _ID;
	string _titulo;
	string _categ_produto;
	string _descricao;
	vector<Imagem> _imagens;
	Data _data;
	vector<Contacto> _contactos;//contatos realizados pelo site entre comprador e anunciante
	int _indentificador;
	int _num_vizualizacoes;
};



class AnuncioVenda: public Anuncio{
	float _preco;
	bool _negociavel;
	int _estado; //Usar ESTADO_*
public:
	AnuncioVenda(string titulo,string categ_produto,string descricao,Data date,float preco,bool negociavel, int estado);
	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);
};

class AnuncioCompra: public Anuncio{
	AnuncioVenda *_anuncioVenda; //anuncio de venda quando é diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
public:
	AnuncioCompra(string titulo,string categ_produto,string descricao,Data date);
	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);
};





#endif
