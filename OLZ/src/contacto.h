#ifndef CONTACTO_H_
#define CONTACTO_H_

#include "utilidades.h"
#include "dadospessoais.h"
#include "dados.h"

//!  Classe Contacto.
/*!
  Esta classe cont�m as informa�oes relativas ao Utilizador que criou um anuncio nomeadamente a forma de contacto por parte dos interessados.
*/
class Contacto: public Dados{
	//! Mensagem.
	    /*!
	      Mensagem a ser enviada ao dono do anuncio.
	    */
	string _mensagem;
	//! Dados.
	    /*!
	      Contem os dados pessoais do anunciante que vai receber/enviar a mensagem.
	    */
	DadosPessoais _dados;
public:

	Contacto();
	//! Overload do Construtor que recebe dois argumentos.
	    /*!
	      \param mensagem a mensagem a ser enviada.
	      \param dados os dados do utilizador que vai receber/enviar a mensagem.
	    */
	Contacto(string mensagem, DadosPessoais dados);
	//! Funcao que retorna a informa�ao (mensagem + dados pessoais).
	    /*!
	      \return O mensagem juntamente com os dados.
	    */
	string getInfo()const;
	//! Funcao que altera a variavel mensagem.
	    /*!
	     *
	    */
	void setMensagem(string mensagem);
	virtual void ler(ifstream& in,bool escreve= false);
	virtual void escrever(ofstream& out);

};



#endif
