#ifndef MENUHOSPITAL_H
#define MENUHOSPITAL_H
#include <string>
#include <vector>
#include "SistemaHospitalario.h"
#include "Especialidad.h"
#include "Hospital.h"
#include "Auxiliares.h"
using namespace std;

class MenuHospital{
	private:
		SistemaHospitalario& sistema;
		void mostrarMenu() const;
		vector<Especialidad> cargarEspecialidadHospital() const;
		
		void registrarHospital();
		void listarHospitalesOrdenados();
		void buscarHospital();
		void eliminarHospital();
		void buscarPorEspecialidad();
		void mostrarFactorCarga();
		
	public:
		MenuHospital(SistemaHospitalario& sistema);
		void ejecutar();		
};
#endif
