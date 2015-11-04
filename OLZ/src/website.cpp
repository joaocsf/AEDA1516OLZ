#include "website.h"
#include "menus.h"

vector<Utilizador*> Website::utilizadores;
vector<Anuncio *> Website::anuncios;
vector<Negocio*> Website::negocios;

int Website::indiceUtilizador = -1;
Data Website::_data = Data();

string Website::getInfo(){
	stringstream ss;
	ss << &utilizadores;
	return ss.str();
}

void Website::intro() {
	setcolor(9);
	cout << "   ______    __       ________  " << endl;
	cout << "  /  __  \\  |  |     |       /  " << endl;
	cout << " |  |  |  | |  |     `---/  /   " << endl;
	cout << " |  |  |  | |  |        /  /    " << endl;
	cout << " |  `--'  | |  `----.  /  /----." << endl;
	cout << "  \\______/  |_______| /________|" << endl;

	setcolor(23);
	cout << setw(36)
			<< ((Website::getIndiceUtilizador() == -1) ?
					"" :
					Website::getUtilizadores()[Website::getIndiceUtilizador()]->getDadosPessoais().getNome())
			<< setw(24) << "" << endl;
	setcolor(15);
}

Website::Website() {
}

void Website::setData(Data d){
	_data=d;
}
Data Website::getData(){
	return _data;
}
vector<Utilizador*> Website::getUtilizadores() {
	return utilizadores;
}

vector<Anuncio *> Website::getAnuncios() {
	return anuncios;
}

vector<Negocio*> Website::getNegocios() {
	return negocios;
}

void Website::addUtilizador(Utilizador *u) {
	utilizadores.push_back(u);
}

void Website::addAnuncio(Anuncio *a) {
	anuncios.push_back(a);
}

void Website::addNegocio(Negocio *n) {
	negocios.push_back(n);
}

void Website::RemoveAnuncio(int id) {

	for (unsigned int i = 0; i < anuncios.size(); ++i) {
		if (anuncios[i]->getID() == id) {
			anuncios[i]->getUser()->RemoverAnuncio(id);
			anuncios.erase(anuncios.begin() + i);
			break;
		}
	}
}

void Website::RemoveAnuncios(vector<Anuncio*> ids) {

	for (unsigned int i = 0; i < anuncios.size(); ++i) {
		for (unsigned int x = 0; x < ids.size(); ++x) {
			if(anuncios[i]->getID() == ids[x]->getID()){
				anuncios.erase(anuncios.begin() + i--);
				break;
			}
		}
	}


}

void Website::RemoveUtilizador(int id) {

	for (unsigned int i = 0; i < utilizadores.size(); ++i) {
		if (utilizadores[i]->getID() == id) {
			RemoveAnuncios(utilizadores[i]->getAnuncios());
			delete(utilizadores[i]);
			utilizadores.erase(utilizadores.begin() + i--);
			break;
		}
	}
	indiceUtilizador=-1;
	Menu::logado=false;
}

void Website::RemoveNegocio(int id) { //s� remove do vetor negocios

	for (unsigned int i = 0; i < negocios.size(); ++i) {
		if (negocios[i]->getID() == id) {
			negocios.erase(negocios.begin() + i);
			break;
		}
	}
}

//fun�oes intera�o com o usuario
int Website::getIndiceUtilizador() {
	return indiceUtilizador;

}

void Website::login() {

	system("cls");
	intro();

	string login;

	cout << "Login:";
	cin >> login;
	for (unsigned int i = 0; i < utilizadores.size(); ++i) {
		if (utilizadores[i]->getDadosPessoais().getEmail() == login) {
			indiceUtilizador = i;
			return;
		}
	}

	throw UtilizadorInixestente(login);
}

