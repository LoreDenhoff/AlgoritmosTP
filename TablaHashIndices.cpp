#include "TablaHashIndices.h"

EntradaIndice::EntradaIndice(int clave){
	this->clave=clave;
}

TablaHashIndices::TablaHashIndices(int capacidad){
	this->capacidad=capacidad;
	tabla.resize(capacidad);
}

int TablaHashIndices::funcionesHash(int clave) const{
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
	
	for(int i=0; i<tabla[posicion].size_type; i++){
		if(tabla[posicion][i].clave==clave){
			resultado=tabla[posicion][i].valores;
			return true;
		}
	}
	return false;
}



















