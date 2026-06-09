#ifndef MENUTURNO_H
#define MENUTURNO_H
#include <string>
#include <vector>
#include "GestorTurnos.h"
#include "GestorPacientes.h"
#include "GestorTurnos.h"
#include "GestorPacientes.h"
#include "GestorHospitales.h"
#include "GestorEspecialidades.h"
#include "GestorPersonalMedico.h"
#include "Especialidad.h"
#include "Fecha.h"
#include "Auxiliares.h"
using namespace std;

class MenuTurno{
	private:
		GestorTurnos& gestorTurnos;
		GestorPacientes& gestorPacientes;
		GestorHospitales& gestorHospitales;
		GestorPersonalMedico& gestorPersonalMedico;
		GestorEspecialidades& gestorEspecialidades;
		
		void mostrarMenu() const;
		int leerIdValido(string mensaje, string tipo) const;
		void mostrarHospitalesDisponibles() const;
		string leerCodigoHospitalValido() const;
		void mostrarEspecialidadesDisponibles() const;
		int leerEspecialidadValida() const;
		string obtenerNombreEspecialidad(int especialidad) const;
		void mostrarMedicosPorEspecialidad(int especialidadId) const;
		int leerMedicoPorEspecialidad(int especialidadId) const;
		void registrarTurno();
		void listarTurnosMedico();
		void listarTurnosPacientePorDni();
		
	public:
		MenuTurno(
		GestorTurnos& gestorTurnos, 
		GestorPacientes& gestorPacientes, 
		GestorHospitales& gestorHospitales,
		GestorPersonalMedico& gestorPersonalMedico,
		GestorEspecialidades& gestorEspecialidades
		);
		void ejecutar();
};
#endif