void Website::Registar() {

	string nome;
	string telefone;
	string email;

	do {
		system("cls");
		intro();
		cout << "Nome: ";
		getline(cin, nome);
	} while (nome.size() == 0);

	cout << "Telefone: ";
	getline(cin, telefone);

	while (telefone.size() < 9) {
		system("cls");
		intro();
		setcolor(12);
		cout << "Numero Invalido (Deve conter 9 ou mais digitos)" << endl;
		setcolor(15);
		cout << "Telefone: ";
		getline(cin, telefone);
	}

	do {
		system("cls");
		intro();
		cout << "Email: ";
		getline(cin, email);
	} while (email.size() == 0);

	DadosPessoais dados(nome, telefone, email);

	Localizacao loc_tmp;
	cout << "Freguesia: ";
	getline(cin, loc_tmp.freguesia);
	cout << "Concelho: ";
	getline(cin, loc_tmp.concelho);
	cout << "Distrito: ";
	getline(cin, loc_tmp.distrito);

	utilizadores.push_back(new Utilizador(dados, loc_tmp));
	indiceUtilizador = utilizadores.size() - 1;
}

void Website::logout() {
	indiceUtilizador = -1;
	Menu::logado=false;
}

void Website::Anunciar_AC() {
	string titulo;
	string categ_produto;
	string descricao;
	Data data;
	string lixo;
	string imagem;
	vector<string> imagens;
	string letra;
	bool ptrAV;

	do {
		system("cls");
		intro();
		cout << "Titulo Do Anuncio de Compra: ";
		getline(cin, titulo);
	} while (titulo.size() == 0);

	do {
		system("cls");
		intro();
		cout << "Categoria do Produto: ";
		getline(cin, categ_produto);
	} while (categ_produto.size() == 0);

	system("cls");
	intro();
	cout << "Descricao: ";
	getline(cin, descricao);

	data = _data;

	do {
		system("cls");
		intro();
		cout << "Imagens(Prima enter se nao quiser adicionar mais imagens): " << endl;
		getline(cin, imagem);
		imagens.push_back(imagem);
	} while (imagem != "");
	imagens.pop_back();

	AnuncioCompra *ac = new AnuncioCompra(titulo, categ_produto, descricao,
			data);
	ac->setUser(utilizadores[indiceUtilizador]);

	do {
		system("cls");
		intro();
		cout << "Deseja escolher um dos seus anuncios de venda? (S/N)" << endl;
		setcolor(7);
		cout
				<< "(Indicando assim, a possibilidade de trocar o\n produto que esta a vender,pelo produto deste anuncio)"
				<< endl;
		setcolor(15);
		getline(cin, letra);
	} while (letra != "s" && letra != "S" && letra != "n" && letra != "N");

	if (letra == "s" || letra == "S")
		ptrAV = true;
	else
		ptrAV = false;

	if (ptrAV) {

		if (retornarMeusAnuncios(true).size() == 0) {
			system("cls");
			intro();
			setcolor(12);
			cout << "Voce nao tem anuncios de venda";
			setcolor(15);
			getch();
			return;
		}
		Menu::idAnuncio = Menu::menuAnuncioInterface(retornarMeusAnuncios(true));

		if(Menu::idAnuncio == -1)
			return;

		ac->setAnuncioVenda(
				dynamic_cast<AnuncioVenda*>(anuncios[Menu::idAnuncio]));
	}

	for (int i = 0; i < imagens.size(); ++i) {
		Imagem img;
		img.conteudo = imagens[i];
		ac->AdicionarImagem(img);
	}

	anuncios.push_back(ac);
	utilizadores[indiceUtilizador]->AdicionarAnuncio(ac);
}

