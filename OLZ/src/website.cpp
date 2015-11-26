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

void Website::RemoveNegocio(int id) { //só remove do vetor negocios

	for (unsigned int i = 0; i < negocios.size(); ++i) {
		if (negocios[i]->getID() == id) {
			negocios.erase(negocios.begin() + i);
			break;
		}
	}
}

//funçoes interaão com o usuario
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

bool Website::emailExiste(string email){
	bool rep=false;

	for (unsigned int i = 0; i < utilizadores.size(); ++i) {
		if(utilizadores[i]->getDadosPessoais().getEmail()==email){
			rep=true;
			break;
		}
	}
	return rep;
}

void Website::Registar() {

	string nome;
	string telefone;
	string email;
	string linha;
	do {
		system("cls");
		intro();
		cout << "Nome: ";
		getline(cin, nome);
	} while (nome.size() == 0);

	system("cls");
	intro();
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

	bool erro=false;

	do {
		system("cls");
		intro();
		if(erro){
			setcolor(12);
			cout << "Email Ja Existe!!" << endl;
			setcolor(15);
		}
		cout << "Email: ";
		cin>> email;
		getline(cin, linha);
		erro=emailExiste(email);
	} while ((email.size() == 0) || erro);


	DadosPessoais dados(nome, telefone, email);

	Localizacao loc_tmp;
	do {
		system("cls");
		intro();
		cout << "Freguesia: ";
		getline(cin, loc_tmp.freguesia);
	} while (loc_tmp.freguesia.size() == 0);
	do {
		system("cls");
		intro();
		cout << "Concelho: ";
		getline(cin, loc_tmp.concelho);
	} while (loc_tmp.concelho.size() == 0);
	do {
		system("cls");
		intro();
		cout << "Distrito: ";
		getline(cin, loc_tmp.distrito);
	} while (loc_tmp.distrito.size() == 0);


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

	//erro propositado;

	titulo = InputLinha("Titulo Do Anuncio de Compra: ");

	categ_produto = InputLinha("Categoria do Produto: ");

	descricao = InputLinha("Descricao:", true);

	data = _data;

	imagens = InputVetorString("Prima enter se nao quiser adicionar mais imagens: ");


	AnuncioCompra *ac = new AnuncioCompra(titulo, categ_produto, descricao,
			data);
	ac->setUser(utilizadores[indiceUtilizador]);


	if(utilizadores[indiceUtilizador]->getAnuncios(true).size() != 0){

		ptrAV= InputBool("Deseja escolher um dos seus anuncios de venda? (S/N) \n (Indicando assim, a possibilidade de trocar o\n produto que esta a vender,pelo produto deste anuncio)");
	}else
		ptrAV=false;

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

		ac->setAnuncioVenda(dynamic_cast<AnuncioVenda*>(anuncios[Menu::idAnuncio]));
	}

	for (unsigned int i = 0; i < imagens.size(); ++i) {
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
	string erroS;
	string letra;
	int estado;
	string imagem;
	vector<string> imagens;

	titulo = InputLinha("Titulo Do Anuncio de Venda: ");

	categ_produto = InputLinha("Categoria do Produto: ");

	descricao = InputLinha("Descricao:", true);

	data = _data;

	imagens = InputVetorString("Prima enter se nao quiser adicionar mais imagens: ");

	preco = Inputfloat("O preco deve ser maior que zero: ");

	negociavel=InputBool("Negociavel?(S/N) ");

	estado = Menu::interfaceCategProd();

	AnuncioVenda *av = new AnuncioVenda(titulo, categ_produto, descricao, data,	preco, negociavel, estado);
	av->setUser(utilizadores[indiceUtilizador]);

	for (unsigned int i = 0; i < imagens.size(); ++i) {
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

	for (unsigned  int i = 0; i < anuncios.size(); i++) {
		Localizacao l = anuncios[i]->getUser()->getLocalizacao();
		if (l.freguesia == loc || l.distrito == loc || l.concelho == loc)
			res.push_back(i);
	}

	return res;
}

vector<int> Website::procurarCategoria(string categoria) {
	vector<int> res;

	for (unsigned  int i = 0; i < anuncios.size(); i++) {
		if (categoria == anuncios[i]->getCategoria())
			res.push_back(i);
	}

	return res;

}

vector<int> Website::procurarData(Data data) {
	vector<int> res;

	for (unsigned int i = 0; i < anuncios.size(); i++) {
		if (data == anuncios[i]->getData())
			res.push_back(i);
	}

	return res;
}

vector<int> Website::procurarPalavraChave(string palavra) {
	vector<int> res;
	for (unsigned int i = 0; i < anuncios.size(); i++) {

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
		nome = InputLinha("Nome: ");

		telefone = InputInteiro("Telefone: ", 9);


		email = InputLinha("Email: ");

		DadosPessoais dados(nome, telefone, email);

		mensagem = InputLinha("Mensagem: ");

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
			else{
				AnuncioCompra *ac = dynamic_cast<AnuncioCompra*>(Website::getAnuncios()[Menu::idAnuncio]);
				cout<< (*ac);
				if(ac->troca()){
					setcolor(3);
					cout << "----------------Anuncio Venda Associado----------------"<< endl;
					setcolor(15);
					cout << (*ac->getAnuncioVenda());
				}
			}
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
		cout << "Não existem Anuncios em " << l << ". ";
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
			for (j = p;	j > 0 && anuncios[tmp]->getPreco()< anuncios[v[j - 1]]->getPreco(); j--) {
				v[j] = v[j - 1];
			}
		} else {
			for (j = p;	j > 0 && anuncios[tmp]->getPreco() > anuncios[v[j - 1]]->getPreco(); j--) {
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
			Menu::idAnuncio = Menu::menuAnuncioInterface(retornarMeusAnuncios(venda));
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
				cout << "------------- Contacto " << i+1 << "------------" << endl;

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
			setcolor(3);
			cout << "------------- Prima Qualquer Tecla Para Sair ------------" << endl;

			setcolor(3);
			getch();
		} else if (y == 1) { //remove anuncio
			RemoveAnuncio(anuncios[Menu::idAnuncio]->getID());
		}else if(y==2){//cria negocio
			criaNegocio(anuncios[Menu::idAnuncio]);
		}
		else if(y==3){//editar
			semcontatos=false;
			int ind;
			if(anuncios[Menu::idAnuncio]->getTipo()==TIPO_VENDA)
				ind=Menu::interfaceEditarAnuncio_AV();
			else
				ind = Menu::interfaceEditarAnuncio_AC();

			Imagem img;
			AnuncioVenda *av = dynamic_cast<AnuncioVenda*>(anuncios[Menu::idAnuncio]);
			AnuncioCompra *ac = dynamic_cast<AnuncioCompra*>(anuncios[Menu::idAnuncio]);

			switch (ind) {
			case 0:
				anuncios[Menu::idAnuncio]->setTitulo(InputLinha("Novo Titulo: "));
				break;
			case 1:
				anuncios[Menu::idAnuncio]->setCategoria(InputLinha("Nova Categoria: "));
				break;
			case 2:
				anuncios[Menu::idAnuncio]->setDescricao(InputLinha("Nova Descricao: ",true));
				break;
			case 3:
				img.conteudo =InputLinha("Nova Imagem: ");
				anuncios[Menu::idAnuncio]->AdicionarImagem(img);
				break;
			case 4:
				anuncios[Menu::idAnuncio]->eliminaImagens();
				break;
			case 5:
				if(anuncios[Menu::idAnuncio]->getTipo()==TIPO_VENDA){
					av->setPreco(Inputfloat("Novo Preco: "));
				}else{

					int novoMenu = Menu::menuAnuncioInterface(retornarMeusAnuncios(true));
					if(novoMenu!= -1)
						ac->setAnuncioVenda(dynamic_cast<AnuncioVenda*>(anuncios[novoMenu]));
				}
				break;
			case 6:
				if(anuncios[Menu::idAnuncio]->getTipo()==TIPO_VENDA){
				av->setNegociavel(InputBool("Negociavel?(S/N) "));
				}else{
					ac->setAnuncioVenda(NULL);
				}
				break;
			case 7:
				av ->setEstado(Menu::interfaceCategProd());

				break;
			}

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

void Website::alterarDadosVisiveis(){
	int y = 0;
	string visiveis[]= {"","",""};
	bool update= true;
	bool* v= utilizadores[indiceUtilizador]->getDadosVisiveis();

	for (int i = 0; i < VIS_TOTAL; ++i) {
		if(v[i])
			visiveis[i]="Visivel";
		else
			visiveis[i]="Invisivel";
	}
	bool updateDados=false;


	while (true) {


		if(updateDados){
			updateDados=false;
			switch(y){
			case VIS_NOME:
				v[VIS_NOME]=!v[VIS_NOME];
				if(v[VIS_NOME]){
					visiveis[VIS_NOME] = "Visivel";
				}else{
					visiveis[VIS_NOME] = "Invisivel";
				}

				break;
			case VIS_TELEFONE:
				v[VIS_TELEFONE]=!v[VIS_TELEFONE];
				if(v[VIS_TELEFONE]){
					visiveis[VIS_TELEFONE] = "Visivel";
				}else{
					visiveis[VIS_TELEFONE] = "Invisivel";
				}

				break;
			case VIS_EMAIL:
				v[VIS_EMAIL]=!v[VIS_EMAIL];
				if(v[VIS_EMAIL]){
					visiveis[VIS_EMAIL] = "Visivel";
				}else{
					visiveis[VIS_EMAIL] = "Invisivel";
				}
				break;
			}
		}



		if(update){
			update=false;
			system("cls");
			Website::intro();
			cout << "Alterar Visibilidade: " << endl << endl;
			cout << setw(20) << Highlight("Nome: ", y, 0)  <<visiveis[VIS_NOME]<< endl;
			setcolor(15);
			cout << setw(20) << Highlight("Telefone: ", y, 1)<<visiveis[VIS_TELEFONE] << endl;
			setcolor(15);
			cout << setw(20) << Highlight("Email: ", y, 2)<<visiveis[VIS_EMAIL] << endl;
			setcolor(15);
		}


		y= (y<0)? 0 : (y>2)? 2 : y;

		if (kbhit()) {
			int tecla = getch();
			if (tecla == 72) { // para cima
				if (y > 0) { //não diminui o indice se já estiver na posição com o menor indice
					y--;
					update=true;
				}
			} else if (tecla == 80) { // para baixo
				if (y < 2) { //não aumenta o indice se já estiver na posição com o maior indice
					y++;
					update=true;
				}
			} else if (tecla == 13) { // enter
				updateDados=true;
				update=true;
			}
			else if(tecla == 27){//esc

				return;
			}
		}
	}

}

//--------Validar input



string Website::InputLinha(string mensagemLoop , bool vazio){
	string linha;
	do {
			system("cls");
			intro();
			cout << mensagemLoop;
			getline(cin, linha);
	} while (linha.size() == 0 && !vazio );

	return linha;
}

vector<string> Website::InputVetorString(string mensagemLoop){
	vector<string> res;
	string linha;
	do {
		system("cls");
		intro();
		cout << mensagemLoop << endl;
		getline(cin, linha);
		res.push_back(linha);
	} while (linha != "");
	res.pop_back();
	return res;
}

bool Website::InputBool(string mensagemLoop){
	string linha;

	do {
		system("cls");
		intro();
		cout << mensagemLoop<<endl;
		getline(cin, linha);
	} while (linha != "s" && linha != "S" && linha != "n" && linha != "N");

	if (linha == "s" || linha == "S")
		return true;
	else
		return false;
}

float Website::Inputfloat(string mensagemLoop){
	string linha;
	bool erro=false;
	string erroS;
	float valor;
	while (true) {
		system("cls");
		intro();
		if (erro) {
			setcolor(12);
			cout << erroS << endl;
			setcolor(15);
		}
		cout << "Preco: ";
		cin >> valor;

		if (cin.fail()) {
			erro = true;
			erroS = "Caracter Invalido";
			cin.clear();
			cin.ignore();
		} else if (valor <= 0.01f) {
			erro = true;
			erroS = mensagemLoop;
		} else {
			erro = false;
			break;
		}
	}
	getline(cin, erroS);
	return valor;
}

string Website::InputInteiro(string mensagemLoop, unsigned int casas){
	bool erro=false;
	string linha;

	do{
		system("cls");
		intro();
		setcolor(12);
		if(erro){
			cout << "Numero Invalido,(deve conter pelo menos "<<casas<<" casas"<< endl;
			erro = false;
		}
		setcolor(15);
		cout << mensagemLoop;

		getline(cin, linha);
		if(linha.size() < casas)
			erro=true;
	}while (erro);

	return linha;
}
//editar utilizador

int Website::EditarUtilizador(){

	while(true){
		int y= Menu::interfaceEditarUtilizador();

		switch (y) {
		case 0:
			utilizadores[indiceUtilizador]->setNome(InputLinha("Novo Nome: "));
			break;
		case 1:
			utilizadores[indiceUtilizador]->setTelefone(InputLinha("Novo Telefone: "));
			break;
		case 2:
			utilizadores[indiceUtilizador]->setEmail(InputLinha("Novo Email: "));
			break;
		case 3:
			alterarDadosVisiveis();
			break;
		case 4:
			utilizadores[indiceUtilizador]->setFreguesia(InputLinha("Nova Freguesia: "));
			break;
		case 5:
			utilizadores[indiceUtilizador]->setConcelho(InputLinha("Novo Concelho: "));
			break;
		case 6:
			utilizadores[indiceUtilizador]->setDistrito(InputLinha("Novo Distrito: "));
			break;
		case 7:
			RemoveUtilizador(utilizadores[indiceUtilizador]->getID());
			return 0;
			break;
		default:
			return 3;
			break;
		}
	}
}

 vector<Utilizador*> Website::BSTParaVetor(BST<Utilizador*>& bst){
	 vector<Utilizador*> util;
	 BSTItrIn<Utilizador*> ordem = BSTItrIn<Utilizador*>(bst);

	 while(!ordem.isAtEnd()){

		 Utilizador* u = ordem.retrieve();
		 cout <<"Utilizador Adicionado: "<<u->getDadosPessoais().getNome() << endl;
		 getch();
		 util.push_back(u);
		 ordem.advance();
	 }

	 return util;
 }



 BST<Utilizador*> Website::ReturnUtilizadoresBST(){

	 BST<Utilizador*> res(NULL);
	 int n=0;
	 for (unsigned int i = 0; i < utilizadores.size(); ++i) {

		 Utilizador* u =utilizadores[i];


		 if(u->getNegocios().size() !=0){
			 n++;
			 cout<<"Adicionado:" << u->getDadosPessoais().getNome() << " Teste:" << u->getNegocios()[u->getNegocios().size()-1]->getData()<<endl;
					 getch();
			 res.insert(u , compareUsers_ptr);
		 }
	 }

	 return res;
 }


 void Website::menuTopNegocios(){

	 BST<Utilizador*> bst_util =ReturnUtilizadoresBST();

	 vector<Utilizador*> util= BSTParaVetor(bst_util);


	 if(util.size()==0){
		 setcolor(12);
		 cout << "Não existem Utilizadores" << endl;
		 setcolor(15);
		 return;
	 }

	 Utilizador* u;

	 do{
		 u = Menu::menuTopNegociantesInterface(util);
		 if(u ==NULL)
			 return;
		 system("cls");
		 intro();
		 cout<< (*u) << endl;
		 setcolor(3);
		 cout << "------------- Prima Qualquer Tecla Para Sair ------------" << endl;
		 setcolor(15);
		 getch();
	 }while(true);
 }











