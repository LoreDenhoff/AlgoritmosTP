
#ifndef SISTEMAHOSPITALARIO_H
#define SISTEMAHOSPITALARIO_H
#include<vector>
#include<string>
#include "GestorHospitales.h"
#include "GestorEspecialidades.h"
#include "GestorPacientes.h"
#include "GestorTurnos.h"
#include "GestorPersonalMedico.h"
using namespace std;

class SistemaHospitalario{
	private:
		GestorHospitales gestorHospitales;
		GestorEspecialidades gestorEspecialidades;
		GestorPacientes gestorPacientes;
		GestorTurnos gestorTurnos;
		GestorPersonalMedico gestorPersonalMedico;
	public:
		SistemaHospitalario(int capacidadTabla);
		void inicializarSistema();
		GestorHospitales& getGestorHospitales();
		GestorEspecialidades& getGestorEspecialidades();
		GestorPacientes& getGestorPacientes();
		GestorTurnos& getGestorTurnos();
		GestorPersonalMedico& getGestorPersonalMedico();
		
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
		vector<Hospital> hospitalesConSobrecarga(int x, Fecha fechaDesde, Fecha fechaHasta);
};

#endif