void Website::Anunciar_AV() {
	string titulo;
	string categ_produto;
	string descricao;
	Data data;
	float preco;
	string tmp;
	bool negociavel;
	bool erro = false;
	string erroS;
	string letra;
	int estado;
	string imagem;
	vector<string> imagens;

	do {
		system("cls");
		intro();
		cout << "Titulo Do Anuncio: ";
		getline(cin, titulo);
	} while (titulo.size() == 0);

	do {
		system("cls");
		intro();
		cout << "Categoria do Produto: ";
		getline(cin, categ_produto);
	} while (categ_produto.size() == 0);

	system("cls");
	intro();
	cout << "Descricao: ";
	getline(cin, descricao);

	data = _data;

	while (true) {
		system("cls");
		intro();
		if (erro) {
			setcolor(12);
			cout << erroS << endl;
			setcolor(15);
		}
		cout << "Preco: ";
		cin >> preco;

		if (cin.fail()) {
			erro = true;
			erroS = "Caracter Invalido";
			cin.clear();
			cin.ignore();
		} else if (preco <= 0.01f) {
			erro = true;
			erroS = "Preco deve ser maior do que zero";
		} else {
			erro = false;
			break;
		}
	}
	getline(cin, erroS);
	do {
		system("cls");
		intro();
		cout << "Imagens(Prima enter se nao quiser adicionar mais imagens): " << endl;
		getline(cin, imagem);
		imagens.push_back(imagem);
	} while (imagem != "");
	imagens.pop_back();

	do {
		system("cls");
		intro();
		cout << "Negociavel? (S/N): ";
		getline(cin, letra);
	} while (letra != "s" && letra != "S" && letra != "n" && letra != "N");

	if (letra != "s" || letra != "S")
		negociavel = true;
	else
		negociavel = false;

	estado = Menu::interfaceCategProd();

	AnuncioVenda *av = new AnuncioVenda(titulo, categ_produto, descricao, data,
			preco, negociavel, estado);
	av->setUser(utilizadores[indiceUtilizador]);

	for (int i = 0; i < imagens.size(); ++i) {
		Imagem img;
		img.conteudo = imagens[i];
		av->AdicionarImagem(img);
	}

	anuncios.push_back(av);
	utilizadores[indiceUtilizador]->AdicionarAnuncio(av);

}

//Procuras ETC ----------------
vector<int> Website::procurarLocalizacao(string loc) {
	vector<int> res;

	for (int i = 0; i < anuncios.size(); i++) {
		Localizacao l = anuncios[i]->getUser()->getLocalizacao();
		if (l.freguesia == loc || l.distrito == loc || l.concelho == loc)
			res.push_back(i);
	}

	return res;
}

vector<int> Website::procurarCategoria(string categoria) {
	vector<int> res;

	for (int i = 0; i < anuncios.size(); i++) {
		if (categoria == anuncios[i]->getCategoria())
			res.push_back(i);
	}

	return res;

}

vector<int> Website::procurarData(Data data) {
	vector<int> res;

	for (int i = 0; i < anuncios.size(); i++) {
		if (data == anuncios[i]->getData())
			res.push_back(i);
	}

	return res;
}

vector<int> Website::procurarPalavraChave(string palavra) {
	vector<int> res;
	for (int i = 0; i < anuncios.size(); i++) {

		unsigned int found = anuncios[i]->getTitulo_Descricao().find(palavra);
		if (found != string::npos) {
			res.push_back(i);
		}
	}
	return res;
}

vector<int> Website::procurarPreco(int min, int max) {
	vector<int> res;

	for (unsigned int i = 0; i < anuncios.size(); i++) {
		if (anuncios[i]->getTipo() == TIPO_VENDA) {
			AnuncioVenda *av = dynamic_cast<AnuncioVenda*>(anuncios[i]);
			if (av->getPreco() >= min && av->getPreco() <= max) {
				res.push_back(i);
			}
		}
	}
	return res;
}

