#ifndef MENUHOSPITAL_H
#define MENUHOSPITAL_H
#include <string>
#include <vector>
#include "SistemaHospitalario.h"
#include "Especialidad.h"
#include "Hospital.h"
using namespace std;

class MenuHospital{
	private:
		SistemaHospitalario& sistema;
		void mostrarMenu() const;
		int leerEntero(string mensaje) const;
		string leerTexto(string mensaje) const;
		vector<Especialidad> cargarEspecialidadHospital() const;
		
		void registrarHospital();
		void listarHospitales();
		void buscarHospital();
		void eliminarHospital();
		void buscarPorEspecialidad();
		void mostrarFactorCarga();
		
	public:
		MenuHospital(SistemaHospitalario& sistema);
		void ejecutar();		
};
#endif
