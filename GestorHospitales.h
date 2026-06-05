#ifndef GESTORHOSPITALES_H
#define GESTORHOSPITALES_H
#include <vector>
#include <string>
#include "Hospital.h"
#include "Especialidad.h"
#include "TablaHashHospitales.h"
#include "ArbolHospitales.h"
using namespace std;

class GestorHospitales{
	private:
		ArbolHospitales arbolHospitales;
		TablaHashHospitales tablaHospitales;
		
	public:
		GestorHospitales(int capacidadTabla);
		
		void agregarHospital(Hospital hospital);
		void eliminarHospital(string codigo);
		Hospital* buscarHospital(string codigo);
		void mostrarHospital(string codigo) const;
		vector<Hospital> obtenerTodosLosHospitales() const;
		void ordenarPorCapacidadCamas();
		void ordenarPorPersonalMedico();
		void ordenarPorPresupuestoAnual();
		vector<Hospital> buscarPorEspecialidad(string especialidad);
		double factorCarga() const;
		void cargarHospitalesDesdeArchivo(string nombreArchivo, const vector<Especialidad> & especialidades);
		void guardarHospitalEnArchivo(string nombreArchivo, const Hospital& hospital)const; 		
};
#endif
