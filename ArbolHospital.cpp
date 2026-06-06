#include "ArbolHospital.h"

ArbolHospitales::ArbolHospitales(){
	raiz=NULL;
}

ArbolHospitales::~ArbolHospitales(){
	destruirRec(raiz);
}

void ArbolHospitales::destruirRec(NodoHospital* nodo){
	if(nodo != NULL){
		destruirRec(nodo->getIzquierda());
		destruirRec(nodo->getDerecha());
		delete nodo;
	}
}

Hospital* ArbolHospitales::insertar(const Hospital& hospital, bool& insertado){
	insertado=false;
	return insertarRec(raiz, hospital, insertado);
}

Hospital* ArbolHospitales::insertarRec(NodoHospital*& nodo, const Hospital& hospital, bool& insertado){
	if(nodo==NULL){
		nodo=new NodoHospital(hospital);
		insertado=true;
		return &(nodo->getHospital());
	}

	string codigoNuevo=hospital.getHospitalId();
	string codigoActual=nodo->getHospital().getHospitalId();
	
	if(codigoNuevo<codigoActual){
		NodoHospital* izquierda=nodo->getIzquierda();
		Hospital* resultado=insertarRec(izquierda, hospital, insertado);
		nodo->setIzquierda(izquierda);
		return resultado;
	}
	if(codigoNuevo>codigoActual){
		NodoHospital* derecha=nodo->getDerecha();
		Hospital* resultado=insertarRec(derecha, hospital, insertado);
		nodo->setDerecha(derecha);
		return resultado;
	}
	insertado=false;
	return &(nodo->getHospital());
}

Hospital* ArbolHospitales::buscar(string codigo) const{
	NodoHospital* nodo=buscarNodoRec(raiz, codigo);
	if(nodo==NULL){
		return NULL;
	}
	return &(nodo->getHospital());
}

NodoHospital* ArbolHospitales::buscarNodoRec(NodoHospital* nodo, string codigo) const{
	if(nodo==NULL){
		return NULL;
	}
	string codigoActual=nodo->getHospital().getHospitalId();
	if(codigo==codigoActual){
		return nodo;
	}
	if(codigo<codigoActual){
		return buscarNodoRec(nodo->getIzquierda(), codigo);
	}
	return buscarNodoRec(nodo->getDerecha(), codigo);
}

bool ArbolHospitales::eliminar(string codigo){
	bool eliminado=false;
	raiz=eliminarRec(raiz, codigo, eliminado);
	return eliminado;
}

NodoHospital* ArbolHospitales::eliminarRec(NodoHospital* nodo, string codigo, bool& eliminado){
	if(nodo==NULL){
		return NULL;
	}
	string codigoActual=nodo->getHospital().getHospitalId();
	
	if(codigo<codigoActual){
		nodo->setIzquierda(eliminarRec(nodo->getIzquierda(), codigo, eliminado));
		return nodo;
	}
	if(codigo>codigoActual){
		nodo->setDerecha(eliminarRec(nodo->getDerecha(), codigo, eliminado));
		return nodo;
	}
	eliminado=true;
	
	if(nodo->getIzquierda()==NULL){
		NodoHospital* derecha=nodo->getDerecha();
		delete nodo;
		return derecha;
	}
	if(nodo->getDerecha()==NULL){
		NodoHospital* izquierda=nodo->getIzquierda();
		delete nodo;
		return izquierda;	
} 

NodoHospital* subArbolIzquierdo=nodo->getIzquierda();
NodoHospital* subArbolDerecho=nodo->getDerecha();

NodoHospital* sucesor=NULL;
subArbolDerecho=extraerMinimo(subArbolDerecho, sucesor);

sucesor->setIzquierda(subArbolIzquierdo);
sucesor->setDerecha(subArbolDerecho);

delete nodo;
return sucesor;
}
	
NodoHospital* ArbolHospitales::extraerMinimo(NodoHospital* nodo, NodoHospital*& minimo){
	if(nodo->getIzquierda()==NULL){
		minimo=nodo;
		return nodo->getDerecha();
	}
	
	nodo->setIzquierda(extraerMinimo(nodo->getIzquierda(), minimo));
	return nodo;
}

vector<Hospital> ArbolHospitales::obtenerTodos() const{
	vector<Hospital> hospitales;
	inOrdenRec(raiz, hospitales);
	return hospitales;
}

void ArbolHospitales::inOrdenRec(NodoHospital* nodo, vector<Hospital>& hospitales) const{
	if(nodo != NULL){
		inOrdenRec(nodo->getIzquierda(), hospitales);
		hospitales.push_back(nodo->getHospital());
		inOrdenRec(nodo->getDerecha(), hospitales);
	}
}

bool ArbolHospitales::estaVacio() const{
return raiz==NULL;
}


















