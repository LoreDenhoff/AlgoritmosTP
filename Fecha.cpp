#include "Fecha.h"
#include <stdexcept>
using namespace std;

Fecha::Fecha(){
	dia=1;
	mes=1;
	anio=2010;
}

Fecha::Fecha(int dia, int mes, int anio){
	if(!fechaValida(dia, mes, anio)){
		throw invalid_argument("La fecha ingresada no es valida");
	}
	this->dia=dia;
	this->mes=mes;
	this->anio=anio;
}

int Fecha::getDia() const{return dia;}
int Fecha::getMes() const{return mes;}
int Fecha::getAnio() const{return anio;}


bool Fecha::esBisiesto(int anio)const{
	return(anio%4==0 && anio%100!=0) || (anio%400==0);
}

int Fecha::diasMes(int mes, int anio) const{
	if(mes==1 ||mes==3 ||mes==5 ||mes==7 ||mes==8 ||mes==10 ||mes==12){
		return 31;
	}
	if (mes==4 ||mes==6 ||mes==9 ||mes==11){
		return 30;
	}
	if(mes==2){
		if(esBisiesto(anio)){
			return 29;
		}
		return 28;
	}
	return 0;
	}
	
bool Fecha::fechaValida(int dia, int mes, int anio) const{
	if(anio<=0){
		return false;
	}
	if(mes<1 || mes>12){
		return false;
	}
	if(dia<1 || dia>diasMes(mes, anio)){
		return false;
	}
	return true;
}

bool Fecha::menorIgualQue(Fecha otraFecha) const{
	if(anio<otraFecha.getAnio()){
		return true;
	}
	if(anio==otraFecha.getAnio() && mes<otraFecha.getMes()){
		return true;
	} 
	if(anio==otraFecha.getAnio() && mes==otraFecha.getMes() && dia<=otraFecha.getDia()){
		return true;
	}
	return false;
}

bool Fecha::mayorIgualQue(Fecha otraFecha) const{
	if(anio>otraFecha.getAnio()){
		return true;
	}
	if(anio==otraFecha.getAnio() && mes>otraFecha.getMes()){
		return true;
	}
	if(anio==otraFecha.getAnio() && mes==otraFecha.getMes() && dia>=otraFecha.getDia()){
		return true;
	}
	return false;
}



