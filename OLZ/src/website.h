#ifndef WEBSITE_H_
#define WEBSITE_H_

#include "utilidades.h"
#include "anuncio.h"
#include "negocio.h"
#include "BST.h"
#include "dadospessoais.h"
#include "utilidades.h"
#include "anuncio.h"
#include <queue>
#include <time.h>
#include "utilizador.h"

//!Classe UtilizadorHandler
/*!
 * Classe utilizada para a BST de utilizador devia a problemas relativos ao overload do operador menor com apontadores.
 */
class UtilizadorHandler{
public:
	//!Construtor default
	UtilizadorHandler(Utilizador* u);
	//!Apontador para o utilizador
	Utilizador* u;
};

//!Class Website
/*!
 * Esta clase contem o registo de tudo relativo ao website, anuncios, utilizadores, negocios...
 * E os membros-funcao relativos ao mesmo.
 */
class Website{
	//!Declaracao da fila de prioridade dos anuncios do website.
	/*!
	 \sa AnuncioHandler
	 \sa Anuncio
	 */
	static priority_queue<AnuncioHandler> anuncios_prioridades;
	//!Declaracao do vetor de utilizadores do website.
	/*!
	 \sa Utilizador
	 */
	static vector<Utilizador *> utilizadores;
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

	//!Declaracao global da BST de top negociantes.
	/*!
	 \sa Utilizador
	 */
	static BST<UtilizadorHandler> topNegociantes;
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
	 * Esta funcao pesquisa no vetor de utilizadores se o utilizador que esta a tentar fazer login existe, se sim vai passar a sua posicao no vetor para a variavel global indiceUtilizador, se n�o vai lan�ar a excep�ao de utilizadorInexistente.
	 */
	static void login();
	//!Funcao que efetua o logout.
	/*!
	 * Esta funcao simplesmente altera a variavel indiceUtilizador para -1 de forma a indicar que n�o h� nenhum utilizador logado de momento.
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
	static vector<Anuncio*> procurarPalavraChave(string palavra);
	//!Funcao para pesquisar por data.
	/*!
	 \param data a procurar.
	 \return devolve um vetor que contem os indices dos anuncios que foram criados na data a procurar.
	 */
	static vector<Anuncio*> procurarData();
	//!Funcao de pesquisa por categoria.
	/*!
	 \param categoria a procurar.
	 \return um vetor de inteiros com os indices dos anuncios cuja categoria e igual a que procuramos.
	 */
	static vector<Anuncio*> procurarCategoria(string categoria);
	//!Funcao para pesquisar anuncios por localizacao.
	/*!
	 \param loc localizacao a procurar.
	 \return devolve um vetor de inteiros contendo os indices dos anuncios que correspondem aos parametros da pesquisa.
	 */
	static vector<Anuncio*> procurarLocalizacao(string loc);
	//!Funcao para procurar anuncios dentro de um intervalo de precos.
	/*!
	 \param min preco minimo.
	 \param max preco maximo.
	 \return o vetor contendo os indices dos anuncios (neste caso somente os de venda) correspondentes.
	 */
	static vector<Anuncio*> procurarPreco(int min, int max);
	//menu pesquisa
	//!Funcao para o menu de pesquisa por palavra.
	/*!
	 * Esta funcao pede ao utilizador a palavra-chave a pesquisar, efetua a pesquisa e verifica se nao encontrou nenhum anuncio correspondente.
	 */
	static int menuAnuncioPalavra();
	//!Funcao para o menu de pesquisa por data.
	/*!
	 * Esta funcao pede ao utilizador a data a pesquisar, efetua a pesquisa e verifica se nao encontrou nenhum anuncio correspondente.
	 */
	static int menuAnuncioData();
	//!Funcao para o menu de pesquisa por categoria.
	/*!
	 * Esta funcao pede ao utilizador a categoria a pesquisar, efetua a pesquisa e verifica se nao encontrou nenhum anuncio correspondente.
	 */
	static int menuAnuncioCategoria();
	//!Funcao para o menu de pesquisa por localizacao.
	/*!
	 * Esta funcao pede ao utilizador a localizacao a pesquisar, efetua a pesquisa e verifica se nao encontrou nenhum anuncio correspondente.
	 */
	static int menuAnuncioLocalizacao();
	//!Funcao para o menu de pesquisa por intervalo de preco.
	/*!
	 * Esta funcao pede ao utilizador o preco minimo e o preco maximo a pesquisar, efetua a pesquisa e verifica se nao encontrou nenhum anuncio correspondente.
	 */
	static int menuAnuncioPreco(bool crescente);
	//!Funcao chamada apos uma pesquisa no caso de esta ser diferente de 0.
	/*!
	 * Esta funcao e chamada no fim de uma pesquisa no caso de de o resultado ser diferente de 0 e mostra os anuncios encontrados.
	 */
	static int subMenuAnuncio(vector<Anuncio *>& indices);
	//!Funcao que ordena os indices por preco.
	/*!
	 \param v vetor com os indices dos anuncios correspondentes a pesquisa.
	 \param crescente booleano que serve para indicar se queremos ordenar por ordem crescente ou decrescente de preco.
	 */
	static void ordenaPreco(vector<Anuncio*>& v,bool crescente);
	//!Funcao de display da intro ("OLZ").
	static void intro();
	//!Funcao para realizar o contacto entre o anunciante e o interessado.
	/*!
	 * Esta funcao realiza o contacto entre dois utilizadores, verifica se o utilizador esta logado, em caso afirmativo vai buscar os seus dados pessoais e realiza o contacto, caso contrario pede essas informacoes ao utilizador.
	 */
	static void contactar(Anuncio * an);
	//!Funcao que guarda todas as informacoes num ficheiro no fim do programa.
	static void guardarFicheiro(ofstream& file);
	//!Funcao que le as informacoes do website de um ficheiro no inicio do programa.
	static void lerFicheiro(ifstream& file);
	//!Funcao quue retorna um vetor de indices com os anuncios de venda do utilizador atualmente logado.
	static vector<Anuncio*> retornarMeusAnuncios(bool venda);
	//!Funcao que lista e gere os anuncios quer de comprar quer de venda do utilizador.
	/*!
	 * A funcao mostra uma lista de anuncios dependendo do booleano (Compra ou venda).
	 \param venda indica se a funcao mostra os anuncios de compra ou de venda.
	 \return inteiro que esta relacionado com a forma como sao escolhidos os menus.
	 */
	static int MenuAnuncioConta(bool venda);
	//!Funcao para atualizadar a data atual.
	static void AtualizarData();
	//!Funcao para o menu relativo aos negocios
	static void menuNegocios(vector<Negocio*> neg,string msg_erro);
	//!Funcao que faz display do estado atual de visibilidade dos dados do utilizador.
	/*!
	 * Esta funcao mostra no ecra o estado dos dados e permite ao usuario altera-los.
	 */
	static void alterarDadosVisiveis();
	//!Funcao que cria um negocio.
	/*!
	 * A funcao trata das possibilidades de ser um anuncio de venda ou compra ou de ter ocorrido uma troca.
	 \param a anuncio referente ao negocio.
	 */
	static void criaNegocio(Anuncio* a);
	//!Funcao que permite ao utilizador alterar as suas informacoes.
	static int EditarUtilizador();
	//Validacao
	//!Funcao auxiliar para pedir informacoes ao utilizador.
	/*!
	 \param mensagemLoop e a mensagem que vai ser impressa na consola.
	 \return uma string com a informacao pretendida.
	 */
	static string InputLinha(string mensagemLoop, bool vazio = false);
	//!Funcao auxiliar para input de um vetor de strings (varias informacoes).
	/*!
	 \param mensagemLoop mensagem a mostrar ao utilizador.
	 \return um vetor de string com as informacoes.
	 */
	static vector<string> InputVetorString(string mensagemLoop);
	//!Funcao auxiliar para o input de um booleano.
	/*!
	 \param mensagemLoop mensagem a ser mostrada no ecra.
	 \return um booleano com a respota do utilizador.
	 */
	static bool InputBool(string mensagemLoop);
	//!Funcao auxiliar para o input de um float.
	/*!
	 \param mensagemLoop mensagem a ser mostrada no ecra.
	 \return um float com a respota do utilizador.
	 */
	static float Inputfloat(string mensagemLoop);
	//!Funcao auxiliar para o input de um numero (exemplo: numero de telefone).
	/*!
	 \param mensagemLoop mensagem a ser impresa.
	 \param casas numero minimo de casas do numero.
	 \return uma string com o numero pedido.
	 */
	static string InputInteiro(string mensagemLoop, unsigned int casas);
	//!Funcao para atualizar a fila de prioridade
	/*!
	 * De forma a manter sempre os anuncios ordenados da forma correta
	 */
	static void AtualizarP_queue();
	//!Funcao que converte a BST de utilizadores para um vetor de utilizadores.
	static vector<Utilizador*> BSTParaVetor(BST<UtilizadorHandler>& bst);
	//!Funcao que converte o vetor de utilizadores do website numa BST.
	static BST<UtilizadorHandler> ReturnUtilizadoresBST();
	//!Menu para o top de negocios.
	static void menuTopNegocios();
	//!Funcao para atualizar a BST de negocios de forma a manter a estrutura de dados ordenada.
	static void AtualizarBSTNegociantes();
	//!Funcao para adicionar na BST de negocios um novo utlizador
	/*!
	 * Utilizador vai ser inserido na BST de top negociantes.
	 */
	static void AdicionarUserBSTNegociantes(Utilizador* utilizador);

