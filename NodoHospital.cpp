#include "NodoHospital.h"

NodoHospital::NodoHospital(const Hospital& hospital){
	this->hospital=hospital;
	this->izquierda=NULL;
	this->derecha=NULL;
}

Hospital& NodoHospital::getHospital(){
	return hospital;
}

const Hospital& NodoHospital::getHospital() const{
	return hospital;
}

NodoHospital* NodoHospital::getIzquierda() const{
	return izquierda;
}

NodoHospital* NodoHospital::getDerecha() const{
	return derecha;
}

void NodoHospital::setIzquierda(NodoHospital* izquierda){
	this->izquierda=izquierda;
}

void NodoHospital::setDerecha(NodoHospital* derecha){
	this->derecha=derecha;
}
