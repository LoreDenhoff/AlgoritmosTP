#include "GestorHospitales.h"
#include "OrdenadorHospitales.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

GestorHospitales::GestorHospitales(int capacidadTabla)
	: tablaHospitales(capacidadTabla){}
	
void GestorHospitales::agregarHospital(Hospital hospital){
	tablaHospitales.agregarHospital(hospital);
}

//falta derivar a otro hospital ELIMINA SOLO DE LA TABLA PERO NO DEL ARCHIVO
void GestorHospitales::eliminarHospital(string codigo){
	tablaHospitales.eliminarHospital(codigo);
}

Hospital* GestorHospitales::buscarHospital(string codigo){
	return tablaHospitales.buscarHospital(codigo);
}

void GestorHospitales::mostrarHospital(string codigo) const{
	tablaHospitales.mostrarHospital(codigo);
}

vector<Hospital> GestorHospitales::obtenerTodosLosHospitales() const{
	return tablaHospitales.obtenerTodosLosHospitales();
}

void GestorHospitales::ordenarPorCapacidadCamas(){
	vector<Hospital> hospitales=obtenerTodosLosHospitales();
	OrdenadorHospitales::ordenar(hospitales, 1);
		
	for(size_t i=0; i<hospitales.size(); i++){
		hospitales[i].mostrarInformacion();
		cout<<endl;
	}
}

void GestorHospitales::ordenarPorPersonalMedico(){
	vector<Hospital> hospitales=obtenerTodosLosHospitales();
		OrdenadorHospitales::ordenar(hospitales, 2);
		
		for(size_t i=0; i<hospitales.size(); i++){
			hospitales[i].mostrarInformacion();
			cout<<endl;
	}
}
	
void GestorHospitales::ordenarPorPresupuestoAnual(){
	vector<Hospital> hospitales=obtenerTodosLosHospitales();
	OrdenadorHospitales::ordenar(hospitales, 3);
		
	for(size_t i=0; i<hospitales.size(); i++){
		hospitales[i].mostrarInformacion();
		cout<<endl;
	}
}

//revisar ordenamiento
vector<Hospital>GestorHospitales::buscarPorEspecialidad(string especialidad){
	vector<Hospital>hospitales=obtenerTodosLosHospitales();
	vector<Hospital>resultado;
	
	for(size_t i=0;i<hospitales.size();i++){
		if(hospitales[i].ofreceEspecialidad(especialidad)){
			resultado.push_back(hospitales[i]);
		}
	}
	if(resultado.size()<=1){
		return resultado;
	}
	for(size_t i=0;i<resultado.size()-1;i++){
		for(size_t j=0;j<resultado.size()-1;j++){
			if(resultado[j].camasDisponibles()<resultado[j+1].camasDisponibles()){
				Hospital aux=resultado[j];
				resultado[j]=resultado[j+1];
				resultado[j+1]=aux;
			}
		}
	}
	return resultado;
}

double GestorHospitales::factorCarga() const{
	return tablaHospitales.factorCarga();
}

//Carga los hospitales al iniciar el sistema
void GestorHospitales::cargarHospitalesDesdeArchivo(string nombreArchivo, const vector<Especialidad>& especialidades){
	ifstream archivo(nombreArchivo.c_str());
	if(!archivo.is_open()){
		cout<<"No se pudo abrir el archivo de hospitales"<<endl;
		return;
	}
	string linea;
	while(getline(archivo, linea)){
		if(linea.empty()){
			continue;
		}
		stringstream ss(linea);
		string hospitalId;
		string nombre;
		string ciudad;
		string capacidadTexto;
		string especialidadesTexto;
		string personalTexto;
		string presupuestoTexto;
		
		
		getline(ss, hospitalId, ';');
		getline(ss, nombre, ';');
		getline(ss, ciudad, ';');
		getline(ss, capacidadTexto, ';');
		getline(ss, especialidadesTexto, ';');
		getline(ss, personalTexto, ';');
		getline(ss, presupuestoTexto, ';');
		
		
		int capacidadCamas=atoi(capacidadTexto.c_str());
		int personalMedico=atoi(personalTexto.c_str());
		int presupuestoAnual=atoi(presupuestoTexto.c_str());
		
		vector<Especialidad> especialidadesHospital;
		
		stringstream ssEspecialidades(especialidadesTexto);
		string idEspecialidadTexto;
		
		while(getline(ssEspecialidades, idEspecialidadTexto, ',')){
			if(idEspecialidadTexto.empty()){
				continue;
			}
			int idEspecialidad=atoi(idEspecialidadTexto.c_str());
			for(size_t i=0; i<especialidades.size(); i++){
				if(especialidades[i].getEspecialidadId() == idEspecialidad){
					especialidadesHospital.push_back(especialidades[i]);
				}
			}
		}
		
	Hospital hospital(hospitalId, nombre, ciudad, capacidadCamas, especialidadesHospital, personalMedico, presupuestoAnual);
	
	agregarHospital(hospital);
	}
	archivo.close();
	cout<<"Hospitales cargados correctamente"<< endl;
}

void GestorHospitales::guardarHospitalEnArchivo(string nombreArchivo, const Hospital& hospital) const{
	ifstream archivoLectura(nombreArchivo.c_str(), ios::ate);
	
	if(archivoLectura.is_open()){
		if(archivoLectura.tellg()>0){
			archivoLectura.seekg(-1,ios::end);
			char ultimoCaracter;
			archivoLectura.get(ultimoCaracter);
			
			archivoLectura.close();
			
			ofstream archivoSalto(nombreArchivo.c_str(), ios::app);
			
			if(ultimoCaracter !='\n'){
				archivoSalto<<endl;
			}
			archivoSalto.close();
		}else{
			archivoLectura.close();
		}
	}
	
	ofstream archivo(nombreArchivo.c_str(), ios::app);
	
	if(!archivo.is_open()){
		cout<<"No se pudo guardar el hospital"<<endl;
		return;
	}
	

	archivo<<hospital.getHospitalId()<<";";
	archivo<<hospital.getNombre()<<";";
	archivo<<hospital.getCiudad()<<";";
	archivo<<hospital.getCapacidadCamas()<<";";
	vector<Especialidad> especialidadesHospital=hospital.getEspecialidades();
		
	for(size_t i=0;i<especialidadesHospital.size();i++){
		archivo<<especialidadesHospital[i].getEspecialidadId();
		if(i<especialidadesHospital.size()-1){
			archivo<<",";
		}			
	}
		
	archivo<<hospital.getPersonalMedico()<<";";
	archivo<<hospital.getPresupuestoAnual()<<";";
	archivo<<endl;
	archivo.close();
	cout<<"Hospital guarddo correctamente"<<endl;
}
