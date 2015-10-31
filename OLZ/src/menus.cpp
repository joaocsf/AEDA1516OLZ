#include "menus.h"
#include <stdlib.h>


void intro(){
	cout << "  ______    __       ________  " <<endl;
	cout << "  /  __  \\  |  |     |       /  " <<endl;
	cout << " |  |  |  | |  |     `---/  /   " <<endl;
	cout << " |  |  |  | |  |        /  /    " <<endl;
	cout << " |  `--'  | |  `----.  /  /----." <<endl;
	cout << "  \\______/  |_______| /________|" <<endl << endl << endl;
}


string Highlight(string frase, int select, int ops){
	return (select == ops)? "["+ frase + "]" : frase;
}

void menuImprime(int y){
	system("cls");
	intro();
	cout << setw(20) <<  Highlight("Login", y, 0) << endl;
	cout << setw(20) << Highlight("Criar Utilizador",y, 1 ) << endl;
	cout << setw(20) <<  Highlight("Pesquisar Anuncios", y, 2) << endl;
	cout << setw(20) <<Highlight("Sair", y, 3) << endl;
}

int menu(int tamanho,int menuSelect){
	int y=0;
	bool teclado=true;

	menuImprime(y);

	while (teclado){
		if (kbhit()){
			int tecla = getch();

			if (tecla == 72){ // para cima
				if (y > 0){//n�o diminui o indice se j� estiver na posi��o com o menor indice
					y--;
				}
			}
			else if (tecla == 80){ // para baixo
				if (y < tamanho){//n�o aumenta o indice se j� estiver na posi��o com o maior indice
					y++;
				}
			}
			else if (tecla == 13){ // enter
				teclado = false;
			}

			switch (menuSelect){
				case 0:	menuImprime(y);
						break;
				default:
						cout << "menu inixestente" << endl;
			}
		}
	}
	return y;
}