#include "menus.h"
#include <stdlib.h>


bool Menu::logado=false;
Anuncio* Menu::Anuncio_atual=NULL;

string Highlight(string frase, int select, int ops) {
	if (select == ops) {
		setcolor(2);
		return "[" + frase + "]";
	}

	return frase;
}
//--------TEXTO------------------
void Menu::menuInicial(int y) {
	system("cls");
	Website::intro();
	cout << setw(20) << Highlight("Login", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Registar", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Pesquisar Anuncios", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Pesquisar Negocios", y, 3) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Top Negociantes", y, 4) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Sair", y, 5) << endl;
	setcolor(15);
}

void Menu::menuLogin(int y) {
	system("cls");
	Website::intro();
	cout << setw(20) << Highlight("Anunciar", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Definicoes De Conta", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Pesquisar Anuncios", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Pesquisar Negocios", y, 3) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Top Negociantes", y, 4) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Terminar Sessao", y, 5) << endl;
	setcolor(15);
}

void Menu::menuAnunciar(int y) {
	system("cls");
	Website::intro();
	cout << setw(20) << Highlight("Criar Anuncio de Venda", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Criar Anuncio de Compra", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 2) << endl;
	setcolor(15);
}

void Menu::menuConta(int y) {
	system("cls");
	Website::intro();
	cout <<  setw(30) << Highlight("Meus Anuncios De Compra", y, 0) << endl;
	setcolor(15);
	cout  <<setw(30)<< Highlight("Meus Anuncios De Venda", y, 1) << endl;
	setcolor(15);
	cout << setw(30)<< Highlight("Meus Negocios", y, 2)<< endl;
	setcolor(15);
	cout << setw(30) << Highlight("Editar Conta", y, 3)<< endl;
	setcolor(15);
	cout << setw(30) << Highlight("Voltar Atras", y,4) <<  endl;
	setcolor(15);
}

void Menu::menuEditarUtilizador(int y) {
	system("cls");
	Website::intro();
	cout << setw(20) << Highlight("Nome", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Telefone", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Email", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Alterar Visibilidade Dos Meus Dados Pessoais", y, 3) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Freguesia", y, 4) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Concelho", y, 5) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Distrito", y, 6) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Cancelar Conta", y, 7) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 8) << endl;
	setcolor(15);
}

void Menu::menuPesquisar(int y) {
	system("cls");
	Website::intro();
	cout << "Pesquisar por: " << endl << endl;
	cout << setw(20) << Highlight("Palavra-Chave", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Data", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Categoria do Produto", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Localizacao", y, 3) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Preco", y, 4) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 5) << endl;
	setcolor(15);
}

void Menu::menuOrdemPesq(int y) {
	system("cls");
	Website::intro();
	cout << "Ordem: " << endl << endl;
	cout << setw(20) << Highlight("Crescente", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Decrescente", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 2) << endl;
	setcolor(15);
}
void Menu::menuTipoAnuncio(int y) {
	system("cls");
	Website::intro();
	cout << setw(20) << Highlight("Anuncio Compra", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Anuncio Venda", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 2) << endl;
	setcolor(15);
}

void Menu::menuTipoNegocio(int y) {
	system("cls");
	Website::intro();
	cout << setw(20) << Highlight("Negocio Compra", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Negocio Venda", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 2) << endl;
	setcolor(15);
}

void Menu::menuAnuncio(int y) {
	system("cls");
	Website::intro();
	if(Anuncio_atual!=NULL)
	if(Anuncio_atual->getTipo())
		cout<< (*dynamic_cast<AnuncioVenda*>(Anuncio_atual));
	else{
		AnuncioCompra *ac = dynamic_cast<AnuncioCompra*>(Anuncio_atual);
		cout<< (*ac);
		if(ac->troca()){
			setcolor(3);
			cout << "----------------Anuncio Venda Associado----------------"<< endl;
			setcolor(15);
			cout << (*ac->getAnuncioVenda());
		}
	}
	cout << endl << setw(40) << Highlight("Contactar Anunciante", y, 0) << endl;
	setcolor(15);
	cout << setw(40) << Highlight("Voltar Atras", y, 1) << endl;
	setcolor(15);
}

void Menu::menuCategProd(int y) {
	system("cls");
	Website::intro();
	cout << "Estado Produto: " << endl << endl;
	cout << setw(20) << Highlight("Novo", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Usado Como Novo", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Funcional", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Para Pecas", y, 3) << endl;
	setcolor(15);
}

void Menu::menuAnuncioDefinicoes(int y) {
	system("cls");
	Website::intro();
	if(Anuncio_atual!=NULL)
	if(Anuncio_atual->getTipo())
		cout<< (*dynamic_cast<AnuncioVenda*>(Anuncio_atual));
	else{
		AnuncioCompra *ac = dynamic_cast<AnuncioCompra*>(Anuncio_atual);
		cout<< (*ac);
		if(ac->troca()){
			setcolor(3);
			cout << "----------------Anuncio Venda Associado----------------"<< endl;
			setcolor(15);
			cout << (*ac->getAnuncioVenda());
		}
	}//Supostamente é aqui
	cout << setw(20) << Highlight("Ver Contacto(s): ", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Remover", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Finalizar Negocio", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Editar", y, 3) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Destacar Anuncio", y, 4) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 5) << endl;
	setcolor(15);
}

void Menu::menuVisibilidade(int y) {
	system("cls");
	Website::intro();
	cout << "Alterar Visibilidade: " << endl << endl;
	cout << setw(20) << Highlight("Nome ", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Telefone", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Email", y, 2) << endl;
	setcolor(15);
}

void Menu::menuEditar_AV(int y) {
	system("cls");
	Website::intro();
	cout << setw(30) << Highlight("Titulo", y, 0) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Categoria do Produto", y, 1) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Descricao", y, 2) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Adicionar Imagem", y, 3) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Eliminar todas as Imagens", y, 4) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Preco", y, 5) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Negociavel", y, 6) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Estado Produto", y, 7) << endl;
	setcolor(15);
}

