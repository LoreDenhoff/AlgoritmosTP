#ifndef GESTORHOSPITALES_H
#define GESTORHOSPITALES_H
#include <vector>
#include <string>
#include "Hospital.h"
#include "Especialidad.h"
#include "TablaHashHospitales.h"
#include "ArbolHospital.h"
#include "Fecha.h"
using namespace std;

class GestorHospitales{
	private:
		ArbolHospitales arbolHospitales;
		TablaHashHospitales tablaHospitales;

		Hospital* buscarHospitalDisponibleParaReasignar(string codigoOrigen, int cantidadPacientes);
		
	public:
		GestorHospitales(int capacidadTabla);
		
		void agregarHospital(Hospital hospital);
		bool eliminarHospital(string codigo, string& codigoHospitalDestino);
		Hospital* buscarHospital(string codigo);
		void mostrarHospital(string codigo) const;
		vector<Hospital> obtenerTodosLosHospitales() const;
		void ordenarPorCapacidadCamas();
		void ordenarPorPersonalMedico();
		void ordenarPorPresupuestoAnual();
		vector<Hospital> buscarPorEspecialidad(string especialidad);
		double factorCarga() const;
		void actualizarArchivo(string nombreArchivo) const;
		void cargarHospitalesDesdeArchivo(string nombreArchivo, const vector<Especialidad> & especialidades);
		void guardarHospitalEnArchivo(string nombreArchivo, const Hospital& hospital)const; 
		vector<Hospital> hospitalesConSobrecarga(int x, Fecha fechaDesde, Fecha fechaHasta);		
};
#endif
