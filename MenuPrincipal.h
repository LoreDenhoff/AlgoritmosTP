#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include <vector>
#include "SistemaHospitalario.h"
#include "Paciente.h"
#include "Turno.h"
#include "Diagnostico.h"
#include "Auxiliares.h"
using namespace std;

class MenuPrincipal{
	private:
		SistemaHospitalario sistema;
		
		vector<Paciente> pacientesRegistrados;
		vector<Turno> turnosRegistrados;
			
		void mostrarMenuPrincipal() const;

	public:
		MenuPrincipal();
		void ejecutar();
};
#endif
