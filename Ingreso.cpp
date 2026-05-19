#include "Ingreso.h"


Ingreso::Ingreso(int ingresoId, Fecha fechaIngreso){
    this->ingresoId= ingresoId;
    this->fechaIngreso= fechaIngreso;
	this->tieneFechaAlta=false;
	this->descripcion="";   
};

int Ingreso::getIngresoId() const{
    return ingresoId;
};

Fecha Ingreso::getFechaIngresoDerivacion() const{
    return fechaIngreso;
};

Fecha Ingreso:: getFechaAltaDerivacion() const{
    return fechaAlta;
};

bool Ingreso::getTieneFechaAlta() const{
	return tieneFechaAlta;
}

string Ingreso::getDescripcion() const{
	return descripcion;
}

void Ingreso::setFechaAlta(Fecha fechaAlta){
	this->fechaAlta=fechaAlta;
	this->tieneFechaAlta=true;
}

void Ingreso::setDescripcion(string descripcion){
	this->descripcion=descripcion;
}
