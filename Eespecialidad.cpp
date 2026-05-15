#include "Especialidad.h"

Especialidad::Especialidad(string nombre){
    this->nombre = nombre;
}

string Especialidad::getEspecialidadNombre() const{
    return this->nombre;
}