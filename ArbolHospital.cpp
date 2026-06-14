#include "ArbolHospital.h"

ArbolHospitales::ArbolHospitales(){
	raiz=NULL;
}

ArbolHospitales::~ArbolHospitales(){
	destruirRec(raiz);
}

void ArbolHospitales::destruirRec(NodoArbol<Hospital>* nodo){
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

Hospital* ArbolHospitales::insertarRec(NodoArbol<Hospital>*& nodo, const Hospital& hospital, bool& insertado){
	if(nodo==NULL){
		nodo=new NodoArbol<Hospital>(hospital);
		insertado=true;
		return &(nodo->getDato());
	}

	string codigoNuevo=hospital.getHospitalId();
	string codigoActual=nodo->getDato().getHospitalId();
	
	if(codigoNuevo<codigoActual){
		NodoArbol<Hospital>* izquierda=nodo->getIzquierda();
		Hospital* resultado=insertarRec(izquierda, hospital, insertado);
		nodo->setIzquierda(izquierda);
		return resultado;
	}
	if(codigoNuevo>codigoActual){
		NodoArbol<Hospital>* derecha=nodo->getDerecha();
		Hospital* resultado=insertarRec(derecha, hospital, insertado);
		nodo->setDerecha(derecha);
		return resultado;
	}
	insertado=false;
	return &(nodo->getDato());
}

Hospital* ArbolHospitales::buscar(string codigo) const{
	NodoArbol<Hospital>* nodo=buscarNodoRec(raiz, codigo);
	if(nodo==NULL){
		return NULL;
	}
	return &(nodo->getDato());
}

NodoArbol<Hospital>* ArbolHospitales::buscarNodoRec(NodoArbol<Hospital>* nodo, string codigo) const{
	if(nodo==NULL){
		return NULL;
	}
	string codigoActual=nodo->getDato().getHospitalId();
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

NodoArbol<Hospital>* ArbolHospitales::eliminarRec(NodoArbol<Hospital>* nodo, string codigo, bool& eliminado){
	if(nodo==NULL){
		return NULL;
	}
	string codigoActual=nodo->getDato().getHospitalId();
	
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
		NodoArbol<Hospital>* derecha=nodo->getDerecha();
		delete nodo;
		return derecha;
	}
	if(nodo->getDerecha()==NULL){
		NodoArbol<Hospital>* izquierda=nodo->getIzquierda();
		delete nodo;
		return izquierda;	
} 

NodoArbol<Hospital>* subArbolIzquierdo=nodo->getIzquierda();
NodoArbol<Hospital>* subArbolDerecho=nodo->getDerecha();

NodoArbol<Hospital>* sucesor=NULL;
subArbolDerecho=extraerMinimo(subArbolDerecho, sucesor);

sucesor->setIzquierda(subArbolIzquierdo);
sucesor->setDerecha(subArbolDerecho);

delete nodo;
return sucesor;
}
	
NodoArbol<Hospital>* ArbolHospitales::extraerMinimo(NodoArbol<Hospital>* nodo, NodoArbol<Hospital>*& minimo){
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

void ArbolHospitales::inOrdenRec(NodoArbol<Hospital>* nodo, vector<Hospital>& hospitales) const{
	if(nodo != NULL){
		inOrdenRec(nodo->getIzquierda(), hospitales);
		hospitales.push_back(nodo->getDato());
		inOrdenRec(nodo->getDerecha(), hospitales);
	}
}

bool ArbolHospitales::estaVacio() const{
return raiz==NULL;
}


















