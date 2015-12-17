#include "data.h"

Data::Data(unsigned int a, unsigned int m, unsigned int d) : hora(0), minutos(0){
	ano = a;
	mes = m;
	dia = d;
}

void Data::setAno(unsigned int a) {
	ano = a;
}
void Data::setMes(unsigned int m) {
	mes = m;
}

void Data::setDia(unsigned int d) {
	dia = d;
}

void Data::setHora(unsigned int h){
	hora = h;
}

void Data::setMinutos(unsigned int m){
	minutos = m;
}

void Data::setData(unsigned int a, unsigned int m, unsigned int d) {
	ano = a;
	mes = m;
	dia = d;
}

unsigned int Data::getAno() const {
	return ano;
}

unsigned int Data::getMes() const {
	return mes;
}

unsigned int Data::getDia() const {
	return dia;
}

unsigned int Data::getHora() const{
	return hora;
}

unsigned int Data::getMinutos() const{
	return minutos;
}

void Data::imprime() {
	cout << ano << "/" << mes << "/" << dia;
}

void Data::ler(ifstream& in, bool escreve) {
	int index = 0;
	string linha;
	while (getline(in, linha)) {
		switch (index) {
		case DATA_MINUTOS:
			stringstream(linha) >> minutos;
			break;
		case DATA_HORA:
			stringstream(linha) >> hora;
			break;
		case DATA_DIA:
			stringstream(linha) >> dia;
			break;
		case DATA_MES:
			stringstream(linha) >> mes;
			break;
		case DATA_ANO:
			stringstream(linha) >> ano;
			break;
		default:
			if (linha == "#DAT")
				return;
			else {
				stringstream ss;
				ss << "Erro Leitura Data. Encontrado:" << linha<< " Esperado:#DAT";
				throw ErroLeitura(ss.str());
			}
			break;
		}
		index++;
	}
}
void Data::escrever(ofstream& out) {
	out << "DAT" << endl;
	out << ano << endl;
	out << mes << endl;
	out << dia << endl;
	out << hora << endl;
	out << minutos << endl;
	out << "#DAT" << endl;
}

bool operator==(const Data& d1, const Data& d2) {

	return 	d1.getAno() == d2.getAno() 	 &&
			d1.getMes() == d2.getMes() 	 &&
			d1.getDia() == d2.getDia() 	 &&
			d1.getHora() == d2.getHora() &&
			d1.getMinutos() == d2.getMinutos();
}
std::ostream & operator<<(ostream & o, const Data & d) {
	o << d.getDia() << '/' << d.getMes() << '/' << d.getAno() << "  " <<d.getHora() << "h " << d.getMinutos() << "m";
	return o;
}

bool Data::operator< (const Data & d) const{
	if(this->ano < d.getAno() ){
		return true;

	}else if(this->ano == d.getAno()){
		if(this->mes < d.getMes()){
			return true;

		}else if (this->mes == d.getMes()){
			if(this->dia < d.getDia()){
				return true;

			}else if(this->dia == d.getDia()){
				if(hora < d.getHora()){
					return true;

				}else if(hora == d.getHora()){
					if(minutos < d.getMinutos()){
						return true;

					}
				}
			}
		}
	}
	return false;
}








