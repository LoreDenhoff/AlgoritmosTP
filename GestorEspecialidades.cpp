#include "GestorEspecialidades.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

GestorEspecialidades::GestorEspecialidades(){}

void GestorEspecialidades::cargarEspecialidadDesdeArchivo(string nombreArchivo){
	especialidades.clear();
	ifstream archivo(nombreArchivo.c_str());
	if(!archivo.is_open()){
		cout<<"No se pudo abrir el archivo de especialidades "<<endl;
		return;
	}
	string linea;
	while(getline(archivo, linea)){
		if(linea.empty()){
			continue;
		}
		stringstream ss(linea);
		string idTexto;
		string nombre;
		
		getline(ss, idTexto, ';');
		getline(ss, nombre, ';');
		
		int id=atoi(idTexto.c_str());
		
		Especialidad especialidad(id, nombre);
		especialidades.push_back(especialidad);
	}
	archivo.close();
	cout<<"Especialidades cargadas correctamente"<<endl;
} 

Especialidad GestorEspecialidades::buscarEspecialidadPorId(int id) const{
	for(size_t i=0;i<especialidades.size();i++){
		if(especialidades[i].getEspecialidadId()==id){
			return especialidades[i];
		}
	}
	return Especialidad();
}

vector<Especialidad> GestorEspecialidades::obtenerTodas() const{
	return especialidades;
}

void GestorEspecialidades::mostrarEspecialidades() const{
	if(especialidades.empty()){
		cout<< "No hay especialidades cargadas"<<endl;
		return;
	}
	for(size_t i=0; i<especialidades.size(); i++){
		cout<<"ID: "<<especialidades[i].getEspecialidadId()
			<<" - Nombre: "<<especialidades[i].getEspecialidadNombre()	
			<<endl;
	}
}























