#include "Especialidad.h"

Especialidad::Especialidad(int especialidadId, string nombre){
    this->especialidadId=especialidadId;
	this->nombre = nombre;
}

string Especialidad::getEspecialidadNombre() const{
    return this->nombre;
}
