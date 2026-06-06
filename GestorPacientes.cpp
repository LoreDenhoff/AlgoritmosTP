#include "GestorPacientes.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

GestorPacientes::GestorPacientes(){}

Fecha GestorPacientes::convertirTextoAFecha(string textoFecha) const {
    if(textoFecha.length() != 8) {
        return Fecha();
    }

    int anio= stoi(textoFecha.substr(0,4));
    int mes= stoi(textoFecha.substr(4,2));
    int dia= stoi(textoFecha.substr(6,2));
    return Fecha(dia, mes, anio);   
}

void GestorPacientes::agregarPaciente(Paciente paciente) {
    pacientes.push_back(paciente);
};

Paciente* GestorPacientes::buscarPacientePorId(int pacienteId) {
    for(size_t i=0;i<pacientes.size(); i++){
        if(pacientes[i].getPacienteID() == pacienteId){
            return &pacientes[i];
        }
    }
    return NULL;
}

vector<Paciente> GestorPacientes::obtenerTodosLosPacientes() const {
    return pacientes;
}

void GestorPacientes::cargarPacientesDesdeArchivo(string nombreArchivo){
    ifstream archivo(nombreArchivo.c_str());
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo de pacientes: " << nombreArchivo << endl;
        return;
    }
    string linea;
    getline(archivo, linea);

    while(getline(archivo, linea)){
        if(linea.empty()){
            continue;
        }

        stringstream ss(linea);

        string codigoHospital;
        string pacienteIdTexto;
        string nombre;
        string apellido;
        string dniTexto;
        string fechaIngresoTexto;
        string diagnostico;
        string prioridadTexto;
        string pesoTexto;

        getline(ss, codigoHospital, ',');
        getline(ss, pacienteIdTexto, ',');
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, dniTexto, ',');
        getline(ss, fechaIngresoTexto, ',');
        getline(ss, diagnostico, ',');
        getline(ss, prioridadTexto, ',');
        getline(ss, pesoTexto, ',');
         
        int pacienteId = stoi(pacienteIdTexto);
        int dni = stoi(dniTexto);
        int prioridad = stoi(prioridadTexto);
        float pesoKg = stof(pesoTexto);

        Paciente paciente(nombre, apellido, pacienteId, dni, pesoKg, prioridad);

        Fecha fechaIngreso= convertirTextoAFecha(fechaIngresoTexto);
        Ingreso ingreso(pacienteId, fechaIngreso);
        ingreso.setDescripcion(diagnostico);

        paciente.agregarIngreso(ingreso);
        pacientes.push_back(paciente);
    }
    archivo.close();
}

void GestorPacientes::mostrarTodosLosPacientes() const{
    if(pacientes.empty()){
        cout << "No hay pacientes registrados." << endl;
        return;
    }

    for(size_t i=0;i < pacientes.size(); i++){
        cout << "\nPaciente " << i+1 <<endl;
        pacientes[i].mostrarInfo() ;
    }
}
