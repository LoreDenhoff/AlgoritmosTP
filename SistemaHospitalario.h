#ifndef SISTEMAHOSPITALARIO_H
#define SISTEMAHOSPITALARIO_H
#include<vector>
#include<string>
#include "Hospital.h"
using namespace std;

class SistemaHospitalario{
	private:
		vector<vector<Hospital>>tablaHash;
		int capacidadTabla;
		int cantHospitales;
		int funcionHash(string codigo) const;
		
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
};
