#include "Hospital.h"

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
	cout<< "Camas disponibles: " <<camasDisponibles<< endl;
}

bool Hospital::ofreceEspecialidad(string nombreEspecialidad) const{
	for(int i=0; i<especialidades.size();i++){
		if(especialidad[i].getNombre()==nombreEspecialidad){
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
	for(int i=0; i<ingresos.size(); i++){
		Fecha fechaIngreso=ingresos[i].getFechaIngreso();
		if(fechaIngreso.esMayorOIgual(fechaDesde) && fechaIngreso.esMenosOIgual(fechaHasta)){
			contador++
		}
	}
	return contador;
}

void Hospital::ingresarPaciente(Paciente paciente){
	if(camasDisponibles>0){ 
		pacientesActivos.push_back(pacientes);
	} else{
		cout<<"No hay camas disponibles"<< endl;
	}

}