	//!Funcao para remover um dado utilizador da arvore de negocios.
	static void RemoverUserBSTNegociantes(Utilizador* utilizador);


	//!Funcao que devolve o vetor de negocios do utilizador atual.
	static  vector<Negocio*> VetorNegocioAnunciante();
	//!Funcao que pesquisa os negocios por tipo.
	static  vector<Negocio*> VetorPesquisarNegocioPorTipo(int y);
	//!Funcao que pesquisa os negocios por categoria.
	static  vector<Negocio*> VetorPesquisarNegocioCategoria();

};

//!Excepcao de  Utilizador Inixestente
/*!
 * Excepcao de utilizador inexistente.
 */
class UtilizadorInixestente{
	//!mail
	/*!
	 * Email que nao foi encontrado no vetor de utilizadores.
	 */
	string mail;
public:
	//!Overload do construtor
	/*!
	 \param mail que nao foi encontrado.
	 */
	UtilizadorInixestente(string mail){
		this->mail=mail;
	}
	//!Funcao get para o email que deu origem a excepcao.
	string getMail(){
		return mail;
	}
};

//!Overload do operador < para a classe UtilizadorHandler.
bool operator< (UtilizadorHandler u1, UtilizadorHandler u2);
//!Overload do operador de igualdade para a classe UtilizadorHandler.
bool operator== (UtilizadorHandler u1, UtilizadorHandler u2);
//!Overload do operador > para a classe UtilizadorHandler.
bool operator > (UtilizadorHandler u1, UtilizadorHandler u2);



#endif
