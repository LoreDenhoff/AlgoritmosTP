#include "ArbolDiagnostico.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

ArbolDiagnostico::ArbolDiagnostico(){
	raiz=NULL;
}

ArbolDiagnostico::~ArbolDiagnostico(){
	destruirRec(raiz);
}

void ArbolDiagnostico::destruirRec(NodoArbol<Diagnostico>* nodo){
	if(nodo !=NULL){
		destruirRec(nodo->getIzquierda());
		destruirRec(nodo->getDerecha());
		delete nodo;
	}
}

bool ArbolDiagnostico::esMenor(const Diagnostico& nuevo, const Diagnostico& actual) const{
	if(nuevo.getDiagnosticoFrecuencia() < actual.getDiagnosticoFrecuencia()){
		return true;
	}
	if(nuevo.getDiagnosticoFrecuencia() > actual.getDiagnosticoFrecuencia()){
		return false;
	}
	return nuevo.getDiagnosticoId() < actual.getDiagnosticoId();
}

void ArbolDiagnostico::insertar(const Diagnostico& diagnostico){
	insertarRec(raiz, diagnostico);
}

void ArbolDiagnostico::insertarRec(NodoArbol<Diagnostico>*& nodo, const Diagnostico& diagnostico){
	if(nodo == NULL){
		nodo = new NodoArbol<Diagnostico>(diagnostico);
		return;
	}	
	if(esMenor(diagnostico, nodo->getDato())){
		NodoArbol<Diagnostico>* izquierda=nodo->getIzquierda();
		insertarRec(izquierda, diagnostico);
		nodo->setIzquierda(izquierda);
	}
	else{
		NodoArbol<Diagnostico>* derecha=nodo->getDerecha();
		insertarRec(derecha, diagnostico);
		nodo->setDerecha(derecha);
	}
}

void ArbolDiagnostico::listarEnOrden() const{
	if(raiz==NULL){
		cout<<"No hay diagnosticos cargados"<<endl;
		return;
	}
	inOrdenRec(raiz);
}

void ArbolDiagnostico::inOrdenRec(NodoArbol<Diagnostico>* nodo) const{
	if(nodo != NULL){
		inOrdenRec(nodo->getIzquierda());
		nodo->getDato().mostrarInformacion();
		cout<<"--------------------------"<<endl;
		inOrdenRec(nodo->getDerecha());
	}
}

NodoArbol<Diagnostico>* ArbolDiagnostico::buscarPorIdRec(NodoArbol<Diagnostico>* nodo, int diagnosticoId) const{
	if(nodo==NULL){
		return NULL;
	}
	if(nodo->getDato().getDiagnosticoId()==diagnosticoId){
		return nodo;
	}
	NodoArbol<Diagnostico>* encontradoIzquierda=buscarPorIdRec(nodo->getIzquierda(), diagnosticoId);
	if(encontradoIzquierda != NULL){
		return encontradoIzquierda;
	}
	return buscarPorIdRec(nodo->getDerecha(), diagnosticoId);
}

NodoArbol<Diagnostico>* ArbolDiagnostico::buscarPorNombreRec(NodoArbol<Diagnostico>* nodo, string nombre) const{
	if(nodo==NULL){
		return NULL;
	}
	if(nodo->getDato().getDiagnosticoNombre()==nombre){
		return nodo;
	}
	NodoArbol<Diagnostico>* encontradoIzquierda=buscarPorNombreRec(nodo->getIzquierda(), nombre);
	if(encontradoIzquierda !=NULL){
		return encontradoIzquierda;
	}
	return buscarPorNombreRec(nodo->getDerecha(), nombre);
}

bool ArbolDiagnostico::incrementarFrecuenciaPorId(int diagnosticoId){
	NodoArbol<Diagnostico>* nodo=buscarPorIdRec(raiz, diagnosticoId);
	if(nodo==NULL){
		return false;
	}
	Diagnostico diagnostico=nodo->getDato();
	bool eliminado=false;
	raiz=eliminarRec(raiz, diagnosticoId, eliminado);
	
	if(eliminado){
		diagnostico.incrementarFrecuencia();
		insertar(diagnostico);
		return true;
	}
	return false;
}

bool ArbolDiagnostico::incrementarFrecuenciaPorNombre(string nombre){
	NodoArbol<Diagnostico>* nodo=buscarPorNombreRec(raiz, nombre);
	if(nodo==NULL){
		return false;
	}
	int diagnosticoId=nodo->getDato().getDiagnosticoId();
	return incrementarFrecuenciaPorId(diagnosticoId);
}

bool ArbolDiagnostico::eliminar(int diagnosticoId){
	bool eliminado=false;
	raiz=eliminarRec(raiz, diagnosticoId, eliminado);
	return eliminado;
}

