#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <string>
#include <vector>
#include "Especialidad.h"
#include "Fecha.h"
using namespace std;

classHospital{
	private:
		string hospitalId;
		string nombre;
		string ciudad;
		int capacidadCamas;
		int personalMedico;
		int presupuestoAnual;
		vector<Especialidad> especialidades;
		
	public:
		Hospital();
		Hospital(string hospitalId, string nombre, string ciudad, int capacidadCamas, int personalMedico, int presupuestoAnual;
		vector<Especialidad> especialidades);
		
		string getHospitalId() const;
		string getNombre() const;
		string getCiudad() const;
		int getCapacidadCamas() const;
		int getPersonalMedico() const;
		int getPresupuestoAnual() const;
		vector<Especialidad> getEspecialidades() const;
		
		bool tieneSobrecargo() const;
		int pacientesAtendidos (Fecha fechaDesde, Fecha fechaHasta) const;
		void ingresarPaciente(Paciente paciente);
		vector<Ingreso> ingresosEnRango(Fecha fechaDesde, Fecha fechaHasta) const;
};

#endif


