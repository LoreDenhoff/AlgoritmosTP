#include "GestorHospitales.h"
#include "OrdenadorHospitales.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

GestorHospitales::GestorHospitales(int capacidadTabla)
	: tablaHospitales(capacidadTabla){}
	
Hospital* GestorHospitales::buscarHospitalDisponibleParaReasignar(string codigoOrigen, int cantidadPacientes){
	vector<Hospital> hospitales= arbolHospitales.obtenerTodos();

	Hospital* mejorHospital= NULL;
	int mayorCantidadDeCamas= -1;

	for(size_t i= 0; i<hospitales.size(); i++){
		string codigoActual= hospitales[i].getHospitalId();

		if(codigoActual != codigoOrigen && hospitales[i].puedeRecibirPacientes(cantidadPacientes)){
			Hospital* hospitalEnTabla= tablaHospitales.buscarHospital(codigoActual);

			if(hospitalEnTabla != NULL && hospitalEnTabla->camasDisponibles() > mayorCantidadDeCamas){
				mejorHospital= hospitalEnTabla;
				mayorCantidadDeCamas= hospitalEnTabla->camasDisponibles();
			}
		}
	}
	return mejorHospital;
}

void GestorHospitales::agregarHospital(Hospital hospital){
	Hospital* existente= tablaHospitales.buscarHospital(hospital.getHospitalId());
	if(existente!=NULL){
		cout << "Ya existe un hospital con el codigo " << hospital.getHospitalId() <<endl;
		return;
	}
	bool insertado= false;
	Hospital* hospitalEnArbol= arbolHospitales.insertar(hospital, insertado);
 
	if (insertado && hospitalEnArbol != NULL){
		tablaHospitales.agregarHospital(hospitalEnArbol);
	}
}

//falta derivar a otro hospital 
/*
void GestorHospitales::eliminarHospital(string codigo){
	Hospital* existente= tablaHospitales.buscarHospital(codigo);
	if(existente==NULL){
		cout << "Hospital no encontrado" << endl;
		return;
	}
	
	tablaHospitales.eliminarHospital(codigo);
	bool eliminado= arbolHospitales.eliminar(codigo);
	if(eliminado){
		actualizarArchivo("datos/hospitales.txt");
		cout << "Hospital eliminado correctamente" << endl;
	}else{
		cout << "No se pudo eliminar el hospital" <<endl;
	}
}*/

bool GestorHospitales::eliminarHospital(string codigo, string& codigoHospitalDestino){
	codigoHospitalDestino= "";
	
	Hospital* existente= tablaHospitales.buscarHospital(codigo);
	if(existente==NULL){
		cout << "Hospital no encontrado" << endl;
		return false;
	}

	vector<Paciente> pacientesActivos= existente->getPacientesActivos();
	int cantidadDePacientes=  pacientesActivos.size();

	if(cantidadDePacientes>0){
		Hospital* hospitalDestino= buscarHospitalDisponibleParaReasignar(codigo, cantidadDePacientes);

		if(hospitalDestino==NULL){
			cout << "No se puede eliminar el hospital porque tiene pacientes activos ";
			cout << "y no hay otro hospital con camas suficientes para reasignarlos" << endl;
			return false;
		}

		hospitalDestino->agregarPacientesActivos(pacientesActivos);
		codigoHospitalDestino= hospitalDestino->getHospitalId();

		cout<< "Pacientes reasignados al hospital ";
		cout<< hospitalDestino->getHospitalId()<<" - "<< hospitalDestino->getNombre()<<endl;
	}

	tablaHospitales.eliminarHospital(codigo);

	bool eliminado= arbolHospitales.eliminar(codigo);

	if(eliminado){
		actualizarArchivo("datos/hospitales.txt");
		cout<< "Hospital eliminado correctamente"<<endl;
		return true;
	}else{
		cout<< "No se pudo eliminar el hospital"<<endl;
		return false;
	}
}


