#ifndef MENUPACIENTE_H
#define MENUPACIENTE_H
#include <string>
#include <vector>
#include "SistemaHospitalario.h"
#include "Paciente.h"
#include "Ingreso.h"
#include "Fecha.h"
#include "Auxiliares.h"
using namespace std;

class MenuPaciente{
	private:
		SistemaHospitalario& sistema;
		vector<Paciente>& pacientesRegistrados;
		
		void mostrarMenu() const;
		void ingresarPaciente();
		void listarPacientes();
		void contarPacientesEnRango();
		
	public:
		MenuPaciente(SistemaHospitalario& sistema, vector<Paciente>& pacientesEnRango);
		void ejecutar();		
};
#endif












