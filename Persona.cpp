
#include "Persona.h"

Persona::Persona(string nombre, string apellido){
	this->nombre=nombre;
	this->apellido=apellido;
}
string Persona::getNombre() const{
    return nombre;
};

string Persona::getApellido() const{
    return apellido;
};
