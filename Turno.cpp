#include <iostream>
#include <sstream>
#include "Turno.h"
using namespace std;
//inicializabamos asi?
Turno::Turno(){
	codigoHospital="";
	turnoId=0;
	pacienteId=0;
	medicoId=0;
	medicoId=0;
	fechaTurno=Fecha();
	especialidad="";
	duracion=0;
	medico=NULL;
}

Turno::Turno(string codigoHospital, int turnoId, int pacienteId, int medicoId, Fecha fechaTurno, string especialidad, int duracion){
    this->codigoHospital=codigoHospital;
	this->turnoId= turnoId;
	this->pacienteId=pacienteId;
	this->medicoId=medicoId;
    this->fechaTurno= fechaTurno;
    this->especialidad=especialidad;
    this->duracion= duracion;    
	this->medico=NULL;//xq null si tienen que tener un medico asignado

};

string Turno::getCodigoHospital() const{
	return codigoHospital;
}

int Turno::getTurnoId() const{
	return turnoId;
}

int Turno::getPacienteId() const{
	return pacienteId;
}

int Turno::getMedicoId() const{
	return medicoId;
}

Fecha Turno::getFechaTurno() const{
    return fechaTurno;
}

int Turno::getDuracion() const{
    return duracion;
}

string Turno::getEspecialidad() const{
	return especialidad;
}

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
   
}

//en medico hay que hacer que muestre solo nombre y apellido
void Turno::mostrarInformacion() const{
	cout<<"Turno ID: "<<turnoId<<endl;
	cout<<"Hospital: "<<codigoHospital<<endl;
	cout<<"Paciente ID: "<<pacienteId<<endl;
	cout<<"Medico ID: "<<medicoId<<endl;
	cout<<"Fecha: "<<turnoId<<endl
		<<fechaTurno.getDia()<< "/"
		<<fechaTurno.getMes()<< "/"
		<<fechaTurno.getAnio()<< "/"<<endl;
	cout<<"Especialidad: "<<especialidad<<endl;
	cout<<"Duracion: "<<duracion<<" minutos"<<endl;
	cout<<"Medico: "<<getMedico()<<endl;
}











