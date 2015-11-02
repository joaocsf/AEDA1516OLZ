#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include "utilidades.h"
#include "contacto.h"
#include "data.h"
#include "comum.h"
#include "dados.h"

#define ESTADO_NOVO 0
#define ESTADO_USADO 1
#define ESTADO_FUNCIONAL 2
#define ESTADO_PECAS 3

#define A_IDENFICADOR 0
#define A_TITULO 1
#define A_CATEG 2
#define A_DESC 3
#define A_N_VIS 4
#define A_VISIVEL 5
#define A_PRECO 0
#define A_NEGOCIAVEL 1
#define A_ESTADO 2




class Anuncio : public Dados{
	static int _ID;

	int _identificador;
	string _titulo;
	string _categ_produto;
	string _descricao;
	int _num_vizualizacoes;
	bool _visivel;
	Data _data;
	vector<Imagem> _imagens;
	vector<Contacto> _contactos;//contatos realizados pelo site entre comprador e anunciante

public:
	Anuncio(){}
	Anuncio(string titulo,string categ_produto,string descricao,Data date);
	//~Anuncio();
	static int getIDGlobal();
	int getID() const;
	Utilizador* _user;
	void enviarMensagem(Contacto c);
	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);
	virtual void setUser(Utilizador* user);
	virtual string getInfo() const;
	virtual Utilizador* getUser();
	void AdicionarImagem(Imagem img);
	void alterarVisibilidade(bool vis);
	bool getVisibilidade();
};



class AnuncioVenda: public Anuncio{
	float _preco;
	bool _negociavel;
	int _estado; //Usar ESTADO_*
public:
	AnuncioVenda(){}
	AnuncioVenda(string titulo,string categ_produto,string descricao,Data date,float preco,bool negociavel, int estado);
	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);
	virtual string getInfo() const;
};

class AnuncioCompra: public Anuncio{
	AnuncioVenda *_anuncioVenda; //anuncio de venda quando é diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
public:
	AnuncioCompra(){}
	AnuncioCompra(string titulo,string categ_produto,string descricao,Data date);
	void setAnuncioVenda(AnuncioVenda* anuncio);
	AnuncioVenda* getAnuncioVenda();
	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);
	virtual string getInfo() const;

};





#endif
