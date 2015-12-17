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

#define TIPO_VENDA 1
#define TIPO_COMPRA 0

struct AnuncioHandler {
	Anuncio * a;
};

//!Class Anuncio
/*!
 * Classe anuncio que contem as informacoes e as funcoes relativas aos anuncios.
 */
class Anuncio: public Dados {
	//!ID
	/*!
	 * Variavel global da classe que contem o numero de identificacao do proximo anuncio a ser gerado.
	 */
	static int _ID;
	//! user
	/*!
	 * Utilizador deste anuncio.
	 \sa Utilizador
	 */
	Utilizador* _user;
	//! identificador
	/*!
	 * Numero de identificacao unico do anuncio.
	 */
	int _identificador;
	//! titulo
	/*!
	 * Titulo do anuncio.
	 */
	string _titulo;
	//! categ_produto
	/*!
	 * Categoria em que o produto do anuncio esta inserido.
	 */
	string _categ_produto;
	//! descricao
	/*!
	 * Descricao do produto.
	 */
	string _descricao;
	//! num_visualizacoes.
	/*!
	 * Contador de visualizacoes do anuncio.
	 */
	int _num_vizualizacoes;
	//! visivel.
	/*!
	 * Booleano com a visivilidade do anuncio.
	 */
	bool _visivel;
	//! data.
	/*!
	 * Data em que o anuncio foi criado.
	 \sa Data
	 */
	Data _data;
	//! imagens
	/*!
	 * Vetor com as imagens de um produto anunciado.
	 \sa Imagem
	 */
	vector<Imagem> _imagens;
	//! contactos
	/*!
	 * Vetor com os contactos realizador pelo site entre comprador e anunciante.
	 \sa Contacto
	 */
	vector<Contacto> _contactos;

	Data _data_destaque;

public:
	//! Construtor default.
	Anuncio() {
	}
	//!Destrutor.
	virtual ~Anuncio();
	//!Overload do construtor com 4 parametros.
	/*!
	 \param titulo do anuncio.
	 \param categ_produto categoria do produto.
	 \param descricao do anuncio.
	 \param date data do anuncio.
	 */
	Anuncio(string titulo, string categ_produto, string descricao, Data date);
	//!Funcao para enviar uma mensagem
	/*!
	 \param c contacto para o qual se vai enviar a mensagem.
	 */
	void enviarMensagem(Contacto c);
	//!Funcao de leitura das informacoes de um ficheiro.
	virtual void ler(ifstream& in, bool escreve = false);
	//!Funcao de escrita das informacoes para um ficheiro.
	virtual void escrever(ofstream& out);
	//!Funcao que adiciona um imagem ao vetor de imagens.
	/*!
	 \param img imagem que vai ser adicionada.
	 */
	void AdicionarImagem(Imagem img);
	//!Funcao que altera a visibilidade do anuncio.
	void alterarVisibilidade();
	//!Funcao de incrementacao das visualizacoes do anuncio.
	void visualizacao();
	//!Funcao set para o utilizador do anuncio.
	virtual void setUser(Utilizador* user);
	//!Funcao set para o numero de identificacao global dos anuncio.
	static void setIDGlobal(int id);
	//!Funcao set para o vetor de imagens referentes ao anuncio.
	void setImagens(vector<Imagem> img);
	//!Funcao que altera a visibilidade do anuncio.
	void setVisibilidade(bool vis);
	//!Funcao set para a data do anuncio.
	void setData(Data d);
	//!Funcao set para o numero de visualizacoes do anuncio.
	void setNVisualizacoes(int v);
	//!Funcao set para a descricao do anuncio.
	void setDescricao(string d);
	//!Funcao set para a categoria do produto.
	void setCategoria(string c);
	//!Funcao set para o titulo do anuncio.
	void setTitulo(string t);
	//!Funcao set para o numero de identificacao.
	void setIdentificador(int id);
	//!Funcao get para o numero de identificacao global dos anuncios.
	static int getIDGlobal();
	//!Funcao get para o numero de identifacao do anuncio.
	int getID() const;
	//!Funcao get para o tipo de anuncio (Compra/Venda)
	virtual int getTipo() const = 0;
	//!Funcao get para a informacao relativa ao anuncio.
	virtual string getInfo() const;
	//!Funcao get para o titulo e descricao do anuncio.
	string getTitulo_Descricao() const;
	//!Funcao get para a data do anuncio.
	Data getData() const;
	//!Funcao get para a categoria do anuncio.
	string getCategoria() const;
	//!Funcao get para o utilizador do anuncio.
	Utilizador* getUser();
	//!Funcao get para o titulo.
	string getTitulo() const;
	//!Funcao get para a visibilidade do anuncio.
	bool getVisibilidade();
	//!Funcao get para o numero de visualizacoes do anuncio.
	int getVisualizacoes() const;
	//!Funcao get para o vetor de imagens referentes ao anuncio.
	vector<Imagem> getImagens() const;
	//!Funcao get para o preco.
	virtual float getPreco() const;
	//!Funcao get para os contactos referentes ao anuncio.
	vector<Contacto> getContactos() const;
	//!Funcao get para a descricao do anuncio.
	string getDescricao() const;
	//!Funcao get para a data limite do anuncio.
	Data getDataLimite() const;
	//!Funcao para eliminar o vector de imagens do anuncio.
	void eliminaImagens();
};

