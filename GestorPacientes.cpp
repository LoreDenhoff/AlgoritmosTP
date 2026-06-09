#include "GestorPacientes.h"
#include "Auxiliares.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

GestorPacientes::GestorPacientes(){}

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

void GestorPacientes::cargarPacientesDesdeArchivo(string nombreArchivo, GestorHospitales& gestorHospitales){
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

        getline(ss, codigoHospital, ';');
        getline(ss, pacienteIdTexto, ';');
        getline(ss, nombre, ';');
        getline(ss, apellido, ';');
        getline(ss, dniTexto, ';');
        getline(ss, fechaIngresoTexto, ';');
        getline(ss, diagnostico, ';');
        getline(ss, prioridadTexto, ';');
        getline(ss, pesoTexto, ';');
         
        int pacienteId = atoi(pacienteIdTexto.c_str());
        int dni = atoi(dniTexto.c_str());
        int prioridad = atoi(prioridadTexto.c_str());
        float pesoKg = atof(pesoTexto.c_str());

        Paciente paciente(nombre, apellido, pacienteId, dni, pesoKg, prioridad);

        Fecha fechaIngreso= convertirTextoAFecha(fechaIngresoTexto);
        Ingreso ingreso(pacienteId, fechaIngreso);
        ingreso.setDescripcion(diagnostico);

        paciente.agregarIngreso(ingreso);
        pacientes.push_back(paciente);
        
        Hospital* hospital=gestorHospitales.buscarHospital(codigoHospital);
        if(hospital !=NULL){
        	hospital->ingresarPaciente(paciente, ingreso);
		}
		else{
			cout<<"No se encontro el hospital"<<codigoHospital
				<<" para el apciente "<<pacienteId<<endl;
		}
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

Paciente* GestorPacientes::buscarPacientePorDni(int dni){
	for(size_t i=0; i<pacientes.size(); i++){
		if(pacientes[i].getDni()==dni){
			return &pacientes[i];
		}
	}
	return NULL;
}
