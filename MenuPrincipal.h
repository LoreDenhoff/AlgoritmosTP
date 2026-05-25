#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include <vector>
#include "SistemaHospitalario.h"
#include "Paciente.h"
#include "Turno.h"
#include "Diagnostico.h"
using namespace std;

class MenuPrincipal{
	private:
		SistemaHospitalario sistema;
		
		vector<Paciente> pacientesRegistrados;
		vector<Turno> turnosRegistrados;
		vector<Diagnostico> diagnosticosRegistrados;
		
		void mostrarMenuPrincipal() const;
		int leerOpcion() const;
		
	public:
		MenuPrincipal();
		void ejecutar();
};
#endif
