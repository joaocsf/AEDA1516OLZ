#include "anuncio.h"
#include "utilizador.h"
//anuncios
int Anuncio::_ID = 1;

Anuncio::~Anuncio(){
	_user = NULL;
}

int Anuncio::getIDGlobal() {
	return _ID;
}
void Anuncio::setIDGlobal(int id) {
	_ID = id;
}
Anuncio::Anuncio(string titulo, string categ_produto, string descricao,
		Data date) :
		_num_vizualizacoes(0), _titulo(titulo), _categ_produto(categ_produto), _descricao(descricao),
		_data(date), _identificador(_ID++), _user(NULL), _visivel(true), _data_destaque(0,0,0) {
}

bool Anuncio::getPrioridade(){

	return	(*_dataAtual) < _data_destaque;

}

void Anuncio::ler(ifstream& in, bool escreve) {
	string linha;
	int index = 0;
	while (getline(in, linha)) {
		switch (index) {
		case A_IDENFICADOR:
			stringstream(linha) >> _identificador;
			break;

		case A_TITULO:
			_titulo = linha;
			break;

		case A_CATEG:
			_categ_produto = linha;
			break;

		case A_DESC:
			_descricao= linha;
			break;

		case A_N_VIS:
			stringstream(linha) >> _num_vizualizacoes;
			break;

		case A_VISIVEL:
			int temp;
			stringstream(linha) >> temp;
			_visivel = temp;
			break;

		case A_DATA:
			if(linha == "DAT"){
				_data.ler(in);
			}else{
				stringstream ss;
				ss << "Erro Leitura Anuncio. Encontrado:" << linha
						<< " Esperado: DAT";
				throw ErroLeitura(ss.str());
			}
			break;

		case A_DATA_DESTAQUE:
			if(linha == "DAT"){
				_data_destaque.ler(in);
			}else{
				stringstream ss;
				ss << "Erro Leitura Anuncio. Encontrado:" << linha
						<< " Esperado: DAT";
				throw ErroLeitura(ss.str());
			}
			break;

		default:
			if (linha == "I") {
				getline(in, linha);
				Imagem temp;
				temp.conteudo = linha;
				_imagens.push_back(temp);
				getline(in, linha);
			} else if (linha == "C") {
				Contacto cTemp;
				cTemp.ler(in);
				_contactos.push_back(cTemp);
			} else if (linha == "#V") {
				return;
			} else {
				stringstream ss;
				ss << "Erro Leitura Anuncio. Encontrado:" << linha
						<< " Esperado:#V / C / I / DAT";
				throw ErroLeitura(ss.str());
			}
			break;
		}
		index++;
	}

}

void Anuncio::alterarVisibilidade() {
	_visivel = !_visivel;
}

string Anuncio::getTitulo() const {
	return _titulo;
}
void Anuncio::setVisibilidade(bool vis){
	_visivel = vis;
}

bool Anuncio::getVisibilidade() {
	return _visivel;
}
string Anuncio::getInfo() const {
	string info;
	stringstream ss;
	ss << "Identificador  " << _identificador << endl;
	ss << "Titulo........." << _titulo << endl;
	ss << "Categoria      " << _categ_produto << endl;
	ss << "Descricao......" << _descricao << endl;
	ss << "Visualizacoes  " << _num_vizualizacoes << endl;
	ss << "Visibilidade...." << ((_visivel) ? "Visivel" : "Invisivel") << endl;
	ss << "Data          " << _data.getDia() << ":" << _data.getMes() << ":"
			<< _data.getAno() << endl;
	for (int i = 0; i < _imagens.size(); ++i) {
		ss << "  I:" << _imagens[i].conteudo << endl;
	}
	for (int i = 0; i < _contactos.size(); ++i) {
		ss << "Contactos:\n" << _contactos[i].getInfo() << endl;
	}

	info += ss.str();
	return info;
}

void Anuncio::enviarMensagem(Contacto c) {
	_contactos.push_back(c);
}

