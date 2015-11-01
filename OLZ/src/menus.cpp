#include "menus.h"
#include <stdlib.h>


void intro(){
	setcolor(9);
	cout << "   ______    __       ________  " <<endl;
	cout << "  /  __  \\  |  |     |       /  " <<endl;
	cout << " |  |  |  | |  |     `---/  /   " <<endl;
	cout << " |  |  |  | |  |        /  /    " <<endl;
	cout << " |  `--'  | |  `----.  /  /----." <<endl;
	cout << "  \\______/  |_______| /________|" <<endl << endl << endl;
	setcolor(15);
}


string Highlight(string frase, int select, int ops){
	if(select == ops){
		setcolor(2);
		return "["+ frase + "]";
	}

	return frase;
}

void menuInicial(int y){
	system("cls");
	intro();
	cout << setw(20) <<  Highlight("Login", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Registar",y, 1 ) << endl;
	setcolor(15);
	cout << setw(20) <<  Highlight("Pesquisar Anuncios", y, 2) << endl;
	setcolor(15);
	cout << setw(20) <<Highlight("Sair", y, 3) << endl;
	setcolor(15);
}

void menuLogin(int y){
	system("cls");
	intro();
	cout << setw(20) <<  Highlight("Anunciar", y, 0) << endl;
	setcolor(15);
	cout << setw(20) <<  Highlight("Definicoes De Conta", y, 1) << endl;
	setcolor(15);
	cout << setw(20) <<  Highlight("Pesquisar Anuncios", y, 2) << endl;
	setcolor(15);
	cout << setw(20) <<Highlight("Terminar Sessao", y, 3) << endl;
	setcolor(15);
}

void menuAnunciar(int y){
	system("cls");
	intro();
	cout << setw(20) <<  Highlight("Criar Anuncio de Venda", y, 0) << endl;
	setcolor(15);
	cout << setw(20) <<  Highlight("Criar Anuncio de Compra", y, 1) << endl;
	setcolor(15);
	cout << setw(20) <<Highlight("Voltar Atras", y, 2) << endl;
	setcolor(15);
}

void menuConta(int y){
	system("cls");
	intro();
	cout << setw(20) <<  Highlight("Meus Anuncios De Compra", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Meus Anuncios De Venda",y, 1 ) << endl;
	setcolor(15);
	cout << setw(20) <<  Highlight("Alterar Visibilidade Dos Meus Dados Pessoais", y, 2) << endl;
	setcolor(15);
	cout << setw(20) <<Highlight("Voltar Atras", y, 3) << endl;
	setcolor(15);
}

void menuPesquisar(int y){
		system("cls");
		intro();
		cout << "Pesquisar por: " << endl << endl;
		cout << setw(20) <<  Highlight("Palavra-Chave", y, 0) << endl;
		setcolor(15);
		cout << setw(20) << Highlight("Data",y, 1 ) << endl;
		setcolor(15);
		cout << setw(20) <<  Highlight("Categoria do Produto", y, 2) << endl;
		setcolor(15);
		cout << setw(20) <<  Highlight("Localizacao", y, 3) << endl;
		setcolor(15);
		cout << setw(20) <<Highlight("Voltar Atras", y, 4) << endl;
		setcolor(15);
}


void menuOrdemPesq(int y){
	system("cls");
	intro();
	cout << "Ordem: " << endl << endl;
	cout << setw(20) <<  Highlight("Crescente", y, 0) << endl;
	setcolor(15);
	cout << setw(20) << Highlight("Decrescente",y, 1 ) << endl;
	setcolor(15);
	cout << setw(20) <<  Highlight("Voltar Atras", y, 2) << endl;
	setcolor(15);
}

//fazer menu para os anuncios com nova funcao highligth

void menuAnuncio(int y){
	system("cls");
	intro();
	cout << setw(50) <<  Highlight("Contactar Anunciante", y, 0) << endl;
	setcolor(15);
	cout << setw(50) <<  Highlight("Voltar Atras", y, 1) << endl;
	setcolor(15);
}

int menu(int tamanho,int menuSelect){
	int y=0;
	bool teclado=true;

	switch (menuSelect){
	case 0:	menuInicial(y);
	break;
	case 1: menuLogin(y);
	break;
	case 2: menuAnunciar(y);
	break;
	case 3: menuPesquisar(y);
	break;
	case 4: menuOrdemPesq(y);
	break;
	case 5: menuConta(y);
	break;
	case 6:menuAnuncio(y);
	break;
	default:
		cout << "menu inixestente" << endl;
	}

	while (teclado){
		if (kbhit()){
			int tecla = getch();
			if (tecla == 72){ // para cima
				if (y > 0){//não diminui o indice se já estiver na posição com o menor indice
					y--;
				}
			}
			else if (tecla == 80){ // para baixo
				if (y < tamanho){//não aumenta o indice se já estiver na posição com o maior indice
					y++;
				}
			}
			else if (tecla == 13){ // enter
				teclado = false;
			}

			switch (menuSelect){
			case 0:	menuInicial(y);
			break;
			case 1: menuLogin(y);
			break;
			case 2: menuAnunciar(y);
			break;
			case 3: menuPesquisar(y);
			break;
			case 4: menuOrdemPesq(y);
			break;
			case 5: menuConta(y);
			break;
			case 6:menuAnuncio(y);
			break;
			default:
				cout << "menu inixestente" << endl;
			}
		}
	}
	return y;
}
