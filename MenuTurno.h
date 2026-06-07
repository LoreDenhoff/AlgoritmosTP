#ifndef MENUTURNO_H
#define MENUTURNO_H
#include <string>
#include <vector>
#include "GestorTurnos.h"
#include "GestorPacientes.h"
#include "GestorHospitales.h"
#include "Fecha.h"
using namespace std;

class MenuTurno{
	private:
		GestorTurnos& gestorTurnos;
		GestorPacientes& gestorPacientes;
		GestorHospitales& gestorHospitales;
		
		void mostrarMenu() const;
		int leerEntero(string mensaje) const;
		string leerTexto(string mensaje) const;
		Fecha leerFecha(string mensaje) const;
		void mostrarHospitalesDisponibles() const;
		string leerCodigoHospitalValido() const;
		void registrarTurno();
		void listarTurnosMedico();
		void listarTurnosPacientePorDni();
		
	public:
		MenuTurno(GestorTurnos& gestorTurnos, GestorPacientes& gestorPacientes, GestorHospitales& gestorHospitales);
		void ejecutar();
};
#endif