//menus pesquisar anuncios
void Website::contactar(int id) {
	string mensagem;
	string nome;
	string email;
	string telefone;

	system("cls");
	intro();
	if (Menu::logado) {
		cout << "Mensagem: " << endl;
		getline(cin, mensagem);
		anuncios[id]->enviarMensagem(
				Contacto(mensagem,
						utilizadores[indiceUtilizador]->getDadosPessoais()));
	} else {
		do {
			system("cls");
			intro();
			cout << "Nome: ";
			getline(cin, nome);
		} while (nome.size() == 0);

		cout << "Telefone: ";
		getline(cin, telefone);

		while (telefone.size() < 9) {
			system("cls");
			intro();
			setcolor(12);
			cout << "Numero Invalido (Deve conter 9 ou mais digitos)" << endl;
			setcolor(15);
			cout << "Telefone: ";
			getline(cin, telefone);
		}

		do {
			system("cls");
			intro();
			cout << "Email: ";
			getline(cin, email);
		} while (email.size() == 0);

		DadosPessoais dados(nome, telefone, email);

		system("cls");
		intro();
		cout << "Mensagem: " << endl;
		getline(cin, mensagem);
		anuncios[id]->enviarMensagem(Contacto(mensagem, dados));
	}
}

int Website::menuAnuncioPalavra() {

	string p;
	system("cls");
	intro();
	cout << "Introduza a Palavra-Chave: ";
	getline(cin, p);

		vector<int> indices = procurarPalavraChave(p);
		if (indices.size() == 0) {
			setcolor(12);
			cout << "Palavra nao encontrada. ";
			setcolor(15);
			getch();
			return 4;
		}

		return subMenuAnuncio(indices);
}

int Website::menuAnuncioData() {

	int dia, mes, ano;
	bool erro;

	system("cls");
	intro();
	cout << "Introduza a Data: ";

	while (true) {
		system("cls");
		intro();
		if (erro) {
			setcolor(12);
			cout << "Caracter Invalido" << endl;
			setcolor(15);
		}
		cout << "Dia: ";
		cin >> dia;

		if (cin.fail()) {
			erro = true;
			cin.clear();
			cin.ignore();
		} else {
			break;
		}
	}
	erro = false;
	while (true) {
		system("cls");
		intro();
		if (erro) {
			setcolor(12);
			cout << "Caracter Invalido" << endl;
			setcolor(15);
		}
		cout << "Mes: ";
		cin >> mes;

		if (cin.fail()) {
			erro = true;
			cin.clear();
			cin.ignore();
		} else {
			break;
		}
	}
	erro = false;
	while (true) {
		system("cls");
		intro();
		if (erro) {
			setcolor(12);
			cout << "Caracter Invalido" << endl;
			setcolor(15);
		}
		cout << "Ano: ";
		cin >> ano;

		if (cin.fail()) {
			erro = true;
			cin.clear();
			cin.ignore();
		} else {
			break;
		}
	}

	Data d(ano, mes, dia);

	vector<int> indices = procurarData(d);
	if (indices.size() == 0) {
		setcolor(12);
		cout << "Nao existem anuncios com a data especificada. ";
		setcolor(15);
		getch();
		return 4;
	}

	return subMenuAnuncio(indices);

}

int Website::subMenuAnuncio(vector<int>& indices) {

	while(true){

		Menu::idAnuncio = Menu::menuAnuncioInterface(indices);
		if(Menu::idAnuncio==-1){
			return 4;
		}

		int y;
		bool vis = true;
		bool verExterno = true;
		if (indiceUtilizador != -1)
			if (utilizadores[indiceUtilizador]->getID() == anuncios[Menu::idAnuncio]->getUser()->getID())
				verExterno = false;

		if (verExterno) {
			do {
				if (vis) {
					anuncios[Menu::idAnuncio]->visualizacao();
					vis = false;
				}
				y = Menu::interfacemenuAnuncio();
				if (!y) {
					contactar(Menu::idAnuncio);
				}
			} while (!y);
			vis = true;

		} else {
			system("cls");
			intro();
			if (Website::getAnuncios()[Menu::idAnuncio]->getTipo())
				cout<< (*dynamic_cast<AnuncioVenda*>(Website::getAnuncios()[Menu::idAnuncio]));
			else
				cout<< (*dynamic_cast<AnuncioCompra*>(Website::getAnuncios()[Menu::idAnuncio]));
			setcolor(3);
			cout <<endl << setw(45) <<"Prima qualquer tecla para voltar atras";
			setcolor(15);
			getch();
		}

	}
}

