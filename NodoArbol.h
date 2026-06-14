#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <cstddef>

template <typename T>
class NodoArbol{
	private:
		T dato;
		NodoArbol<T>* izquierda;
		NodoArbol<T>* derecha;
		
	public:
		NodoArbol(const T& dato);
		
		T& getDato();
		const T& getDato() const;
		
		NodoArbol<T>* getIzquierda() const;
		NodoArbol<T>* getDerecha() const;
		void setIzquierda(NodoArbol<T>* izquierda);
		void setDerecha(NodoArbol<T>* derecha);
};

template <typename T>
NodoArbol<T>::NodoArbol(const T& dato){
	this->dato= dato;
	this->izquierda=NULL;
	this->derecha=NULL;
}

template <typename T>
T& NodoArbol<T>::getDato(){
	return dato;
}

template <typename T>
const T& NodoArbol<T>::getDato() const{
	return dato;
}

template <typename T>
NodoArbol<T>* NodoArbol<T>::getIzquierda() const{
	return izquierda;
}

template <typename T>
NodoArbol<T>* NodoArbol<T>::getDerecha() const{
	return derecha;
}

template <typename T>
void NodoArbol<T>::setIzquierda(NodoArbol<T>* izquierda){
	this->izquierda=izquierda;
}

template <typename T>
void NodoArbol<T>::setDerecha(NodoArbol<T>* derecha){
	this->derecha=derecha;
}

#endif



















