#include "Paciente.h"
#include "Persona.h"
#include "Ingreso.h"
#include <iostream>
using namespace std;

Paciente::Paciente(string nombre, string apellido, int pacienteID, int dni, float pesoKg, int prioridad):Persona(nombre, apellido){
    this->pacienteID= pacienteID;
    this->dni= dni;
    this->pesoKg= pesoKg;
    this->prioridad=static_cast<Prioridad>(prioridad);
};

void Paciente::mostrarInfo(){
    cout << "Nombre: " << getNombre() << endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "Paciente ID: " << pacienteID << endl;
    cout << "DNI: " << dni << endl;
    cout << "Peso: " << pesoKg << " kg" << endl;
    cout << "Prioridad: " << prioridad << endl;
};
int Paciente::getPacienteID() const{
    return pacienteID;
};
int Paciente::getDni() const{
    return dni;
};
float Paciente::getPesoKg() const{
    return pesoKg;
};
int Paciente::getPrioridad() const{
    return prioridad;
};
void Paciente::agregarIngreso(const Ingreso& nuevoIngreso){
    ingresos.push_back(nuevoIngreso);
}
vector<Ingreso> Paciente::getIngresos() const{
    return ingresos;
};