void Menu::menuEditar_AC(int y) {
	system("cls");
	Website::intro();
	cout << setw(30) << Highlight("Titulo", y, 0) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Categoria do Produto", y, 1) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Descricao", y, 2) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Adicionar Imagem", y, 3) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Eliminar todas as Imagens", y, 4) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Associar/Alterar Anuncio", y, 5) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Desassociar", y, 6) << endl;
	setcolor(15);
}

void Menu::menuPesquisarNegocios(int y){
	system("cls");
	Website::intro();
	setcolor(3);
	cout << "Pesquisar por: " << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Anunciante", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Tipo de Negocio", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Categoria", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 3) << endl;
	setcolor(15);
}


//----------------------------------------------------------------------------------
//---------------------------Menu Selector------------------------------------------
void Menu::InterfaceSeletor() {

	int menu = 0;
	while (true) {
		switch (menu) {
		case 0:
			menu = menuInterface();
			break;
		case 1:
			menu = interfaceLog();
			break;
		case 2:
			menu=interfaceTipoAnuncio();
			break;
		case 3:
			menu = interfaceConta();
			break;
		case 4:
			menu = interfacePesquisar(logado);
			break;
		case 5:
			menu = interfaceOrdemPesq();
			break;
		case 6:
			menu = interfaceCategProd();
			break;
		case 7://sair
			return;
			break;
		case 8:
			menu = interfacePesquisarNegocios();
			break;
		default:
			cout << "Interface Invalida" << endl;
			return;
			break;
		}
	}

}

//---------------------------Menu Anuncios--------------------------------------

void Menu::desenharAnuncioThumbnail(Anuncio* anuncio, int sel, int pos){


	string header = (anuncio->getTipo() == TIPO_COMPRA)? "Anuncio Compra" : "Anuncio Venda";

	setcolor(15);
	bool prioritario = anuncio->getPrioridade();
	if(prioritario)
		setcolor(2);

	if (sel == pos)
		if(prioritario)
			setcolor(114);
		else
			setcolor(135);
	//est
	if(prioritario)
		cout << "Destaque ---------------------------------" << endl;
	else
		cout << "------------------------------------------" << endl;

	cout <<left << "|" <<setw(19)<< anuncio->getData() << right << setw(21) << header << "|" << endl;
	cout << "|Titulo: "<< setw(32) << anuncio->getTitulo() << "|" << endl;
	if (anuncio->getTipo() == TIPO_VENDA)
		cout <<"|Preco: "<<setw(33) << anuncio->getPreco() <<"|"<< endl;
	cout << "------------------------------------------"<<endl;

	setcolor(15);

}

//-----------------------------Menu top negociantes----------------------------

