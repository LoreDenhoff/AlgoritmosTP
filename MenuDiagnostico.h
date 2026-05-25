#ifndef MENUDIAGNOSTICO_H
#define MENUDIAGNOSTICO_H
#include <string>
#include <vector>
#include "Diagnostico.h"
using namespace std;

class MenuDiagnostico{
	private:
		vector<Diagnostico>& diagnosticosRegistrados;
		
		void mostrarMenu() const;
	
	public:
		MenuDiagnostico(vector<Diagnostico>& diagnosticosRegistrados);
		void ejecutar();
};
#endif







