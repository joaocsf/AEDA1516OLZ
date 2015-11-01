#include "website.h"

vector<Utilizador*> Website::utilizadores;
vector<Anuncio *> Website::anuncios;
vector<Negocio*> Website::negocios;


int Website::indiceUtilizador=-1;

Website::Website(){
}

vector<Utilizador*>  Website::getUtilizadores(){
	return utilizadores;
}

vector<Anuncio *>  Website::getAnuncios(){
	return anuncios;
}

vector<Negocio*>  Website::getNegocios(){
	return negocios;
}

void Website::addUtilizador(Utilizador *u){
	utilizadores.push_back(u);
}

void Website::addAnuncio(Anuncio *a){
	anuncios.push_back(a);
}

void Website::addNegocio(Negocio *n){
	negocios.push_back(n);
}

void Website::RemoveAnuncio(int id){
	int index;

	for (unsigned int i = 0; i < anuncios.size(); ++i) {
		if(anuncios[i]->getID()==id){
			anuncios.erase(anuncios.begin()+i);
			index=i;
			break;
		}
	}
anuncios[index]->getUser()->RemoverAnuncio(id);

}

void Website::RemoveUtilizador(int id){
	int index;

		for (unsigned int i = 0; i < utilizadores.size(); ++i) {
			if(utilizadores[i]->getID()==id){
				utilizadores.erase(utilizadores.begin()+i);
				index=i;
				break;
			}
		}
}

void Website::RemoveNegocio(int id){//só remove do vetor negocios
	int index;
	for (unsigned int i = 0; i < negocios.size(); ++i) {
		if(negocios[i]->getID()==id){
			negocios.erase(negocios.begin()+i);
			index=i;
			break;
		}
	}
}
//funçoes interaão com o usuario
int Website::getIndiceUtilizador(){
return indiceUtilizador;

}

void Website::login(){

	string login;

	cout << "Login:";
	cin >> login;
	for (unsigned int i = 0; i < utilizadores.size(); ++i) {
		if(utilizadores[i]->getDadosPessoais().getEmail()==login){
			indiceUtilizador = i;
			return;
		}
	}

	throw UtilizadorInixestente(login);
}

void Website::Registar(){

	string nome;
	string telefone;
	string email;
	cout << "Nome: ";
	getline(cin,nome);
	cout << "Telefone: " ;
	getline(cin,telefone);
	cout << "Email: " ;
	getline(cin,email);
	DadosPessoais dados(nome,telefone,email);

	Localizacao loc_tmp;
	cout << "Freguesia: ";
	getline(cin,loc_tmp.freguesia);
	cout << "Concelho: ";
	getline(cin,loc_tmp.concelho);
	cout << "Distrito: ";
	getline(cin,loc_tmp.distrito);

	utilizadores.push_back(new Utilizador(dados,loc_tmp));
	indiceUtilizador=utilizadores.size()-1;
}

void Website::logout(){
     indiceUtilizador=-1;
}






