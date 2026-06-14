#ifndef MENUDIAGNOSTICO_H
#define MENUDIAGNOSTICO_H
#include <string>
#include <vector>
#include "Diagnostico.h"
#include "ArbolDiagnostico.h"
using namespace std;

class MenuDiagnostico{
	private:
		ArbolDiagnostico& arbolDiagnostico;
		
		void mostrarMenu() const;
	
	public:
		MenuDiagnostico(ArbolDiagnostico& arbolDiagnostico);
		void ejecutar();
};
#endif