//!Overload do operador de comparacao que vai ser utilizado na fila de prioridade
/*!
 * Vamos usar uma estrutura (\sa AnuncioHandler) para tratar dos anuncios em apontador na fila de prioridade.
 */
bool operator<(AnuncioHandler aH1,AnuncioHandler aH2);

//!Class AnuncioVenda
/*!
 * Classe para um anuncio de um produto que se pretende vender.
 \sa Anuncio
 */
class AnuncioVenda: public Anuncio {
	//!preco
	/*!
	 * Preco que se procura pelo produto.
	 */
	float _preco;
	//!negociavel
	/*!
	 * Indica se o preco e negociavel ou nao.
	 */
	bool _negociavel;
	//!estado
	/*!
	 * Indica o estado do produto atraves de defines associados a inteiros.
	 */
	int _estado; //Usar ESTADO_*
public:
	//!Construtor default.
	AnuncioVenda() {
	}
	//!Overlaod do construtor com 7 parametros.
	/*!
	 \param titulo do anuncio.
	 \param categ_produto categoria do produto.
	 \param descricao
	 \param date Data.
	 \param preco do produto.
	 \param negociavel
	 \param estado do produto.
	 */
	AnuncioVenda(string titulo, string categ_produto, string descricao,
			Data date, float preco, bool negociavel, int estado);
	//!Funcao de leitura das informacoes de um ficheiro.
	virtual void ler(ifstream& in, bool escreve = false);
	//!Funcao de escrita das informacoes para um ficheiro.
	virtual void escrever(ofstream& out);
	//!Funcao get para a informacao relativa ao AnuncioVenda.
	virtual string getInfo() const;
	//!Funcao get para o tipo de Anuncio.
	virtual int getTipo() const;
	//!Funcao get para o preco.
	float getPreco() const;
	//!Funcao get para o booleano Negociavel.
	bool getNegociavel() const;
	//!Funcao get para o Estado do produto.
	int getEstado() const;
	//!Funcao set para o preco do anuncio.
	void setPreco(float preco);
	//!Funcao set para o booleano negociavel.
	void setNegociavel(bool negociavel);
	//!Funcao set para o estado do produto anunciado.
	void setEstado(int estado);
};

//!Overload do operador << para a classe AnuncioVenda.
ostream & operator<<(ostream & o, AnuncioVenda & av);

//!Class AnuncioCompra
/*!
 * Classe para um anuncio de um produto que se pretende comprar.
 \sa Anuncio
 */
class AnuncioCompra: public Anuncio {
	//!anuncioVenda
	/*!
	 * anuncio de venda quando é diferente de NULL significa que o utilizador aceita troca, pointer para anuncio de venda do mesmo utilizador
	 \sa AnuncioVenda
	 */
	AnuncioVenda *_anuncioVenda;
public:
	//!Construtor default.
	AnuncioCompra() {
	}
	//!Destrutor.
	~AnuncioCompra();
	//!Overload do construtor com 4 parametros.
	/*!
	 \param titulo do anuncio.
	 \param categ_produto
	 \param descricao do anuncio.
	 \param date Data de criacao.
	 */
	AnuncioCompra(string titulo, string categ_produto, string descricao,
			Data date);
	//!Funcao para ler as informacoes do anuncio de um ficheiro.
	virtual void ler(ifstream& in, bool escreve = false);
	//!Funcao para escrever as informacoes do anuncio para um ficheiro.
	virtual void escrever(ofstream& out);
	//!Funcao troca
	/*!
	 * Verifica se o produto esta disponivel para trocar, se AnuncioVenda != NULL.
	 */
	bool troca();
	//!Funcao set para o anuncio de venda.
	void setAnuncioVenda(AnuncioVenda* anuncio);
	//!Funcao get para o Anuncio de Venda.
	AnuncioVenda* getAnuncioVenda();
	//!Funcao get para a informacao relativa a um anuncio de compra.
	virtual string getInfo() const;
	//!Funcao get para o tipo de anuncio.
	virtual int getTipo() const;
};

//!Overload do operador << para a classe AnuncioCompra.
ostream & operator<<(ostream & o, AnuncioCompra & ac);

#endif
