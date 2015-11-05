#ifndef WEBSITE_H_
#define WEBSITE_H_

#include "utilidades.h"
#include "utilizador.h"
#include "anuncio.h"
#include "negocio.h"

//!Class Website
/*!
 * Esta clase contem o registo de todo relativo ao website, anuncios, utilizadores, negocios...
 * E os membros-funcao relativos ao mesmo.
 */
class Website{
	//!Declaracao do vetor de utilizadores do website.
	/*!
	 \sa Utilizador
	 */
	static vector<Utilizador *> utilizadores;
	//!Declaracao do vetor de anuncios do website.
	/*!
	 \sa Anuncio
	 */
	static vector<Anuncio *> anuncios;
	//!Declaracao do vetor de negocios do website.
	/*!
	 \sa Negocio
	 */
	static vector<Negocio *> negocios;
	//!Variavel global que contem o indice do utilizador.
	/*!
	 * Indica a posicao no vetor de utilizadores do utilizador que esta atualmente logado.
	 */
	static int indiceUtilizador;
	//!Variavel global a classe que contem a data atual.
	/*!
	 \sa Data
	 */
	static Data _data;
public:
	//!Construtor default
	Website();
	//!Funcao para atualizar a data do website.
	/*!
	 \param d data atual.
	 */
	static void setData(Data d);
	//!Funcao get para a data atual.
	static Data getData();
	//!Funcao get para a informacao do website.
	/*!
	 \return Devolve uma string com todas as informacoes relativas aos utilizadores do website.
	 */
	static string getInfo();
	//!Funcao que faz o login do utilizador.
	/*!
	 * Esta funcao pesquisa no vetor de utilizadores se o utilizador que esta a tentar fazer login existe, se sim vai passar a sua posicao no vetor para a variavel global indiceUtilizador, se não vai lançar a excepçao de utilizadorInexistente.
	 */
	static void login();
	//!Funcao que efetua o logout.
	/*!
	 * Esta funcao simplesmente altera a variavel indiceUtilizador para -1 de forma a indicar que não há nenhum utilizador logado de momento.
	 */
	static void logout();
	//!Funcao para registar um novo utilizador.
	/*!
	 * Esta funcao pede atraves cin (console input) as informacoes do utilizador, de seguida verifica se o email ja foi registado, em caso negativo vai adicionar o novo utilizador ao vetor de utilizadores e ira mante-lo logado.
	 */
	static void Registar();
	//!Funcao para criar anuncio de compra.
	/*!
	 * Esta funcao cria um novo anuncio de venda perguntando ao usuario as informacoes do anuncio.
	 * A funcao trata tambem se for o caso de o utilizador querer associar este anuncio de compra a um dos seus anuncios de venda indicando a possibilidade de troca.
	 */
	static void Anunciar_AC();
	//!Funcao para criar um anuncio de venda.
	/*!
	 * Esta funcao cria um anuncio de venda perguntando as informacoes do mesmo ao utilizador.
	 */
	static void Anunciar_AV();
	//!Funcao get para o vetor de utilizadores do website.
	static vector<Utilizador*>  getUtilizadores();
	//!Funcao get para o vetor de anuncios do website.
	static vector<Anuncio *>  getAnuncios();
	//!Funcao get para o vetor de negocios do website.
	static vector<Negocio*>  getNegocios();
	//!Funcao que adiciona um novo utilizador ao vetor de utilizadores.
	static void addUtilizador(Utilizador *u);
	//!Funcao que adiciona um anuncio ao vetor de anuncios do website.
	static void addAnuncio(Anuncio *a);
	//!Funcao que adiciona um novo negocio ao vetor de negocios do website.
	static void addNegocio(Negocio *n);
	//!Funcao que remove um anuncio do vetor.
	/*!
	 \param id do anuncio que se pretende remover.
	 */
	static void RemoveAnuncio(int id);
	//!Funcao que remove varios anuncios do vetor.
	/*!
	 \param ids vetor com os anuncios que se pretende remover.
	 */
	static void RemoveAnuncios(vector<Anuncio*> ids);
	//!Funcao que verifica a existencio de um dado email nos utilizadores ja existentes.
	static bool emailExiste(string email);
	//!Funcao para remover um utilizador do website.
	/*!
	 * Esta funcao remove todos os anuncios do utilizador e depois remove o utilizador.
	 */
	static void RemoveUtilizador(int id);
	//!Funcao para remover um negocio.
	static void	RemoveNegocio(int id);
	//!Funcao get para o indice do utilizador atual.
	static int getIndiceUtilizador();
	//procura
	//!Funcao de pesquisa por Palavra Chave.
	/*!
	 \param palavra que vai ser procurada na descricao de cada anuncio.
	 \return devolve um vetor que contem os indices dos anuncios nos quais encontrou a palavra chave com recurso a funcao find() das strings.
	 */
	static vector<int> procurarPalavraChave(string palavra);
	//!Funcao para pesquisar por data.
	/*!
	 \param data a procurar.
	 \return devolve um vetor que contem os indices dos anuncios que foram criados na data a procurar.
	 */
	static vector<int> procurarData(Data data);
	static vector<int> procurarCategoria(string categoria);
	static vector<int> procurarLocalizacao(string loc);
	static vector<int> procurarPreco(int min, int max);
	//menu pesquisa
	static int menuAnuncioPalavra();
	static int menuAnuncioData();
	static int menuAnuncioCategoria();
	static int menuAnuncioLocalizacao();
	static int menuAnuncioPreco(bool crescente);
	static int subMenuAnuncio(vector<int>& indices);
	static void ordenaPreco(vector<int>& v,bool crescente);
	static void intro();
	static void contactar(int id);
	static void guardarFicheiro(ofstream& file);
	static void lerFicheiro(ifstream& file);
	//menu definicoes
	static vector<int> anunciosParaIndices(const vector<Anuncio*>& aTemp);
	static vector<int> retornarMeusAnuncios(bool venda);
	static int MenuAnuncioConta(bool venda);
	static int menuMeusNegocios();
	static void alterarDadosVisiveis();
	static void menuVisivel(bool* v);
	static void criaNegocio(Anuncio* a);
	static int EditarUtilizador();
	//Validacao
	static string InputLinha(string mensagemLoop, bool vazio = false);
	static vector<string> InputVetorString(string mensagemLoop);
	static bool InputBool(string mensagemLoop);
	static float Inputfloat(string mensagemLoop);
	static string InputInteiro(string mensagemLoop, unsigned int casas);
};

class UtilizadorInixestente{
	string mail;
public:
	UtilizadorInixestente(string mail){
		this->mail=mail;
	}
	string getMail(){
		return mail;
	}
};

#endif
