#include "GestorTurnos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

GestorTurnos::GestorTurnos(): indicePorPaciente(101), indicePorMedico(101) {}


void GestorTurnos::ordenarTurnosPorFecha(vector<Turno>& lista) const{
	for(size_t i=0; i<lista.size();i++){
		for(size_t j=0; j+1<lista.size(); j++){
			Fecha fechaActual=lista[j].getFechaTurno();
			Fecha fechaSiguiente=lista[j+1].getFechaTurno();
			
			if(fechaSiguiente.menorIgualQue(fechaActual)){
				Turno aux=lista[j];
				lista[j]=lista[j+1];
				lista[j+1]=aux;
			}
			
		}
	}
}

void GestorTurnos::agregarTurno(Turno turno){
	turnos.push_back(turno);
	int posicion=turnos.size()-1;
	indicePorPaciente.insertar(turno.getPacienteId(), posicion);
	indicePorMedico.insertar(turno.getMedicoId(), posicion);
}

vector<Turno> GestorTurnos::obtenerTodosLosTurnos() const{
	return turnos;
}

vector<Turno> GestorTurnos::buscarTurnosPorPacienteId(int pacienteId) const{
	vector<Turno> resultado;
	vector<int> posiciones;
	
	bool encontrado=indicePorPaciente.buscar(pacienteId, posiciones);
	if(!encontrado){
		return resultado;
	}
	for(size_t i=0; i<posiciones.size(); i++){
		int posicion=posiciones[i];
		if(posicion>=0 && posicion<turnos.size()){
			resultado.push_back(turnos[posicion]);
		}
	}
	ordenarTurnosPorFecha(resultado);
	return resultado;
}

vector<Turno> GestorTurnos::buscarTurnosPorDni(int dni, GestorPacientes& gestorPacientes) const{
	vector<Turno> resultado;
	
	Paciente* paciente=gestorPacientes.buscarPacientePorDni(dni);
	if(paciente==NULL){
		return resultado;
	}
	int pacienteId=paciente->getPacienteID();
	resultado=buscarTurnosPorPacienteId(pacienteId);
	return resultado;
}

vector<Turno> GestorTurnos::buscarTurnosPorMedicoId(int medicoId) const{
	vector<Turno> resultado;
	vector<int> posiciones;
	bool encontrado=indicePorMedico.buscar(medicoId, posiciones);
	if(!encontrado){
		return resultado;
	}
	for(size_t i=0; i<posiciones.size(); i++){
		int posicion=posiciones[i];
		if(posicion>=0 && posicion<turnos.size()){
			resultado.push_back(turnos[posicion]);
		}
	}
	ordenarTurnosPorFecha(resultado);
	return resultado;
}

void GestorTurnos::cargarTurnosDesdeArchivo(string nombreArchivo){
	ifstream archivo(nombreArchivo.c_str());
	if(!archivo.is_open()){
		cout<<"No se  pudo abrir el archivo: "<<nombreArchivo<<endl;
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
		string turnoIdTexto;
		string pacienteIdTexto;
		string medicoIdTexto;
		string fechaTurnoTexto;
		string especialidad;
		string duracionTexto;
		
		getline(ss, codigoHospital, ';');
        getline(ss, turnoIdTexto, ';');
        getline(ss, pacienteIdTexto, ';');
        getline(ss, medicoIdTexto, ';');
        getline(ss, fechaTurnoTexto, ';');
        getline(ss, especialidad, ';');
        getline(ss, duracionTexto, ';');

		int turnoId=atoi(turnoIdTexto.c_str());
		int pacienteId=atoi(pacienteIdTexto.c_str());
		int medicoId=atoi(medicoIdTexto.c_str());
		int duracion=atoi(duracionTexto.c_str());
		
		Fecha fechaTurno=convertirTextoAFecha(fechaTurnoTexto);
		
		Turno turno(codigoHospital, turnoId, pacienteId, medicoId, fechaTurno, especialidad, duracion);
		agregarTurno(turno);
	}
		archivo.close();
}

void GestorTurnos::mostrarTurnos(const vector<Turno>& lista) const{
	if(lista.empty()){
		cout<<"No se econtraron turnos"<<endl;
		return;
	}
	for(size_t i=0; i<lista.size(); i++){
		cout<<"\n Turno "<<i+1<<endl;
		lista[i].mostrarInformacion();
	}
} 

void GestorTurnos::guardarTurnoEnArchivo(string nombreArchivo, const Turno& turno) const{
	ofstream archivo(nombreArchivo.c_str(), ios::app);
	if(!archivo.is_open()){
		cout<<"No sepuede abrir el archivo"<< endl;
		return;
	}
	Fecha fecha=turno.getFechaTurno();
	archivo <<turno.getCodigoHospital()<<";"
			<<turno.getTurnoId()<<";"
			<<turno.getPacienteId()<<";"
			<<turno.getMedicoId()<<";";
	archivo<<fecha.getAnio();
	if(fecha.getMes()<10){archivo<<"0";}
	archivo<<fecha.getMes();
	if(fecha.getDia()<10){archivo<<"0";}
	archivo<<";"
			<<turno.getEspecialidad()<<";"
			<<turno.getDuracion()
			<<endl;
	archivo.close();
			
}




















