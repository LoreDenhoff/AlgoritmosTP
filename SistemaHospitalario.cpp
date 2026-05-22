#include "SistemaHospitalario.h"
#include<iostream>

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








