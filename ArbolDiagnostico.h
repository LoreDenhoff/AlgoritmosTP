#ifndef ARBOLDIAGNOSTICO_H
#define ARBOLDIAGNOSTICO_H
#include "NodoArbol.h"
#include "Diagnostico.h"
#include <vector>
#include <string>
using namespace std;

class ArbolDiagnostico{
	private:
		NodoArbol<Diagnostico>* raiz;
		
		bool esMenor(const Diagnostico& nuevo, const Diagnostico& actual) const;
		
		void insertarRec(NodoArbol<Diagnostico>*& nodo, const Diagnostico& diagnostico);
		void inOrdenRec(NodoArbol<Diagnostico>* nodo) const;
		void destruirRec(NodoArbol<Diagnostico>* nodo);
		
		NodoArbol<Diagnostico>* buscarPorIdRec(NodoArbol<Diagnostico>* nodo, int diagnosticoId) const;
		NodoArbol<Diagnostico>* buscarPorNombreRec(NodoArbol<Diagnostico>* nodo, string nombre) const;
		NodoArbol<Diagnostico>* eliminarRec(NodoArbol<Diagnostico>* nodo, int diagnosticoId, bool& eliminado);
		NodoArbol<Diagnostico>* extraerMinimo(NodoArbol<Diagnostico>* nodo, NodoArbol<Diagnostico>*& minimo);
		
		void masFrecuenteRec(NodoArbol<Diagnostico>* nodo, Diagnostico& masFrecuente, bool& encontrado) const;
		int alturaRec(NodoArbol<Diagnostico>* nodo) const;
		bool estaDesbalanceadoRec(NodoArbol<Diagnostico>* nodo) const;
		
		void cargarDesdeArchivoRec(string nombreArchivo);
	
	public:
		ArbolDiagnostico();
		~ArbolDiagnostico();
		
		void insertar(const Diagnostico& diagnostico);
		bool incrementarFrecuenciaPorId(int diagnosticoId);
		bool incrementarFrecuenciaPorNombre(string nombre);
		void listarEnOrden() const;
		bool eliminar(int diagnosticoId);
		Diagnostico obtenerMasFrecuente() const;
		int calcularAltura() const;
		bool estaDesbalanceado() const;
		bool estaVacio() const;
		void cargarDesdeArchivo(string nombreArchivo);		
};
#endif
