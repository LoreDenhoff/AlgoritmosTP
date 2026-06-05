#ifndef TURNO_H
#define TURNO_H
#include<string>
#include "Fecha.h"
#include "PersonalMedico.h"
using namespace std;

class Turno{
    private:
    	string codigoHospital;
        int turnoId;
        int pacienteId;
        int medicoId;
        Fecha fechaTurno;
        string especialidad;
        int duracion;

        PersonalMedico* medico;

    public:
        Turno(
		string codigoHospital;
        int turnoId;
        int pacienteId;
        int medicoId;
        Fecha fechaTurno;
        string especialidad;
        int duracion;
		);
		
	string getCodigoHospital() const;
        int getTurnoId() const;
        int getPacienteId() const;
        int getMedicoId() const;
        Fecha getFechaTurno() const;
        string getEspecialidad() const;
        int getDuracion() const;  
		
		void asignarMedico(PersonalMedico* unMedico);
		string getMedico() const;
		void mostrarInformacion() const;     
};
#endif


