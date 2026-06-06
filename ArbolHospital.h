#ifndef ARBOLHOSPITALES_H
#define ARBOLHOSPITALES_H
#include "NodoHospital.h"
#include <vector>
#include <string>
using namespace std;

class ArbolHospitales{
	private:
		NodoHospital* raiz;
		
		Hospital* insertarRec(NodoHospital*& nodo, const Hospital& hospital, bool& insertado);
		NodoHospital* buscarNodoRec(NodoHospital* nodo, string codigo) const;
		NodoHospital* eliminarRec(NodoHospital* nodo, string codigo, bool& eliminado);
		NodoHospital* extraerMinimo(NodoHospital* nodo, NodoHospital*& minimo);
		void inOrdenRec(NodoHospital* nodo, vector<Hospital>& hospitales) const;
		void destruirRec(NodoHospital* nodo);
		
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
