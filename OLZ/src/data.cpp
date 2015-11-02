#include "data.h"

Data::Data(unsigned int a, unsigned int m, unsigned int d) {
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

void Data::setData(unsigned int a, unsigned int m, unsigned int d) {
	ano = a;
	mes = m;
	dia = d;
}

unsigned int Data::getAno() const{
	return ano;
}

unsigned int Data::getMes()const {
	return mes;
}

unsigned int Data::getDia()const {
	return dia;
}

void Data::imprime() {
	cout << ano << "/" << mes << "/" << dia;
}

void Data::ler(ifstream& in, bool escreve) {
	int index = 0;
	string linha;
	while (getline(in, linha)) {
		switch (index) {
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
			else
				cout << "MERDOU DATA\n";
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
	out << "#DAT" << endl;
}

bool operator==(const Data& d1, const Data& d2){

	return d1.getAno()==d2.getAno() && d1.getMes() == d2.getMes() && d1.getDia() == d2.getDia();
}
std::ostream & operator<<(ostream & o, const Data & d){
		o << d.getDia() << '/' << d.getMes() << '/' << d.getAno();
		return o;
	}



