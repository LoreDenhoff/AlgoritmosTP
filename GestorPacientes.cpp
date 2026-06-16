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

Paciente* GestorPacientes::buscarPacientePorDni(int dni){
    for(size_t i=0; i<pacientes.size(); i++){
        if(pacientes[i].getDni()==dni){
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

        listaDeEspera.insertar(paciente, fechaIngreso);
        
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
    cout<<"Pacientes cargados correctamente"<< endl;
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

void GestorPacientes::actualizarHospitalPacientesArchivo(string nombreArchivo, string codigoAnterior, string codigoNuevo){
    if(codigoNuevo.empty()){
        return;
    }

    ifstream archivoEntrada(nombreArchivo.c_str());

    if(!archivoEntrada.is_open()){
        cout<< "No se pudo abrir el archivo de pacientes para actualizar"<<endl;
        cout<<nombreArchivo<<endl;
        return;
    }

    vector<string> lineas;
    string linea;

    if(getline(archivoEntrada, linea)){
        lineas.push_back(linea);
    }

    while(getline(archivoEntrada, linea)){
        if(linea.empty()){
            continue;
        }
        stringstream ss(linea);

		string codigoHospital;
		string restoLinea;

		getline(ss, codigoHospital, ';');
		getline(ss, restoLinea);

		if(codigoHospital==codigoAnterior){
			linea=codigoNuevo + ";" + restoLinea;
		}

		lineas.push_back(linea);
    }

    archivoEntrada.close();

    ofstream archivoSalida(nombreArchivo.c_str());

    if(!archivoSalida.is_open()){
        cout<< "No se pudo actualizar el archivo de pacientes"<<endl;
        return;
    }

    for(size_t i=0;i<lineas.size();i++){
        archivoSalida<<lineas[i];

        if(i<lineas.size()-1){
            archivoSalida<<endl;
        }
    }
    archivoSalida.close();

    cout<<"Archivo de pacientes actualizado"<<endl;
};

void GestorPacientes::insertarEnListaDeEspera(Paciente paciente, Fecha fechaIngreso){
    listaDeEspera.insertar(paciente, fechaIngreso);
};

void GestorPacientes::mostrarListaDeEspera() const{
    listaDeEspera.mostrarListaDeEspera();
};

void GestorPacientes::atenderPacienteMasPrioritario(){
    Paciente pacienteExtraido("","",0,0,0,5);

    if(!listaDeEspera.extraerMasPrioritario(pacienteExtraido)){
        cout << "No hay pacientes en lista de espera" << endl;
        return;
    }

    cout << "\nPaciente mas prioritario extraido de la lista de espera:" << endl;
    pacienteExtraido.mostrarInfo();
};

void GestorPacientes::actualizarPrioridadPaciente(int dni, int nuevaPrioridad){
    if (nuevaPrioridad < 1 || nuevaPrioridad > 5){
        cout << "Prioridad invalidad. Debe estar entre 1 y 5." << endl;
        return;
    }

    bool actualizada= listaDeEspera.actualizarPrioridad(dni, nuevaPrioridad);

    if(!actualizada){
        cout << "No se encontro un paciente con ese DNI en la lista de espera." << endl;
        return;
    }

    Paciente* paciente= buscarPacientePorDni(dni);

    if(paciente != NULL){
        paciente->setPrioridad(nuevaPrioridad);
    }

    cout << "Prioridad actualizada correctamente." << endl;
};
