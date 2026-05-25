#include "SistemaHospitalario.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

SistemaHospitalario::SistemaHospitalario(int capacidadTabla){
	this->capacidadTabla=capacidadTabla;
	this->cantHospitales=0;
	tablaHash.resize(capacidadTabla);	
}

//Existen diferentes manera d ehacer la funcion hash, comparar
int SistemaHospitalario::funcionHash(string codigo) const{
	int suma=0;
	for(size_t i=0;i<codigo.length();i++){
		suma+=codigo[i]*(i+1);
	}
	return suma%capacidadTabla;
}

vector<Especialidad> SistemaHospitalario::cargarEspecialidadesDesdeArchivo(string nombreArchivo){
	vector<Especialidad> especialidades;
	ifstream archivo(nombreArchivo.c_str());
	if(!archivo.is_open()){
		cout<<"No se pudo abrir el archivo de especialidades "<<endl;
		return especialidades;
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
	return especialidades;
}

Especialidad SistemaHospitalario::buscarEspecialidadPorId(int id, const vector<Especialidad>& especialidades) const{
	for(size_t i=0;i<especialidades.size();i++){
		if(especialidades[i].getEspecialidadId()==id){
			return especialidades[i];
		}
	}
	return Especialidad();
}

void SistemaHospitalario::agregarHospital(Hospital hospital){
	int indiceHash=funcionHash(hospital.getHospitalId());
	
	for(size_t i=0; i<tablaHash[indiceHash].size();i++){
		if(tablaHash[indiceHash][i].getHospitalId()==hospital.getHospitalId()){
			cout<<"Hospital ya registrado"<<endl;
			return;
		}
	}
	tablaHash[indiceHash].push_back(hospital);
	cantHospitales++;
}

//falta derivar a otro hospital
void SistemaHospitalario::eliminarHospital(string codigo){
	int indiceHash=funcionHash(codigo);
	
	for(size_t i=0; i<tablaHash[indiceHash].size();i++) {
		if(tablaHash[indiceHash][i].getHospitalId()==codigo){
			tablaHash[indiceHash].erase(tablaHash[indiceHash].begin()+i);
			cantHospitales--;
			cout<<"Hospital eliminado correctamente"<<endl;
			return;
		}
	}
	cout<<"Hospital no encontrado"<<endl;
}

Hospital* SistemaHospitalario::buscarHospital(string codigo){
	int indiceHash=funcionHash(codigo);
	
	for(size_t i=0; i<tablaHash[indiceHash].size();i++){
		if(tablaHash[indiceHash][i].getHospitalId()==codigo){
			return &tablaHash[indiceHash][i];
		}
	}
	return NULL;
}

void SistemaHospitalario::mostrarHospital(string codigo) const{
	int indiceHash=funcionHash(codigo);
	
	for(size_t i=0; i<tablaHash[indiceHash].size();i++){
		if(tablaHash[indiceHash][i].getHospitalId()==codigo){
			tablaHash[indiceHash][i].mostrarInformacion();
			return;
		}
	}
	cout<<"Hospital no esncontrado"<<endl;
}

vector<Hospital>SistemaHospitalario::obtenerTodosLosHospitales() const{
	vector<Hospital>hospitales;
	
	for(size_t i=0;i<tablaHash.size();i++){
		for(size_t j=0;j<tablaHash[i].size();j++){
			hospitales.push_back(tablaHash[i][j]);
		}
	}
	return hospitales;
}
	//ver que algoritmo de ordenamieno conviene
	void SistemaHospitalario::ordenarPorCapacidadCamas(){
	//codigo
	}
	void SistemaHospitalario::ordenarPorPersonalMedico(){
	//codigo
	}
	void SistemaHospitalario::ordenarPorPresupuestoAnual(){
	//codigo
	}

//revisar ordenamiento
vector<Hospital>SistemaHospitalario::buscarPorEspecialidad(string especialidad){
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

double SistemaHospitalario::factorCarga() const{
	return (double) cantHospitales/capacidadTabla;
}
//Carga los hospitales al iniciar el sistema
void SistemaHospitalario::cargarHospitalesDesdeArchivo(string nombreArchivo, const vector<Especialidad>& especialidades){
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
			Especialidad especialidad=buscarEspecialidadPorId( idEspecialidad, especialidades);
			
			if(especialidad.getEspecialidadId()!=0){
				especialidadesHospital.push_back(especialidad);
			}
		}
		
	Hospital hospital(hospitalId, nombre, ciudad, capacidadCamas, especialidadesHospital, personalMedico, presupuestoAnual);
	
	agregarHospital(hospital);
	}
	archivo.close();
	cout<<"Hospitales cargados correctamente"<< endl;
}

void SistemaHospitalario::guardarHospitalEnArchivo(string nombreArchivo, const Hospital& hospital) const{
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








