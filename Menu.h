#ifndef MENU_H
#define MENU_H
#include "SistemaHospitalario.h"
#include "Especialidad.h"
#include "Fecha.h"
#include <vector>
#include <string>
using namespace std;

class Menu{
	private:
		SistemaHospitalario sistema;
		vector<Especialidad> especialidades;
		
		void mostrarMenu() const;		
		int leerEntero(string mensaje) const;
		float leerFloat(string mensaje) const;
		string leerTexto(string mensaje) const;
		Fecha leerFecha(string mensaje) const;

		vector<Especialidad> cargarEspecialidadHospital() const;
		
		//hospitales
		void listarHospitales();
		void buscarHospital();
		void registrarHospital();
		void eliminarHospital();
		void buscarPorEspecialidad();
		//pacientes
		void ingresarPaciente();
		void contarPacientesEnRango();
		
		void mostrarFactorCarga();
		
	public:
		Menu();
		void ejecutar();
};
#endif