void Menu::desenharUtilizadorThumbnail(Utilizador* util, int sel, int pos){

	DadosPessoais dp = util->getDadosPessoais();
	setcolor(15);
	if (sel == pos)
		setcolor(2);
	string nome = (dp.getVisiveis()[VIS_NOME])? dp.getNome() : "Nome nao visivel";
	string email=(dp.getVisiveis()[VIS_EMAIL])? dp.getEmail() : "Email nao visivel";
	string telefone=(dp.getVisiveis()[VIS_TELEFONE])? dp.getTelefone() : "Telefone nao visivel";

	cout << "-------------------------------------------------" << endl;
	cout << "|Nome:" << setw(42) << nome << "|" << endl;
	cout << "|Mail: "<< setw(41) << email<< "|" << endl;
	cout << "|Telefone: "<<setw(37) << telefone <<"|"<< endl;
	cout << "|Numero de Negocios:"<<setw(28) << util->getNegocios().size() <<"|"<< endl;
	cout << "-------------------------------------------------"<<endl;

	setcolor(15);
}


Utilizador* Menu::menuTopNegociantesInterface(vector<Utilizador*>& util){
	int y= 0;//Seletor
		int nPagina=0; //numero pagina;
		int utilizadoresPorPagina=3;//numero de anuncio por pagina;
		bool update= true;
		int maxY;
		while(true){

			if(update){
				update=false;
				system("cls");
				Website::intro();
				cout<<(nPagina+1)<< "/" <<((util.size()-1)/utilizadoresPorPagina + 1)<<endl;
				for (int i = 0; i < 3; ++i) {
					int n = nPagina * utilizadoresPorPagina;
					if (i + n >= util.size())
						break;
					maxY=i;

					desenharUtilizadorThumbnail(util[i+n], y, i);
				}
			}

			if (kbhit()) {
				int tecla = getch();
				if (tecla == 72) { // para cima
					if (y > 0){//não diminui o indice se já estiver na posição com o menor indice
						y--;
						update=true;

					}

				} else if (tecla == 80) { // para baixo
					if(y<maxY){
						y++;
						update=true;
					}

				}else if(tecla == 75){ //esquerda
					if(nPagina>0){
						y=0;
						nPagina--;
						update=true;
					}

				}else if(tecla == 77){ // direita
					if(nPagina < (util.size()-1)/utilizadoresPorPagina){
						y=0;
						nPagina++;
						update=true;
					}
				}else if (tecla == 13) { // enter
					return util[(nPagina*utilizadoresPorPagina+y)];
				}
				else if(tecla==27){//esc
					return NULL;//voltar atras Aqui jaz Grande Easter Egg :(
				}
			}
		}
}


//-----------------------------Menu Anuncio----------------------------
Anuncio* Menu::menuAnuncioInterface(vector<Anuncio*>& anuncios){
	int y= 0;//Seletor
	int nPagina=0; //numero pagina;
	int anuncioPorPagina=3;//numero de anuncio por pagina;
	bool update= true;
	int maxY;
	while (true) {



		if(update){
			update=false;
			system("cls");
			Website::intro();
			cout<<(nPagina+1)<< "/" <<((anuncios.size()-1)/anuncioPorPagina + 1)<<endl;
			for (int i = 0; i < 3; ++i) {
				int n = nPagina * anuncioPorPagina;
				if (i + n >= anuncios.size())
					break;
				maxY=i;
				desenharAnuncioThumbnail(anuncios[i + n], y, i);
			}
		}

		if (kbhit()) {
			int tecla = getch();
			if (tecla == 72) { // para cima
				if (y > 0){//não diminui o indice se já estiver na posição com o menor indice
					y--;
					update=true;
				}

			} else if (tecla == 80) { // para baixo
				if(y<maxY){
					y++;
					update=true;
				}

			}else if(tecla == 75){ //esquerda
				if(nPagina>0){
					y=0;
					nPagina--;
					update=true;
				}

			}else if(tecla == 77){ // direita
				if(nPagina < (anuncios.size()-1)/anuncioPorPagina){
					y=0;
					nPagina++;
					update=true;
				}
			}else if (tecla == 13) { // enter
				return anuncios[(nPagina*anuncioPorPagina+y)];
			}
			else if(tecla==27){//esc
				return NULL;//voltar atras
			}
		}
	}
}
//-----------------------------Menu Negocios----------------------------------------
void Menu::desenharNegocioThumbnail(Negocio *n, int sel, int pos){

	Anuncio *a =n->getAnuncio();
	AnuncioVenda *av=dynamic_cast<AnuncioVenda*>(n->getAnuncio());

	string header = (av == NULL)? "Negocio Compra" : "Negocio Venda";
	setcolor(15);
	if (sel == pos)
		setcolor(2);
	cout << "------------------------------------------" << endl;
	cout << "|" << setw(40) << header << "|" << endl;
	cout << "|Titulo: "<< setw(32) << a->getTitulo() << "|" << endl;
	if(n->trocou())
		cout <<"|Este negocio resultou de uma troca. "<<setw(6)<<"|"<< endl;
	else
		cout <<"|Montante: "<<setw(30) <<n->getMontante() <<"|"<< endl;
	cout << "------------------------------------------"<<endl;

	setcolor(15);

}

