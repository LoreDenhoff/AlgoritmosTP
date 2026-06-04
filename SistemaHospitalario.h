#ifndef SISTEMAHOSPITALARIO_H
#define SISTEMAHOSPITALARIO_H
#include<vector>
#include<string>
#include "Hospital.h"
#include "TablaHashHospitales.h"
#include "Especialidad.h"
using namespace std;

class SistemaHospitalario{
	private:
		TablaHashHospitales tablaHospitales;
		Especialidad buscarEspecialidadPorId(int id, const vector<Especialidad>& especialidades) const;
		
	public:
		SistemaHospitalario(int capacidadTabla);
		void agregarHospital(Hospital hospital);
		void eliminarHospital(string codigo);
		Hospital* buscarHospital(string codigo);
		void mostrarHospital(string codigo) const;
		vector<Hospital>obtenerTodosLosHospitales() const;
		void ordenarPorCapacidadCamas();
		void ordenarPorPersonalMedico();
		void ordenarPorPresupuestoAnual();
		vector<Hospital> buscarPorEspecialidad(string especialidad);
		double factorCarga() const;		
		
		void cargarHospitalesDesdeArchivo(string nombreArchivo, const vector<Especialidad>& especialidades);
		void guardarHospitalEnArchivo(string nombreArchivo, const Hospital& hospital) const;
		vector<Especialidad> cargarEspecialidadesDesdeArchivo(string nombreArchivo);
};

#endif
