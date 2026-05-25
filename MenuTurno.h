#ifndef MENUTURNO_H
#define MENUTURNO_H
#include <string>
#include <vector>
#include "Turno.h"
#include "Fecha.h"
using namespace std;

class MenuTurno{
	private:
		vector<Turno>& turnosRegistrados;
		
		void mostrarMenu() const;
		int leerEntero(string mensaje) const;
		Fecha leerFecha(string mensaje) const;
		void registrarTurno();
		void listarTurnosMedico();
		
	public:
		MenuTurno(vector<Turno>& turnosRegistrados);
		void ejecutar();
};
#endif