NodoArbol<Diagnostico>* ArbolDiagnostico::eliminarRec(NodoArbol<Diagnostico>* nodo, int diagnosticoId, bool& eliminado){
	if(nodo==NULL){
		return NULL;
	}	
	if(nodo->getDato().getDiagnosticoId()==diagnosticoId){
		eliminado=true;
		if(nodo->getIzquierda()==NULL){
			NodoArbol<Diagnostico>* derecha=nodo->getDerecha();
			delete nodo;
			return derecha;
		}
		if(nodo->getDerecha()==NULL){
			NodoArbol<Diagnostico>* izquierda=nodo->getIzquierda();
			delete nodo;
			return izquierda;
	}
	NodoArbol<Diagnostico>* subArbolIzquierdo=nodo->getIzquierda();
	NodoArbol<Diagnostico>* subArbolDerecho=nodo->getDerecha();
	NodoArbol<Diagnostico>* sucesor=NULL;
	subArbolDerecho=extraerMinimo(subArbolDerecho, sucesor);
	sucesor->setIzquierda(subArbolIzquierdo);
	sucesor->setDerecha(subArbolDerecho);
	
	delete nodo; 
	return sucesor;
 }
 nodo->setIzquierda(eliminarRec(nodo->getIzquierda(), diagnosticoId, eliminado));
 if(eliminado){
 	return nodo;
 }
 nodo->setDerecha(eliminarRec(nodo->getDerecha(), diagnosticoId, eliminado));
 	return nodo;
 }
 
 NodoArbol<Diagnostico>* ArbolDiagnostico::extraerMinimo(NodoArbol<Diagnostico>* nodo, NodoArbol<Diagnostico>*& minimo){
 	if(nodo->getIzquierda()==NULL){
 		minimo=nodo;
 		return nodo->getDerecha();
	}
	nodo->setIzquierda(extraerMinimo(nodo->getIzquierda(), minimo));
	return nodo; 
 }
 
Diagnostico ArbolDiagnostico::obtenerMasFrecuente() const{
	Diagnostico masFrecuente;
	bool encontrado=false;
	masFrecuenteRec(raiz, masFrecuente, encontrado);
	return masFrecuente;
}
 
 void ArbolDiagnostico::masFrecuenteRec(NodoArbol<Diagnostico>* nodo, Diagnostico& masFrecuente, bool& encontrado) const{
 	if(nodo != NULL){
 		masFrecuenteRec(nodo->getIzquierda(), masFrecuente, encontrado);
 		if(!encontrado || nodo->getDato().getDiagnosticoFrecuencia() > masFrecuente.getDiagnosticoFrecuencia()){
 			masFrecuente=nodo->getDato();
 			encontrado=true;
		}
		masFrecuenteRec(nodo->getDerecha(), masFrecuente, encontrado); 
	}
 }
 
 

int ArbolDiagnostico::calcularAltura() const{
	return alturaRec(raiz);
}

int ArbolDiagnostico::alturaRec(NodoArbol<Diagnostico>* nodo) const{
	if(nodo==NULL){
		return 0;
	}
	int alturaIzquierda=alturaRec(nodo->getIzquierda());
	int alturaDerecha=alturaRec(nodo->getDerecha());
	if(alturaIzquierda > alturaDerecha){
		return alturaIzquierda +1;
	}
	return alturaDerecha +1;
}

bool ArbolDiagnostico::estaDesbalanceado() const{
	return estaDesbalanceadoRec(raiz);
}

bool ArbolDiagnostico::estaDesbalanceadoRec(NodoArbol<Diagnostico>* nodo) const{
	if(nodo==NULL){
		return false;
	}
	int alturaIzquierda=alturaRec(nodo->getIzquierda());
	int alturaDerecha=alturaRec(nodo->getDerecha());
	int diferencia=alturaIzquierda - alturaDerecha;
	
	if(diferencia < 0){
		diferencia=diferencia*-1;
	}
	if(diferencia > 2){
		return true;
	}
	return estaDesbalanceadoRec(nodo->getIzquierda()) || estaDesbalanceadoRec(nodo->getDerecha());
}

bool ArbolDiagnostico::estaVacio() const{
	return raiz==NULL;
}

void ArbolDiagnostico::cargarDesdeArchivo(string nombreArchivo){
	ifstream archivo(nombreArchivo.c_str());
	
	if(!archivo.is_open()){
		cout<<"No se pudo abrir el archivo: "<<nombreArchivo<<endl;
		return;
	}
	string linea;
	getline(archivo, linea);
	
	while(getline(archivo, linea)){
		stringstream ss(linea);
		string idTexto;
		string nombre;
		string frecuenciaTexto;
		
		getline(ss, idTexto, ';');
		getline(ss, nombre, ';');
		getline(ss, frecuenciaTexto, ';');
		
		int diagnosticoId=atoi(idTexto.c_str());
		int frecuencia=atoi(frecuenciaTexto.c_str());
		
		Diagnostico diagnostico(diagnosticoId, nombre, frecuencia);
		insertar(diagnostico);
	}
	archivo.close();
}

