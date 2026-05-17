#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <string>
#include <vector>
#include "Especialidad.h"
#include "Fecha.h"
#include "Paciente.h"
#include "Ingreso.h"
using namespace std;

class Hospital{
	private:
		string hospitalId;
		string nombre;
		string ciudad;
		int capacidadCamas;
		int personalMedico;
		int presupuestoAnual;
		vector<Especialidad> especialidades;
		vector<Paciente> pacientesActivos;
		vector<Ingreso> ingresos;
		
	public:
		Hospital();
		Hospital(string hospitalId, string nombre, string ciudad, int capacidadCamas, int personalMedico, int presupuestoAnual, vector<Especialidad> especialidades);
		
		string getHospitalId() const;
		string getNombre() const;
		string getCiudad() const;
		int getCapacidadCamas() const;
		int getPersonalMedico() const;
		int getPresupuestoAnual() const;
		vector<Especialidad> getEspecialidades() const;
		vector<Paciente> getPacientesActivos() const;
		
		void mostrarInformacion() const;
		bool ofreceEspecialidad(string nombreEspecialidad) const;
		bool tieneSobrecarga() const;
		int cantPacientesActivos() const;//una funcion?
		int camasDisponibles() const;
		int pacientesAtendidosEnRango (Fecha fechaDesde, Fecha fechaHasta) const;
		void ingresarPaciente(Paciente paciente); //Ingreso un paciente o hago un ingreso?
		//vector<Ingreso> ingresosEnRango(Fecha fechaDesde, Fecha fechaHasta) const;
};

#endif


