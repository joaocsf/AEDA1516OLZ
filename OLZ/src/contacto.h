#ifndef CONTACTO_H_
#define CONTACTO_H_

#include "utilidades.h"
#include "dadospessoais.h"
#include "dados.h"

//!  Class Contacto.
/*!
* Esta classe contêm as informaçoes relativas ao Utilizador que criou um anuncio nomeadamente a forma de contacto por parte dos interessados.
*/
class Contacto: public Dados{
	//! Mensagem.
	    /*!
	      Mensagem a ser enviada ao dono do anuncio.
	    */
	string _mensagem;
	//! Dados.
	    /*!
	      Contem os dados pessoais do anunciante que vai receber a mensagem.
	      \sa DadosPessoais
	    */
	DadosPessoais _dados;
public:
	//!Construtor Default
	Contacto();
	//! Overload do Construtor que recebe dois argumentos.
	    /*!
	      \param mensagem a mensagem a ser enviada.
	      \param dados os dados do utilizador que vai receber a mensagem.
	    */
	Contacto(string mensagem, DadosPessoais dados);
	//! Funcao que altera a variavel mensagem.
	    /*!
	    */
	void setMensagem(string mensagem);
	//! Funcao que le as informaçoes do ficheiro.
		/*!
		 \param in funcao de leitura de ficheiros.
		 \param escreve switch que indica se se vai escrever ou nao.
		 */
	virtual void ler(ifstream& in,bool escreve= false);
	//! Funcao que escreve as informaçoes no ficheiro.
		/*!
		 \param out funcao de escrita de ficheiros.
		 */
	virtual void escrever(ofstream& out);
	//! Funcao que retorna a informaçao (mensagem + dados pessoais).
	    /*!
	      \return O mensagem juntamente com os dados.
	    */
	string getInfo()const;
	//!Funcao get para os Dados Pessoais.
	DadosPessoais getDados() const;
	//!Funcao get para a mensagem.
	string getMensagem() const;
};



#endif
