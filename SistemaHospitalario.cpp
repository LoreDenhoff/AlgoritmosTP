#include "SistemaHospitalario.h"

SistemaHospitalario::SistemaHospitalario(int capacidadTabla):gestorHospitales(capacidadTabla){}

void SistemaHospitalario::inicializarSistema(){
	gestorEspecialidades.cargarEspecialidadDesdeArchivo("datos/especialidades.txt");
	gestorHospitales,cargarHospitalesDesdeArchivo("datos/hospitales.txt", gestorEspecialidades.obtenerTodas());
}

GestorHospitales& SistemaHospitalario::getGestorHospitales(){
	return gestorHospitales;
}

GestorEspecialidades& SistemaHospitalario::getGestorEspecialidades(){
	return gestorEspecialidades;
}

void SistemaHospitalario::agregarHospital(Hospital hospital){
	gestorHospitales.agregarHospital(hospital);
}

void SistemaHospitalario::eliminarHospital(string codigo){
	gestorHospitales.eliminarHospital(codigo);
}

Hospital* SistemaHospitalario::buscarHospital(string codigo){
	return gestorHospitales.buscarHospital(codigo);
}

void SistemaHospitalario::mostrarHospital(string codigo) const{
	gestorHospitales.mostrarHospital(codigo);
}

vector<Hospital> SistemaHospitalario::obtenerTodosLosHospitales() const{
	return gestorHospitales.obtenerTodosLosHospitales();
}

void SistemaHospitalario::ordenarPorCapacidadCamas(){
	gestorHospitales.ordenarPorCapacidadCamas();
}

void SistemaHospitalario::ordenarPorPersonalMedico(){
	gestorHospitales.ordenarPorPersonalMedico();
}

void SistemaHospitalario::ordenarPorPresupuestoAnual(){
	gestorHospitales.ordenarPorPresupuestoAnual();
}

vector<Hospital> SistemaHospitalario::buscarPorEspecialidad(string especialidad){
	return gestorHospitales.buscarPorEspecialidad(especialidad);
}

double SistemaHospitalario::factorCarga() const{
	return gestorHospitales.factorCarga();
}

void SistemaHospitalario::cargarHospitalesDesdeArchivo(string nombreArchivo, const vector<Especialidad>& especialidades){
	gestorHospitales.cargarHospitalesDesdeArchivo(nombreArchivo, especialidades);	
}

void SistemaHospitalario::guardarHospitalEnArchivo(string nombreArchivo, const Hospital& hospital) const{
	gestorHospitales.guardarHospitalEnArchivo(nombreArchivo, hospital);	
}

vector<Especialidad> SistemaHospitalario::cargarEspecialidadesDesdeArchivo(string nombreArchivo){
	gestorEspecialidades.cargarEspecialidadDesdeArchivo(nombreArchivo);
	return gestorEspecialidades.obtenerTodas();	
	
}







