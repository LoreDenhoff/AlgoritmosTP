#ifndef MENUDERIVACION_H
#define MENUDERIVACION_H
#include "SistemaHospitalario.h"
#include <string>
using namespace std;

class MenuDerivacion{
	private:
	SistemaHospitalario& sistema;

	void mostrarMenu() const;
	void calcularRutaConMenorTiempo();
	void mostrarDerivaciones();
		//ver ambulancias
		
	public:
		MenuDerivacion(SistemaHospitalario& sistema);
		void ejecutar();		
};
#endif