void Anuncio::escrever(ofstream& out) {
	out << _identificador << endl;
	out << _titulo << endl;
	out << _categ_produto << endl;
	out << _descricao << endl;
	out << _num_vizualizacoes << endl;
	out << ((_visivel) ? 1 : 0) << endl;
	_data.escrever(out);
	_data_destaque.escrever(out);
	for (int i = 0; i < _imagens.size(); ++i) {
		out << "I" << endl << _imagens[i].conteudo << endl << "#I" << endl;
	}
	for (int i = 0; i < _contactos.size(); ++i) {
		_contactos[i].escrever(out);
	}
	out << "#V" << endl; //Sinaliza Fim vetor
}
void Anuncio::setUser(Utilizador* user) {
	_user = user;
}

void Anuncio::setDataAtual(Data* data){
	_dataAtual=data;
}

int Anuncio::getID() const {
	return _identificador;
}

string Anuncio::getTitulo_Descricao() const {
	return _titulo + _descricao;
}

Data Anuncio::getData() const {
	return _data;
}

string Anuncio::getCategoria() const {
	return _categ_produto;
}

Utilizador* Anuncio::getUser() {
	return _user;
}

void Anuncio::AdicionarImagem(Imagem img) {
	_imagens.push_back(img);
}

void Anuncio::setImagens(vector<Imagem> img) {
	_imagens = img;
}

float Anuncio::getPreco() const {
	return -1;
}
vector<Contacto> Anuncio::getContactos() const {
	return _contactos;
}
void Anuncio::eliminaImagens(){
	_imagens.clear();
}

void Anuncio::setTitulo(string t){
	_titulo= t;
}

void Anuncio::setCategoria(string c){
	_categ_produto=c;
}
void Anuncio::setDescricao(string d){
	_descricao=d;
}

Data Anuncio::getDataAtual(){
	if(_dataAtual != NULL)
		return *_dataAtual;
	return Data(0,0,0);
}

void Anuncio::adicionarMensalidade(){
	if(_data_destaque < *_dataAtual)
		_data_destaque = *_dataAtual;

	_data_destaque.addMes();
}

bool operator<(AnuncioHandler aH1,AnuncioHandler aH2){
	Data d1 = aH1.a->getData();
	Data dd1 = aH1.a->getDataDestaque();
	Data d2 = aH2.a->getData();
	Data dd2 = aH2.a->getDataDestaque();
	bool p_1 = (d1 < dd1);
	bool p_2 = (d2 < dd2);
	if (p_1 && !p_2) return false;
	if (p_2 && !p_1) return true;
	if (p_1 && p_2) return (dd1 < dd2);
	if (!p_1 && !p_2) return (d1 < d2);
	return false;
}


//anuncio venda
AnuncioVenda::AnuncioVenda(string titulo, string categ_produto,
		string descricao, Data date, float preco, bool negociavel, int estado) :
		Anuncio(titulo, categ_produto, descricao, date), _preco(preco), _negociavel(
				negociavel), _estado(estado) {
}

void AnuncioVenda::ler(ifstream& in, bool escreve) {
	Anuncio::ler(in);
	string linha;
	int index = 0;
	while (getline(in, linha)) {
		switch (index) {
		case A_PRECO:
			stringstream(linha) >> _preco;
			break;
		case A_NEGOCIAVEL:
			int temp;
			stringstream(linha) >> temp;
			_negociavel = temp;
			break;
		case A_ESTADO:
			stringstream(linha) >> _estado;
			break;
		default:
			if (linha == "#AV") {
				return;
			} else {
				stringstream ss;
				ss << "Erro Leitura Anuncio Venda. Encontrado:" << linha
						<< " Esperado:#AV";
				throw ErroLeitura(ss.str());
			}
			break;
		}

		index++;
	}
}
void AnuncioVenda::escrever(ofstream& out) {
	out << "AV" << endl;
	Anuncio::escrever(out);
	out << _preco << endl;
	out << ((_negociavel) ? 1 : 0) << endl;
	out << _estado << endl;
	out << "#AV" << endl;

}

