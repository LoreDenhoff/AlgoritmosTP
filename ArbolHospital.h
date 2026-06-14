#ifndef ARBOLHOSPITALES_H
#define ARBOLHOSPITALES_H
#include "NodoArbol.h"
#include "Hospital.h"
#include <vector>
#include <string>
using namespace std;

class ArbolHospitales{
	private:
		NodoArbol<Hospital>* raiz;
		
		Hospital* insertarRec(NodoArbol<Hospital>*& nodo, const Hospital& hospital, bool& insertado);
		NodoArbol<Hospital>* buscarNodoRec(NodoArbol<Hospital>* nodo, string codigo) const;
		NodoArbol<Hospital>* eliminarRec(NodoArbol<Hospital>* nodo, string codigo, bool& eliminado);
		NodoArbol<Hospital>* extraerMinimo(NodoArbol<Hospital>* nodo, NodoArbol<Hospital>*& minimo);
		void inOrdenRec(NodoArbol<Hospital>* nodo, vector<Hospital>& hospitales) const;
		void destruirRec(NodoArbol<Hospital>* nodo);
		
	public:
		ArbolHospitales();
		~ArbolHospitales();
		
		Hospital* insertar(const Hospital& hospital, bool& insertado);
		Hospital* buscar(string codigo) const;
		bool eliminar(string codigo);
		vector<Hospital> obtenerTodos() const;
		bool estaVacio() const;
};
#endif
