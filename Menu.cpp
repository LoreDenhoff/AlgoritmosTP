#include "Menu.h"
#include "Hospital.h"
#include "Paciente.h"
#include "Ingreso.h"
#include "Especialidad.h"
#include "Fecha.h"
#include <iostream>
#include <stdexcept>
using namescape std;

Menu::Menu():sistema(10){
	//carga de datos
}

void Menu::mostrarMenu() const{
	cout<<"======= SISTEMA HOSPITALARIO ======="<<endl;
	
	cout<<"1. Registrar hospital"<<endl;
	cout<<"2. Listar hospitales"<<endl;
	cout<<"3. Buscar hospital"<<endl;
	cout<<"4. Eliminar hospital"<<endl;
	cout<<"5. Buscar hospital por especialidad"<<endl;
	cout<<"6. Ingresar paciente"<<endl;
	cout<<"7. Pacientes atendidos por rango"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Seleccione una opcion: ";
}

int Menu::leerEntero(string mensaje) const{
	int valor;
	cout<<mensaje;
	
	while(!(cin>>valor)){
		cout<<"Entrada invalida. Ingrese un numero: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	return valor;
}

float Menu::leerFloat(string mensaje) const{
	float valor;
	cout<<mensaje;
	
	while(!(cin>>valor)){
		cout<<"Entrada invalida. Ingrese un numero: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	return valor;
}

string Menu::leerTexto(string mensaje) const{
	string texto;
	cout<<mensaje;
	getline(cin, texto);
	
	return texto;
}

Fecha Menu::leerFecha(string mensaje) const{
	int dia;
	int mes;
	int anio;
	cout<<mensaje<<endl;
	
	dia=leerEntero("Dia: ");
	mes=leerEntero("Mes: ");
	anio=leerEntero("Anio: ");
	
	return Fecha(dia, mes, anio);
}
//Se usa cuando registras un hospital nuevo
vector<Especialidad> Menu::cargarEspecialidadHospital() const{
	vector<Especialidad> especialidadesHospital;
	int cant=leerEntero("Cantidad de especialidades del hospital: ");
	
	for(int i=0; i<cant;i++){
		cout<<"\nEspecialidad "<<i+1<<endl;
		int id=leerEntero("Id de especialidad: ");
		string nombre=leerTexto("Nombre de la especialidad: ");
		
		Especialidad especialidad(id, nombre);
		especialidadesHospital.push_back(especialidad);
	}
	return especialidadesHospital;
}

void Menu::registrarHospital(){
	cout<<"\n ======Registrar Hospital ======"<<endl;
	
	string codigo=leerTexto("Codigo del hospital: ");
	string nombre=leerTexto("Nombre: ");
	string ciudad=leerTexto("Ciudad: ");
	int capacidad=leerEntero("Capacidad de camas: ");
	int personal=leerEntero("Cantidad de personal medico: ");
	int presupuesto=leerEntero("Presupuesto anual: ");
	
	vector<Especialidad> especialidadesHospital=cargarEspecialidadHospital();
	
	Hospital hospital(
		codigo,
		nombre,
		ciudad,
		capacidad,
		personal,
		presupuesto,
		especialidadHospital
	);
	sistema.agregarHospital(hospital);
	cout<<"Hospital registrado correctamente"<<endl;
}

void Menu::listarHospitales(){
	cout<<"\n ======Listado de Hospitales ======"<<endl;
	
	vector<Hospital>=sistema.obtenerTodosLosHospitales();
	if(hospitales.empty()){
		cout<<"No hay hospitales registrados"<<endl;
		return;
	}
	for(size_t i=0; i<hospitales.size();i++){
		cout<<"\nHospital " <<i+1<<endl;
		hospitales[i].mostrarInformacion(); 
	}
}

void Menu::buscarHospital(){
	cout<<"\n ======Buscar Hospital ======"<<endl;
	
	string codigo=leerTexto("Ingrese codigo del hospital: ");
	Hospital * hospital=buscarHospital(codigo);
	if(hospital==NULL){
		cout<<"Hospital no encontrado."<<endl;
		return;
	}
	hospital->mostrarInformacion();
}

void Menu::eliminarHospital(){
	cout<<"\n ======Eliminar Hospital ======"<<endl;
	
	string codigo=leerTexto("Ingrese codigo del hospital: ");
	sistema.eliminarHospital(codigo);
}

void Menu::buscarPorEspecialidad(){
	cout<<"\n ======Buscar por especialidad ======"<<endl;
	
	string especialidad=leerTexto("Ingrese nombre de especialidad: ");
	vector<Hospital> hospitales=sistema.buscarPorEspecialidad(especialidad);
	if(hospitales.empty()){
		cout<<"No se encontraron hospitales con esa especialidad"<<endl;
		return;
	}
	cout<<"\nHospitales encontrados: "<<endl;
	for(size_t i=0;i<hospitales.size();i++){
		cout<<"\nHospital "<<i+1<<endl;
		hospitales[i].mostrarInformacion();
	}
}