Negocio* Menu::menuNegocioInterface(const vector<Negocio*>& negocios){
	int y= 0;//Seletor
	int nPagina=0; //numero pagina;
	int negocioPorPagina=3;//numero de anuncio por pagina;
	bool update= true;
	int maxY;
	while (true) {


		if(update){
			update=false;
			system("cls");
			Website::intro();
			cout<<(nPagina+1)<< "/" <<((negocios.size()-1)/negocioPorPagina + 1)<<endl;
			for (int i = 0; i < 3; ++i) {
				int n = nPagina * negocioPorPagina;
				if (i + n >= negocios.size())
					break;
				maxY=i;
				desenharNegocioThumbnail(negocios[i + n], y, i);
			}
		}

		if (kbhit()) {
			int tecla = getch();
			if (tecla == 72) { // para cima
				if (y > 0){//não diminui o indice se já estiver na posição com o menor indice
					y--;
					update=true;
				}

			} else if (tecla == 80) { // para baixo
				if(y<maxY){
					y++;
					update=true;
				}

			}else if(tecla == 75){ //esquerda
				if(nPagina>0){
					y=0;
					nPagina--;
					update=true;
				}

			}else if(tecla == 77){ // direita
				if(nPagina < (negocios.size()-1)/negocioPorPagina){
					y=0;
					nPagina++;
					update=true;
				}
			}else if (tecla == 13) { // enter
				return negocios[(nPagina*negocioPorPagina+y)];
			}
			else if(tecla==27){
				return NULL;//voltar atras
			}
		}
	}
}

//---------------------------Funcoes Interface--------------------------------------
int Menu::menuInterface() {
	int y;
	y = menu(5, 0);
	switch (y) {
	case 0://login
		try {
			Website::login();
			logado = true;
			return 1;
		} catch (UtilizadorInixestente &e) {
			setcolor(12);
			cout << "O Utilizador " << e.getMail() << " nao esta registado"<< endl;
			setcolor(15);
			getch();
			return 0;
		}
		break;
	case 1://registar
		Website::Registar();
		logado=true;
		return 1;
		break;
	case 2:  //pesquisar anuncios
		return 4;
		break;
	case 3: //pesquisar negocios
		return 8;

	case 4: //menu top anunciantes
		Website::menuTopNegocios();
		return 0;
		break;
	default://sair
		return 7;
	}
}

int Menu::interfaceLog() {
	int y;
	do{
		y = menu(5, 1);
	}while(y==-1);

	switch (y) {
	case 0:  //anunciar
		return 2;
		break;
	case 1:  //conta
		return 3;
		break;
	case 2://pesquisar anuncios
		return 4;
		break;

	case 3: //pesquisar negocios
		return 8;
	case 4://menu top anunciantes
		Website::menuTopNegocios();
		return 1;
		break;
	case 5:
		logado = false;
		Website::logout();
		//por o indice do utilizador logado a -1
		return 0;
	}
}

int Menu::interfaceConta() {
	int y;
	y = menu(4, 5);
	switch (y) {
	case 0:  //ac
		return Website::MenuAnuncioConta(false);
		break;
	case 1:  //av
		return Website::MenuAnuncioConta(true);
		break;
	case 2:  //negocios
		Website::menuNegocios(Website::getUtilizadores()[Website::getIndiceUtilizador()]->getVetorNegocios(),"Voce nao tem Negocios");
		return 3;
		break;
	case 3:  //Editar Utilizador
		return Website::EditarUtilizador();
		break;
	default: //voltar atras
		return 1;
		break;

	}
}

int Menu::interfaceAnuncioDefinicoes() {
	return menu(5,9);
}