int Website::menuAnuncioCategoria() {
	string c;
	system("cls");
	intro();
	cout << "Introduza a Categoria que deseja procurar: ";
	getline(cin, c);

	vector<int> indices = procurarCategoria(c);
	if (indices.size() == 0) {
		setcolor(12);
		cout << "Nao existem Anuncios da Categoria" << c << ". ";
		setcolor(15);
		getch();
		return 4;
	}
	return subMenuAnuncio(indices);
}

int Website::menuAnuncioLocalizacao() {
	string l;
	system("cls");
	intro();
	cout << "Introduza a Localizao na qual deseja procurar o anuncio: " << endl;
	getline(cin, l);

	vector<int> indices = procurarLocalizacao(l);
	if (indices.size() == 0) {
		setcolor(12);
		cout << "N�o existem Anuncios em " << l << ". ";
		setcolor(15);
		getch();
		return 4;
	}

	return subMenuAnuncio(indices);
}
//ordenar

void Website::ordenaPreco(vector<int>& v, bool crescente) {
	for (unsigned int p = 1; p < v.size(); p++) {
		int tmp = v[p];
		int j;
		if (crescente) {
			for (j = p;
					j > 0
							&& anuncios[tmp]->getPreco()
									< anuncios[v[j - 1]]->getPreco(); j--) {
				v[j] = v[j - 1];
			}
		} else {
			for (j = p;
					j > 0
							&& anuncios[tmp]->getPreco()
									> anuncios[v[j - 1]]->getPreco(); j--) {
				v[j] = v[j - 1];
			}
		}
		v[j] = tmp;
	}
}

int Website::menuAnuncioPreco(bool crescente) {
	float min, max;
	bool erro;

	system("cls");
	intro();
	cout << "Introduza a Data: ";

	while (true) {
		system("cls");
		intro();
		if (erro) {
			setcolor(12);
			cout << "Caracter Invalido" << endl;
			setcolor(15);
		}
		cout << "Valor minimo: ";
		cin >> min;

		if (cin.fail()) {
			erro = true;
			cin.clear();
			cin.ignore();
		} else {
			break;
		}
	}
	erro = false;
	while (true) {
		system("cls");
		intro();
		if (erro) {
			setcolor(12);
			cout << "Caracter Invalido" << endl;
			setcolor(15);
		}
		cout << "Valor Maximo: ";
		cin >> max;

		if (cin.fail()) {
			erro = true;
			cin.clear();
			cin.ignore();
		} else {
			break;
		}
	}


		vector<int> indices = procurarPreco(min, max);
		if (indices.size() == 0) {
			setcolor(12);
			cout << "Nao existem Produtos no intervalo de preco " << min
					<< "<->" << max;
			setcolor(15);
			getch();
			return 4;
		}
		ordenaPreco(indices, crescente);
		return subMenuAnuncio(indices);
}

//ficheiros

void Website::guardarFicheiro(ofstream& file) {
	Dados::setVetorAnuncio(&anuncios);
	Dados::setVetorUtilizadores(&utilizadores);
	Dados::setVetorNegocios(&negocios);

	Dados::escreverFicheiro(file);
}
void Website::lerFicheiro(ifstream& file) {

	Dados::setVetorAnuncio(&anuncios);
	Dados::setVetorUtilizadores(&utilizadores);
	Dados::setVetorNegocios(&negocios);

	Dados::lerFicheiro(file);
	getch();

}

//meus anuncios

vector<int> Website::anunciosParaIndices(const vector<Anuncio*>& aTemp) {
	vector<int> res;
	for (unsigned int i = 0; i < aTemp.size(); ++i) {
		for (unsigned int k = 0; k < anuncios.size(); k++) {
			if (aTemp[i]->getID() == anuncios[k]->getID()) {
				res.push_back(k);
				break;
			}
		}
	}

	return res;
}

