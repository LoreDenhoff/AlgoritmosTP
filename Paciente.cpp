#include "Paciente.h"
#include "Persona.h"
#include "Ingreso.h"

Paciente::Paciente(string _nombre, string _apellido, int _pacienteID, int _dni, float _pesoKg, int _prioridad):Persona(_nombre, _apellido){
    pacienteID= _pacienteID;
    dni= _dni;
    pesoKg= _pesoKg;
    prioridad=static_cast<Prioridad>(_prioridad);
};

int Paciente::getPacienteID(){
    return pacienteID;
};
int Paciente::getDni(){
    return dni;
};
float Paciente::getPesoKg(){
    return pesoKg;
};
int Paciente::getPrioridad(){
    return prioridad;
};
void Paciente::agregarIngreso(const Ingreso& nuevoIngreso){
    ingresos.push_back(nuevoIngreso);
}