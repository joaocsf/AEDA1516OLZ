#include "menus.h"
#include <stdlib.h>

void Menu::intro(){
	setcolor(9);
	cout << "   ______    __       ________  " <<endl;
	cout << "  /  __  \\  |  |     |       /  " <<endl;
	cout << " |  |  |  | |  |     `---/  /   " <<endl;
	cout << " |  |  |  | |  |        /  /    " <<endl;
	cout << " |  `--'  | |  `----.  /  /----." <<endl;
	cout << "  \\______/  |_______| /________|" <<endl;


	setcolor(23);
	cout << setw(40) << ((Website::getIndiceUtilizador()==-1) ? "" : Website::getUtilizadores()[Website::getIndiceUtilizador()]->getDadosPessoais().getNome()) << endl << endl;
	setcolor(15);
}

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
	intro();
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
	intro();
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
	intro();
	cout << setw(20) << Highlight("Criar Anuncio de Venda", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Criar Anuncio de Compra", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 2) << endl;
	setcolor(15);
}

void Menu::menuConta(int y) {
	system("cls");
	intro();
	cout << setw(20) << Highlight("Meus Anuncios De Compra", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Meus Anuncios De Venda", y, 1) << endl;
	setcolor(15);
	cout << setw(20)
			<< Highlight("Alterar Visibilidade Dos Meus Dados Pessoais", y, 2)
			<< endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 3) << endl;
	setcolor(15);
}

void Menu::menuPesquisar(int y) {
	system("cls");
	intro();
	cout << "Pesquisar por: " << endl << endl;
	cout << setw(20) << Highlight("Palavra-Chave", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Data", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Categoria do Produto", y, 2) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Localizacao", y, 3) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 4) << endl;
	setcolor(15);
}

void Menu::menuOrdemPesq(int y) {
	system("cls");
	intro();
	cout << "Ordem: " << endl << endl;
	cout << setw(20) << Highlight("Crescente", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Decrescente", y, 1) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Voltar Atras", y, 2) << endl;
	setcolor(15);
}

void Menu::menuAnuncio(int y) {
	system("cls");
	intro();
	cout << setw(50) << Highlight("Contactar Anunciante", y, 0) << endl;
	setcolor(15);
	cout << setw(50) << Highlight("Voltar Atras", y, 1) << endl;
	setcolor(15);
}
//----------------------------------------------------------------------------------
//---------------------------Menu Selector--------------------------------------
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
			return;
		default:
			cout << "Interface Invalida" << endl;
			return;
			break;
		}
	}

}

//---------------------------Funcoes Interface--------------------------------------

int Menu::menuInterface() {
	int y;
	y = menu(3, 0);
	switch (y) {
	case 0:
		try {
			system("cls");
			intro();
			Website::login();
			logado = true;
			return 1;
		} catch (UtilizadorInixestente &e) {
			setcolor(4);
			cout << "O Utilizador " << e.getMail() << " nao esta registado"<< endl;
			setcolor(15);
			getch();
			return 0;
		}
		break;
	case 1:
		system("cls");
		intro();
		Website::Registar();
		logado=true;
		return 1;
		break;
	case 2:  //pesquisar
		return 4;

		break;
	case 3:
		return 6;

	default:

		break;
	}
}

int Menu::interfaceLog() {
	int y;
	y = menu(3, 1);
	switch (y) {
	case 0: { //anunciar
	}
		break;
	case 1: { //conta
		return 3;
	}
		break;
	case 2: {
		return 4;
	}
		break;
	case 3: {
		logado = false;
		Website::logout();
		//por o indice do site a 0
		return 0;
	}
	default:
		break;
	}
}

int Menu::interfaceConta() {
	int y;
	y = menu(3, 5);
	switch (y) {
	case 0: { //ac
	}
		break;
	case 1: { //av
	}
		break;
	case 2: { //visibilidade
	}
		break;
	case 3: {
		return 1;
		break;
	}
	default:
		break;
	}
}

int Menu::interfacePesquisar(bool log) {
	int y;
	y = menu(4, 3);
	switch (y) {
	case 0: { //palavra
	}
		break;
	case 1: { //data
		return 5;
		break;
	}
		break;
	case 2: { //categ
	}
		break;
	case 3: { //localizacao

	}
		break;
	case 4: {
		if (log)
			interfaceLog();
		else
			menuInterface();
	}
		break;
	}
}

int Menu::interfaceOrdemPesq() {
	int y;
	y = menu(2, 4);
	switch (y) {
	case 0: { //crescente
	}
		break;
	case 1: { //decrecente
	}
		break;
	case 2: {
		return 4;
	}
		break;
	}
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
			default:
				cout << "menu inixestente" << endl;
			}
		}
	}
	return y;
}