vector<int> Website::retornarMeusAnuncios(bool venda) {
	return anunciosParaIndices(utilizadores[indiceUtilizador]->getAnuncios(venda));
}

int Website::MenuAnuncioConta(bool venda) {
	bool semcontatos = true;

	while (true) {
		if (retornarMeusAnuncios(venda).size() == 0) {
			system("cls");
			intro();
			setcolor(12);
			cout << "Voce nao tem anuncios de ";
			cout << ((venda) ? "Venda" : "Compra");
			setcolor(15);
			getch();
			return 3;
		}
		if (semcontatos) {
			Menu::idAnuncio = Menu::menuAnuncioInterface(
					retornarMeusAnuncios(venda));

			if (Menu::idAnuncio == -1)
				return 3;
		}
		int y = Menu::interfaceAnuncioDefinicoes();
		semcontatos = true;
		if (y == 0) { //ver contatos
			vector<Contacto> c = anuncios[Menu::idAnuncio]->getContactos();
			if (c.size() == 0) {
				system("cls");
				intro();
				setcolor(12);
				cout << "Voce nao tem mensagens referentes a este anuncio";
				setcolor(15);
				semcontatos = false;
				getch();
				continue;
			}

			system("cls");
			intro();
			for (unsigned int i = 0; i < c.size(); ++i) {
				setcolor(3);
				cout << "Dados: " << endl;
				setcolor(15);
				DadosPessoais dp = c[i].getDados();
				cout << dp << endl;
				setcolor(3);
				cout << "Mensagem:" << endl;
				setcolor(15);
				cout << c[i].getMensagem() << endl << endl;
			}
			getch();
		} else if (y == 1) { //remove anuncio
			RemoveAnuncio(anuncios[Menu::idAnuncio]->getID());
		}else if(y==2){
			criaNegocio(anuncios[Menu::idAnuncio]);
		}
	}
}


void Website::criaNegocio(Anuncio* a){
	float montante= 0;
	bool erro = false;

	bool adicionarMontante=false;

	if(a->getTipo()==TIPO_VENDA ){
		adicionarMontante=true;
	}else{
		AnuncioCompra* ac = dynamic_cast<AnuncioCompra*>(a);
		if(ac->getAnuncioVenda() != NULL){
			string letra;
			do {
				system("cls");
				intro();
				cout << "O Anuncio foi resultado de troca?(S/N): ";
				getline(cin, letra);
			} while (letra != "s" && letra != "S" && letra != "n" && letra != "N");

			if (letra == "s" || letra == "S")
				adicionarMontante = false;
			else{
				adicionarMontante = true;
				ac->setAnuncioVenda(NULL);
			}
		}else{
			adicionarMontante=true;
		}
	}
	if(adicionarMontante){
		while (true){
			system("cls");
			intro();
			if (erro) {
				setcolor(12);
				cout << "Caracter Invalido" << endl;
				setcolor(15);
			}
			cout << "Montante: ";
			cin >> montante;

			if (cin.fail()) {
				erro = true;
				cin.clear();
				cin.ignore();
			} else {
				break;
			}
		}
	}
	utilizadores[indiceUtilizador]->FecharNegocio(a,montante,_data);
	getch();
	setcolor(3);
	cout << "Negocio Finalizado Com Sucesso!";
	setcolor(15);
	getch();
}

int Website::menuMeusNegocios(){

	while(true){
		if(utilizadores[indiceUtilizador]->getNegocios().size()==0){
			system("cls");
			intro();
			setcolor(12);
			cout << "Voce nao tem Negocios ";
			setcolor(15);
			getch();
			return 3;
		}
		Negocio* negocio = Menu::menuNegocioInterface(utilizadores[indiceUtilizador]->getNegocios());
		if(negocio==NULL)
			return 3;
		system("cls");
		intro();
		cout << (*negocio);

		setcolor(3);
		cout << "Prima qualquer Tecla para sair";
		getch();
		setcolor(15);
	}
}




