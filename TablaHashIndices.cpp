#include "TablaHashIndices.h"
#include <iostream>
using namespace std;

EntradaIndice::EntradaIndice(int clave){
	this->clave=clave;
}

TablaHashIndices::TablaHashIndices(int capacidad){
	if(capacidad <= 0){
		cout << "Error: capacidad invalida. Seusara capacidad 100" << endl;
		this->capacidad=100;
	}else{
		this->capacidad=capacidad;
	}
	
	tabla.resize(capacidad);
}

int TablaHashIndices::funcionHash(int clave) const{
	if(capacidad <=0){
		return 0;
	}
	if(clave<0){
		clave=clave*-1;
	}
	return clave%capacidad;
}

void TablaHashIndices::insertar(int clave, int valor){
	int posicion=funcionHash(clave);
	
	for(int i=0; i<tabla[posicion].size(); i++){
		if(tabla[posicion][i].clave==clave){
			tabla[posicion][i].valores.push_back(valor);
			return;
		}
	}
	
	EntradaIndice nueva(clave);
	nueva.valores.push_back(valor);
	tabla[posicion].push_back(nueva);
}

bool TablaHashIndices::buscar(int clave, vector<int>& resultado) const{
	int posicion=funcionHash(clave);
	
	for(int i=0; i<tabla[posicion].size(); i++){
		if(tabla[posicion][i].clave==clave){
			resultado=tabla[posicion][i].valores;
			return true;
		}
	}
	return false;
}