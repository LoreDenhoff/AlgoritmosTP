#include "Hospital.h"
#include<iostream>
using namespace std;

Hospital::Hospital(){
	hospitalId="";
	nombre="";
	ciudad="";
	capacidadCamas=0;
	personalMedico=0;
	presupuestoAnual=0;
}

Hospital::Hospital(string hospitalId, string nombre, string ciudad, int capacidadCamas,	int personalMedico, int presupuestoAnual, vector<Especialidad> especialidades){
	this->hospitalId= hospitalId;
	this->nombre= nombre;
	this->ciudad= ciudad;
	this->capacidadCamas= capacidadCamas;
	this->personalMedico= personalMedico;
	this->presupuestoAnual= presupuestoAnual;
	this->especialidades= especialidades;
}

string Hospital::getHospitalId() const {return hospitalId;}
string Hospital::getNombre() const {return nombre;}
string Hospital::getCiudad() const {return ciudad;}
int Hospital::getCapacidadCamas() const {return capacidadCamas;}
int Hospital::getPersonalMedico() const {return personalMedico;}
int Hospital::getPresupuestoAnual() const {return presupuestoAnual;}
vector<Especialidad> Hospital::getEspecialidades() const {return especialidades;}
vector<Paciente> Hospital::getPacientesActivos() const {return pacientesActivos;}

void Hospital::mostrarInformacion() const{
	cout<< "Código: "<<hospitalId<< endl;
	cout<< "Nombre: " <<nombre<< endl;
	cout<< "Ciudad: " <<ciudad<< endl;
	cout<< "Capacidad de camas: " <<capacidadCamas<< endl;
	cout<< "Personal Médico: " <<personalMedico<< endl;
	cout<< "Presupuesto anual: " <<presupuestoAnual<< endl;
	cout<< "Pacientes activos: " <<pacientesActivos.size()<< endl;
	cout<< "Camas disponibles: " <<camasDisponibles()<< endl;
}

bool Hospital::ofreceEspecialidad(string nombreEspecialidad) const{
	for(size_t i=0; i<especialidades.size();i++){
		if(especialidades[i].getEspecialidadNombre()==nombreEspecialidad){
			return true;
		}
	}
	return false;
}

bool Hospital::tieneSobrecarga() const{
	if(capacidadCamas==0){
		return false;
	}
	double ocupacion=pacientesActivos.size()*100.0/capacidadCamas;
	return ocupacion>90.0;
}

int Hospital::camasDisponibles() const{
	return capacidadCamas-pacientesActivos.size();
}

int Hospital::pacientesAtendidosEnRango(Fecha fechaDesde, Fecha fechaHasta) const{
	int cont=0;
	for(size_t i=0; i<ingreso.size(); i++){
		Fecha fechaIngreso=ingreso[i].getFechaIngresoDerivacion();
		if(fechaIngreso.mayorIgualQue(fechaDesde) && fechaIngreso.menorIgualQue(fechaHasta)){
			cont++;
		}
	}
	return cont;
}

void Hospital::ingresarPaciente(Paciente paciente, Ingreso nuevoIngreso){
	if(camasDisponibles()>0){ 
		pacientesActivos.push_back(paciente);
		ingreso.push_back(nuevoIngreso);
	} else{
		cout<<"No hay camas disponibles"<< endl;
	}

}

int Hospital::cantPacientesActivos() const{
	return pacientesActivos.size();
}


