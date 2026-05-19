#include<string>
#include "Turno.h"

Turno::Turno(int turnoID, Fecha fechaTurno, int duracion){
    this->turnoID= turnoID;
    this->fechaTurno= fechaTurno;
    this->duracion= duracion;
    this->medico=nullptr;

};
Fecha Turno::getFechaTurno() const{
    return fechaTurno;
};
int Turno::getDuracion() const{
    return duracion;
};
void Turno::asignarMedico(PersonalMedico* unMedico){
    medico= unMedico;
};
string Turno::getMedico() const{
	if(medico==nullptr){
		return "Sin medico asignado";
	}
    return medico->getNombre() + " " 
    + medico->getApellido() + " - " 
    + to_string(medico->getEspecialidadID());
};