string AnuncioVenda::getInfo() const {
	string info = Anuncio::getInfo();
	stringstream ss;
	ss << "AnuncioVenda:" << endl;
	ss << "Preco:........." << _preco << endl;
	ss << "Negociavel:    " << ((_negociavel) ? "true" : "false") << endl;
	ss << "Estado:........";
	switch (_estado) {
	case ESTADO_FUNCIONAL:
		ss << "Funcional";
		break;
	case ESTADO_NOVO:
		ss << "Novo";
		break;
	case ESTADO_PECAS:
		ss << "Novo Para Pecas";
		break;
	case ESTADO_USADO:
		ss << "Usado";
		break;
	}
	ss << endl;

	return ss.str() + info;
}

int AnuncioVenda::getTipo() const {
	return TIPO_VENDA;
}

float AnuncioVenda::getPreco() const {
	return _preco;
}

void AnuncioVenda::setPreco(float preco){
	_preco=preco;
}

void AnuncioVenda::setNegociavel(bool negociavel){
	_negociavel=negociavel;
}
void AnuncioVenda::setEstado(int estado){
	_estado=estado;
}

//anuncio compra
AnuncioCompra::AnuncioCompra(string titulo, string categ_produto,
		string descricao, Data date) :
				Anuncio(titulo, categ_produto, descricao, date), _anuncioVenda(NULL) {
}

AnuncioCompra::~AnuncioCompra(){
	_anuncioVenda=NULL;
}

void AnuncioCompra::ler(ifstream& in, bool escreve) {
	Anuncio::ler(in);
	string linha;
	int index = 0;
	while (getline(in, linha)) {
		if (index == 0) { //Procurar Anuncio;
			int id;
			stringstream(linha) >> id;
			if (id != -1) {
				Utilizador* user = getUser();
				if (user != NULL) {
					Anuncio* aTemp = user->procurarAnuncio(id);
					_anuncioVenda = dynamic_cast<AnuncioVenda*>(aTemp);
				}
			} else {
				_anuncioVenda = NULL;
			}
		} else if (linha == "#AC") {
			return;
		} else {
			stringstream ss;
			ss << "Erro Leitura Anuncio Compra. Encontrado:" << linha
					<< " Esperado:#AC";
			throw ErroLeitura(ss.str());
		}

		index++;
	}

}

void AnuncioCompra::setAnuncioVenda(AnuncioVenda* anuncio) {
	_anuncioVenda = anuncio;
}

void AnuncioCompra::escrever(ofstream& out) {
	out << "AC" << endl;
	Anuncio::escrever(out);
	if (_anuncioVenda != NULL) {
		out << _anuncioVenda->getID() << endl;
	} else {
		out << "-1" << endl;
	}
	out << "#AC" << endl;
}
string AnuncioCompra::getInfo() const {
	string info;
	stringstream ss;
	ss << "Anuncio Compra:\n";
	ss << "TrocoPor: ";
	if (_anuncioVenda != NULL)
		ss << _anuncioVenda->getID();
	ss << endl;
	info += ss.str();
	info += Anuncio::getInfo();
	return info;
}

AnuncioVenda* AnuncioCompra::getAnuncioVenda() {
	return _anuncioVenda;
}

bool AnuncioCompra::troca() {
	return (_anuncioVenda != NULL);
}

int AnuncioCompra::getTipo() const {
	return TIPO_COMPRA;
}

void Anuncio::visualizacao() {
	_num_vizualizacoes++;
}

int Anuncio::getVisualizacoes() const {
	return _num_vizualizacoes;

}

//get
vector<Imagem> Anuncio::getImagens() const {
	return _imagens;
}

string Anuncio::getDescricao() const {
	return _descricao;
}

bool AnuncioVenda::getNegociavel() const {
	return _negociavel;
}

int AnuncioVenda::getEstado() const {
	return _estado;
}

Data Anuncio::getDataDestaque() const {
	return _data_destaque;
}

//overload <<

//falta o print dos dados do utilizador visiveis

