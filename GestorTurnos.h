#ifndef GESTORTURNOS_H
#define GESTORTURNOS_H
#include <vector>
#include <string>
#include "Fecha.h"
#include "TablaHashIndices.h"
#include "GestorPacientes.h"
#include "Turno.h"
using namespace std;

class GestorTurnos{
	private:
		vector<Turno> turnos;
		
		TablaHashIndices indicePorPaciente;
		TablaHashIndices indicePorMedico;
		Fecha convertirTextoAFecha(string textoFecha) const;
		void ordenarTurnosPorFecha(vector<Turno>& lista) const;
	
	public:
		GestorTurnos();
		
		void agregarTurno(Turno turno);
		vector<Turno> obtenerTodosLosTurnos() const;
		vector<Turno> buscarTurnosPorPacienteId(int pacienteId) const;
		vector<Turno> buscarTurnosPorMedicoId(int medicoId) const;
		vector<Turno> buscarTurnosPorDni(int dni, GestorPacientes& gestorPacientes) const;
		void cargarTurnosDesdeArchivo(string nombreArchivo);
		void mostrarTurnos(const vector<Turno>& lista) const;	
		void guardarTurnoEnArchivo(string nombreArchivo, const Turno& turno) const;
};
#endif

