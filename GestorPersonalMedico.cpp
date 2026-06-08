#include "GestorPersonalMedico.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

GestorPersonalMedico::GestorPersonalMedico():indicePorMedico(100), indicePorEspecialidad(100){}

vector<int> GestorPersonalMedico::convertirEspecialidadTexto(string texto) const{
	vector<int> especialidades;
	stringstream ss(texto);
	string idTexto;
	
	while(getline(ss, idTexto, ',')){
		if(!idTexto.empty()){
			int id=atoi(idTexto.c_str());
			especialidades.push_back(id);
		}
	}
	return especialidades;
}

void GestorPersonalMedico::agregarMedico(PersonalMedico medico){
	if(existeMedico(medico.getMedicoId())){
		cout<<"Medico existente"<< medico.getMedicoId()<<endl;
		return;
	}
	medicos.push_back(medico);
	int posicion=medicos.size()-1;
	indicePorMedico.insertar(medico.getMedicoId(), posicion);
	vector<int> especialidades=medico.getEspecialidadesIds();
	for(size_t i=0; i<especialidades.size(); i++){
		indicePorEspecialidad.insertar(especialidades[i], posicion);
	}
}

void GestorPersonalMedico::cargarMedicosDesdeArchivo(string nombreArchivo){
	ifstream archivo(nombreArchivo.c_str());
	
	if(!archivo.is_open()){
		cout<<"No se pudo abrir el archivo: "<<nombreArchivo<<endl;
		return;
	} 
	string linea;
	
	while(getline(archivo, linea)){
		if(linea.empty()){
			continue;
		}
		if(linea.find("medicoId")!=string::npos){
			continue;
		}
		stringstream ss(linea);
		
		string medicoIdTexto;
		string nombre;
		string apellido;
		string especialidadTexto;
		string especialidadNombreTexto;
		
		getline(ss, medicoIdTexto, ';');
		getline(ss, nombre, ';');
		getline(ss, apellido, ';');
		getline(ss, especialidadTexto, ';');
		getline(ss, especialidadNombreTexto, ';');
		
		if(medicoIdTexto.empty() || nombre.empty() || apellido.empty() || especialidadTexto.empty()){
			continue;	
		}
		int medicoId=atoi(medicoIdTexto.c_str());
		vector<int> especialidadesIds=convertirEspecialidadTexto(especialidadTexto);
		PersonalMedico medico(nombre, apellido, medicoId, especialidadesIds);
		agregarMedico(medico);	
	}
	archivo.close();
	cout<<"Medicos cargados correctamente"<<endl;
}

PersonalMedico* GestorPersonalMedico::buscarMedicoPorId(int medicoId){
	vector<int> posiciones;
	bool encontrado=indicePorMedico.buscar(medicoId, posiciones);
	
	if(!encontrado || posiciones.empty()){
		return NULL;
	}
	int posicion=posiciones[0];
	if(posicion>=0 && posicion<medicos.size()){
		return &medicos[posicion];
	}
	return NULL;
}

vector<PersonalMedico> GestorPersonalMedico::buscarMedicosPorEspecialidad(int especialidadId) const{
	vector<PersonalMedico> resultado;
	vector<int> posiciones;
	bool encontrado=indicePorEspecialidad.buscar(especialidadId, posiciones);
	if(!encontrado){
		return resultado;
	}
	for(size_t i=0; i<posiciones.size(); i++){
		int posicion=posiciones[i];
		if(posicion>=0 && posicion<medicos.size()){
			resultado.push_back(medicos[posicion]);
		}
	}
	return resultado;
}

vector<PersonalMedico>GestorPersonalMedico::obtenerTodosLosMedicos() const{
	return medicos;
}

bool GestorPersonalMedico::existeMedico(int medicoId){
	return buscarMedicoPorId(medicoId) !=NULL;
}

bool GestorPersonalMedico::medicoTieneEspecialidad(int medicoId, int especialidadId){
	PersonalMedico* medico=buscarMedicoPorId(medicoId);
	if(medico == NULL){
		return false;
	}
	return medico->tieneEspecialidad(especialidadId);
}













