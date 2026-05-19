#include<string>
#include<sstream>
#include "Turno.h"

Turno::Turno(int turnoID, Fecha fechaTurno, int duracion){
    this->turnoID= turnoID;
    this->fechaTurno= fechaTurno;
    this->duracion= duracion;
    this->medico=NULL;

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
	if(medico==NULL){
		return "Sin medico asignado";
	}
   stringstream ss;
   ss<<medico->getNombre()
     <<" - "
     <<medico->getApellido()
     <<" - "
     <<medico->getEspecialidadId();
return ss.str();
   
   
};

