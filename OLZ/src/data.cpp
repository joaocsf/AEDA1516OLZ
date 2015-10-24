#include "data.h"

Data::Data(unsigned int a, unsigned int m,unsigned int d)
{
ano = a;
mes = m;
dia = d;
}

void Data::setAno(unsigned int a) {
	ano=a;
}
void Data::setMes(unsigned int m){
	mes=m;
}

void Data::setDia(unsigned int d){
	dia=d;
}

void Data::setData(unsigned int a, unsigned int m, unsigned int d){
	ano=a;
	mes=m;
	dia=d;
}

unsigned int Data::getAno(){
	return ano;
}

unsigned int Data::getMes(){
	return mes;
}

unsigned int Data::getDia(){
	return dia;
}

void Data::imprime(){
	cout << ano << "/"<<  mes << "/" << dia;
}

