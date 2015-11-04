#include "menus.h"
#include <stdlib.h>


bool Menu::logado=false;
int Menu::idAnuncio=-1;

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
	cout << setw(20) << Highlight("Sair", y, 3) << endl;
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
	cout << setw(20) << Highlight("Terminar Sessao", y, 3) << endl;
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
	cout << setw(30) << Highlight("Meus Anuncios De Compra", y, 0) << endl;
	setcolor(15);
	cout << setw(30) << Highlight("Meus Anuncios De Venda", y, 1) << endl;
	setcolor(15);
	cout << setw(30)<< Highlight("Meus Negocios", y, 2)<< endl;
	setcolor(15);
	cout << setw(30)<< Highlight("Alterar Visibilidade Dos Meus Dados Pessoais", y, 3)<< endl;
	setcolor(15);
	cout << setw(30)<< Highlight("Cancelar Conta", y, 4)<< endl;
	setcolor(15);
	cout << setw(30) << Highlight("Voltar Atras", y, 5) << endl;
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

void Menu::menuAnuncio(int y) {
	system("cls");
	Website::intro();
	if(Website::getAnuncios()[idAnuncio]->getTipo())
		cout<< (*dynamic_cast<AnuncioVenda*>(Website::getAnuncios()[idAnuncio]));
	else
		cout<< (*dynamic_cast<AnuncioCompra*>(Website::getAnuncios()[idAnuncio]));
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
		if(Website::getAnuncios()[idAnuncio]->getTipo())
			cout<< (*dynamic_cast<AnuncioVenda*>(Website::getAnuncios()[idAnuncio]));
		else
			cout<< (*dynamic_cast<AnuncioCompra*>(Website::getAnuncios()[idAnuncio]));
	cout << setw(20) << Highlight("Ver Contacto(s): ", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Remover", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Finalizar Negocio", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 3) << endl;
	setcolor(15);
}

void Menu::menuVisibilidade(int y) {
	system("cls");
	Website::intro();
	cout << "Alterar Visibilidade: " << endl << endl;
	cout << setw(20) << Highlight("Nome", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Telefone", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Email", y, 2) << endl;
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
		case 7:
			return;
		default:
			cout << "Interface Invalida" << endl;
			return;
			break;
		}
	}

}

//---------------------------Menu Anuncios--------------------------------------

void Menu::desenharAnuncioThumbnail(int indice, int sel, int pos){

	Anuncio* aTemp = Website::getAnuncios()[indice];


	string header = (aTemp->getTipo() == TIPO_COMPRA)? "Anuncio Compra" : "Anuncio Venda";
	setcolor(15);
	if (sel == pos)
		setcolor(2);
	cout << "------------------------------------------" << endl;
	cout << "|" << setw(40) << header << "|" << endl;
	cout << "|Titulo: "<< setw(32) << aTemp->getTitulo() << "|" << endl;
	if (aTemp->getTipo() == TIPO_VENDA)
		cout <<"|Preco: "<<setw(33) << aTemp->getPreco() <<"|"<< endl;
	cout << "------------------------------------------"<<endl;

	setcolor(15);

}

int Menu::menuAnuncioInterface(vector<int> indices){
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
			cout<<(nPagina+1)<< "/" <<((indices.size()-1)/anuncioPorPagina + 1)<<endl;
			for (int i = 0; i < 3; ++i) {
				int n = nPagina * anuncioPorPagina;
				if (i + n >= indices.size())
					break;
				maxY=i;
				desenharAnuncioThumbnail(indices[i + n], y, i);
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
				if(nPagina < (indices.size()-1)/anuncioPorPagina){
					y=0;
					nPagina++;
					update=true;
				}
			}else if (tecla == 13) { // enter
				return indices[(nPagina*anuncioPorPagina+y)];
			}
			else if(tecla==27){//esc
				return -1;//voltar atras
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
		cout <<"|Este negocio resultou de uma toca. "<<setw(6)<<"|"<< endl;
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
	y = menu(3, 0);
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
	case 2:  //pesquisar
		return 4;

		break;
	default://sair
		return 7;
	}
}

int Menu::interfaceLog() {
	int y;
	do{
		y = menu(3, 1);
	}while(y==-1);

	switch (y) {
	case 0:  //anunciar
		return 2;
		break;
	case 1:  //conta
		return 3;

		break;
	case 2://pesquisar
		return 4;
		break;
	case 3:
		logado = false;
		Website::logout();
		//por o indice do utilizador logado a -1
		return 0;
	}
}

int Menu::interfaceConta() {
	int y;
	y = menu(5, 5);
	switch (y) {
	case 0:  //ac
		return Website::MenuAnuncioConta(false);
		break;
	case 1:  //av
		return Website::MenuAnuncioConta(true);
		break;
	case 2:  //negocios
		return Website::menuMeusNegocios();
		break;
	case 3:  //alterar visiblidade
		return Website::alterarDadosVisiveis();
		break;
	case 4://cancelar conta
		Website::RemoveUtilizador(Website::getUtilizadores()[Website::getIndiceUtilizador()]->getID());
		return 0;
	default: //voltar atras
		return 1;
		break;

	}
}

int Menu::interfaceAnuncioDefinicoes() {
	return menu(3,9);
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
	int y;
	y = menu(3,8);
	switch (y) {
	case 0:
		return 0;
		break;
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	}
}


int Menu::interfacemenuAnuncio() {
	return menu(1,6);
}

//------------------------menu propriamente dito-----------------
int Menu::menu(int tamanho, int menuSelect) {
	int y = 0;
	bool teclado = true;

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
	default:
		cout << "Menu Inixestente" << endl;
	}

	while (teclado) {
		if (kbhit()) {
			int tecla = getch();
			if (tecla == 72) { // para cima
				if (y > 0) { //não diminui o indice se já estiver na posição com o menor indice
					y--;
				}
			} else if (tecla == 80) { // para baixo
				if (y < tamanho) { //não aumenta o indice se já estiver na posição com o maior indice
					y++;
				}
			} else if (tecla == 13) { // enter
				teclado = false;
			}
			else if(tecla == 27){//esc
				y=-1;
				break;
			}
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
			default:
				cout << "Menu Inixestente" << endl;
			}
		}
	}
	return y;
}