Hospital* GestorHospitales::buscarHospital(string codigo){
	return tablaHospitales.buscarHospital(codigo);
}

void GestorHospitales::mostrarHospital(string codigo) const{
	tablaHospitales.mostrarHospital(codigo);
}

vector<Hospital> GestorHospitales::obtenerTodosLosHospitales() const{
	return arbolHospitales.obtenerTodos();
}

void GestorHospitales::ordenarPorCapacidadCamas(){
	vector<Hospital> hospitales=obtenerTodosLosHospitales();
	OrdenadorHospitales::ordenar(hospitales, 1);
		
	for(size_t i=0; i<hospitales.size(); i++){
		hospitales[i].mostrarInformacion();
		cout<<"\n----------------------------------"<<endl;
		cout<<endl;
	}
}

void GestorHospitales::ordenarPorPersonalMedico(){
	vector<Hospital> hospitales=obtenerTodosLosHospitales();
	OrdenadorHospitales::ordenar(hospitales, 2);
		
	for(size_t i=0; i<hospitales.size(); i++){
		hospitales[i].mostrarInformacion();
		cout<<"\n----------------------------------"<<endl;
		cout<<endl;
	}
}
	
void GestorHospitales::ordenarPorPresupuestoAnual(){
	vector<Hospital> hospitales=obtenerTodosLosHospitales();
	OrdenadorHospitales::ordenar(hospitales, 3);
		
	for(size_t i=0; i<hospitales.size(); i++){
		hospitales[i].mostrarInformacion();
		cout<<"\n----------------------------------"<<endl;
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
	//if(resultado.size()<=1){
	//	return resultado;
	//}
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

void GestorHospitales::actualizarArchivo(string nombreArchivo) const{
	ofstream archivo(nombreArchivo.c_str());
	if(!archivo.is_open()){
		cout<<"No se pudo actualizar el archivo"<<endl;
		return;
	}
	archivo<<"codigo;nombre;ciudad;capacidadCamas;especialidadIds;personalMedico;presupuestoAnual"<<endl;
	vector<Hospital> hospitales=arbolHospitales.obtenerTodos();
	
	for(size_t i=0; i<hospitales.size(); i++){
		archivo<<hospitales[i].getHospitalId()<<";";
		archivo<<hospitales[i].getNombre()<<";";
		archivo<<hospitales[i].getCiudad()<<";";
		archivo<<hospitales[i].getCapacidadCamas()<<";";
		
		vector<Especialidad> especialidadesHospital=hospitales[i].getEspecialidades();
		
		for (size_t j=0; j<especialidadesHospital.size(); j++){
			archivo<< especialidadesHospital[j].getEspecialidadId();
			if(j<especialidadesHospital.size()-1){
				archivo<<",";
			}
		}	
		archivo<<";";
		archivo<<hospitales[i].getPersonalMedico()<<";";	
		archivo<<hospitales[i].getPresupuestoAnual()<<";";	
		if(i<hospitales.size()-1){
			archivo<<endl;
		}
	}
	archivo.close();
	cout<<"Archivo actualizado"<<endl;
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
		if(linea.find("codigo") != string::npos){
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
		
		if(hospitalId.empty() || nombre.empty() ||ciudad.empty()){
			continue;
		}
		
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

vector<Hospital> GestorHospitales::hospitalesConSobrecarga(int x, Fecha fechaDesde, Fecha fechaHasta){
	vector<Hospital> hospitales=obtenerTodosLosHospitales();
	vector<Hospital>sobrecargados;
	
	for(size_t i=0; i<hospitales.size(); i++){
		bool sobrecargaPorOcupacion=hospitales[i].tieneSobrecarga();
		bool sobrecargaPorIngresos=hospitales[i].ingresosEnSemana(x, fechaDesde, fechaHasta);
		if(sobrecargaPorOcupacion || sobrecargaPorIngresos){
			sobrecargados.push_back(hospitales[i]);
		}
	}	
	return sobrecargados;
}



















