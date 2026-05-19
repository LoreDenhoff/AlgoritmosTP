#include "Especialidad.h"

Especialidad::Especialidad(){
	especialidadId=0;
	nombre="";
}

Especialidad::Especialidad(int especialidadId, string nombre){
    this->especialidadId=especialidadId;
	this->nombre = nombre;
}

int Especialidad::getEspecialidadId() const{
	return especialidadId;
}
string Especialidad::getEspecialidadNombre() const{
    return nombre;
}