ostream & operator<<(ostream & o, AnuncioVenda & av) {
	setcolor(3);
	o << endl << "Titulo: ";
	setcolor(15);
	o << av.getTitulo();
	setcolor(3);
	o << "  Num.Vizualizacoes: ";
	setcolor(15);
	o << av.getVisualizacoes() << endl;
	setcolor(3);
	o << "Categoria do Produto: ";
	setcolor(15);
	o << av.getCategoria() << endl;
	setcolor(3);
	o << "Data de Criacao: ";
	setcolor(15);
	o << av.getData() << endl;
	setcolor(3);
	o << "Data de fim Destaque: ";
	setcolor(15);
	o << av.getDataDestaque() << endl;
	setcolor(3);
	o << "Imagens: " << endl;
	setcolor(15);
	for (unsigned int i = 0; i < av.getImagens().size(); ++i) {
		o << av.getImagens()[i].conteudo << endl;
	}
	setcolor(3);
	o << "Descricao: ";
	setcolor(15);
	o << endl << av.getDescricao() << endl;
	//localizacao
	setcolor(3);
	o << "Localizacao do Anuncio: " << endl;
	o << "Distrito: ";
	setcolor(15);
	o << av.getUser()->getLocalizacao().distrito << endl;
	setcolor(3);
	o << "Concelho: ";
	setcolor(15);
	o << av.getUser()->getLocalizacao().concelho << endl;
	setcolor(3);
	o << "Freguesia: ";
	setcolor(15);
	o << av.getUser()->getLocalizacao().freguesia << endl;
	//-----------
	setcolor(3);
	o << "Preco: ";
	setcolor(15);
	o << av.getPreco() << " " << char(36);
	setcolor(3);
	o << "          Negociavel: ";
	setcolor(15);
	if (av.getNegociavel())
		cout << "Sim" << endl;
	else
		cout << "Nao" << endl;
	setcolor(3);
	o << "Estado: ";
	setcolor(15);
	switch (av.getEstado()) {
	case ESTADO_FUNCIONAL:
		o << "Funcional";
		break;
	case ESTADO_NOVO:
		o << "Novo";
		break;
	case ESTADO_PECAS:
		o << "Novo Para Pecas";
		break;
	case ESTADO_USADO:
		o << "Usado Como Novo";
		break;
	}
	o << endl;

	setcolor(3);
	o << "Dados Vendedor: " << endl;
	setcolor(15);
	DadosPessoais dp = av.getUser()->getDadosPessoais();
	o << dp;

	return o;
}

ostream & operator<<(ostream & o, AnuncioCompra & ac) {
	setcolor(3);
	o << endl << "Titulo: ";
	setcolor(15);
	o << ac.getTitulo();
	setcolor(3);
	o << "  Num.Vizualizacoes: ";
	setcolor(15);
	o << ac.getVisualizacoes() << endl;
	setcolor(3);
	o << "Categoria do Produto: ";
	setcolor(15);
	o << ac.getCategoria() << endl;
	setcolor(3);
	o << "Data de Criacao: ";
	setcolor(15);
	o << ac.getData() << endl;


	setcolor(3);
	o << "Data de fim Destaque: ";
	setcolor(15);
	o << ac.getDataDestaque() << endl;


	setcolor(3);
	o << "Imagens: " << endl;
	setcolor(15);
	for (unsigned int i = 0; i < ac.getImagens().size(); ++i) {
		o << ac.getImagens()[i].conteudo << endl;
	}
	setcolor(3);
	o << "Descricao: ";
	setcolor(15);
	o << endl << ac.getDescricao() << endl;
	//localizacao
	setcolor(3);
	o << "Localizacao do Anuncio: " << endl;
	o << "Distrito: ";
	setcolor(15);
	o << ac.getUser()->getLocalizacao().distrito << endl;
	setcolor(3);
	o << "Concelho: ";
	setcolor(15);
	o << ac.getUser()->getLocalizacao().concelho << endl;
	setcolor(3);
	o << "Freguesia: ";
	setcolor(15);
	o << ac.getUser()->getLocalizacao().freguesia << endl;
	//-----------
	setcolor(3);
	cout << "Troca: ";
	setcolor(15);
	if (ac.troca())
		cout << "Sim" << endl;
	else
		cout << "Nao" << endl;

	setcolor(3);
	o << "Dados Comprador: " << endl;
	setcolor(15);
	DadosPessoais dp = ac.getUser()->getDadosPessoais();
	o << dp;

	return o;
}