int Menu::interfacePesquisar(bool log) {
	int y;
	y = menu(5, 3);
	switch (y) {
	case 0:  //palavra
		return Website::menuAnuncioPalavra();
		break;
	case 1://data
		return Website::menuAnuncioData();
		break;
	case 2://categoria
		return Website::menuAnuncioCategoria();
		break;
	case 3://localizacao
		return Website::menuAnuncioLocalizacao();

	break;
	case 4://preco
		return 5;
		break;
	default: {
		if (log)
			return 1;
		else
			return 0;
	}
	break;
	}
}

int Menu::interfaceOrdemPesq() {
	int y;
	y = menu(2, 4);
	switch (y) {
	case 0: //crescente
		return Website::menuAnuncioPreco(true);
		break;
	case 1: //decrecente
		return Website::menuAnuncioPreco(false);
		break;
	default: //voltar atras
		return 4;
		break;
	}
}

int Menu::interfaceTipoAnuncio() {
	int y;
	y = menu(2,7);
	switch (y) {
	case 0:  //Anuncio compra
		Website::Anunciar_AC();
		return 1;
		break;
	case 1:  //anuncio venda
		Website::Anunciar_AV();
		return 1;
		break;
	default: //voltar atras
		return 1;
		break;
	}
}

int Menu::interfaceCategProd() {
	return menu(3,8);
}

int Menu::interfaceMudarVisibilidade() {
	return menu(2,10);
}


int Menu::interfacemenuAnuncio() {
	return menu(1,6);
}

int Menu::interfaceEditarAnuncio_AV() {
	return menu(7,10);
}

int Menu::interfaceEditarAnuncio_AC() {
	return menu(6,11);
}

int Menu::interfaceEditarUtilizador() {
	return menu(8,12);
}

int Menu::interfacePesquisarNegocios(){
	int y;
	y = menu(3, 13);
	string msg;
	switch (y) {
	case 0: //anunciante

		Website::menuNegocios(Website::VetorNegocioAnunciante(),"Nao existem Negocios para este Utilizador");
		return 8;

		break;
	case 1: //tipo negocio
		y = menu(2,14);
		if(y==2)
			return 8;


		if(y==TIPO_COMPRA)
			msg="Nao existem Negocios de Compra";
		else
			msg="Nao existem Negocios de Venda";

		Website::menuNegocios(Website::VetorPesquisarNegocioPorTipo(y),msg);
		return 8;

		break;
	case 2:  //categoria


		Website::menuNegocios(Website::VetorPesquisarNegocioCategoria(),"Nao existem Negocios desta Categoria");
		return 8;

		break;
	default: //voltar atras
		if(logado)
			return 1;
		else
			return 0;
		break;
	}
}


//------------------------menu propriamente dito-----------------
int Menu::menu(int tamanho, int menuSelect) {
	int y = 0;
	bool teclado = true;

	bool update= true;

	while (teclado) {
		if (kbhit()) {
			int tecla = getch();
			if (tecla == 72) { // para cima
				if (y > 0) { //não diminui o indice se já estiver na posição com o menor indice
					y--;
					update=true;
				}
			} else if (tecla == 80) { // para baixo
				if (y < tamanho) { //não aumenta o indice se já estiver na posição com o maior indice
					y++;
					update=true;
				}
			} else if (tecla == 13) { // enter
				teclado = false;
			}
			else if(tecla == 27){//esc
				y=-1;
				break;
			}
		}

		if(update){
			update=false;
			switch (menuSelect) {
			case 0:
				menuInicial(y);
				break;
			case 1:
				menuLogin(y);
				break;
			case 2:
				menuAnunciar(y);
				break;
			case 3:
				menuPesquisar(y);
				break;
			case 4:
				menuOrdemPesq(y);
				break;
			case 5:
				menuConta(y);
				break;
			case 6:
				menuAnuncio(y);
				break;
			case 7:
				menuTipoAnuncio(y);
				break;
			case 8:
				menuCategProd(y);
				break;
			case 9:
				menuAnuncioDefinicoes(y);
				break;
			case 10:
				menuEditar_AV(y);
				break;
			case 11:
				menuEditar_AC(y);
				break;
			case 12:
				menuEditarUtilizador(y);
				break;
			case 13:
				menuPesquisarNegocios(y);
				break;
			case 14:
				menuTipoNegocio(y);
				break;
			default:
				cout << "Menu Inixestente" << endl;
			}
		}

	}
	return y;
}
