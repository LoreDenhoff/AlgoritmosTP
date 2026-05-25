#include <iostream>
#include <limits>
#include "MenuHospital.h"
using namespace std;

MenuHospital::MenuHospital(SistemaHospitalario& sistema) : sistema(sistema){}

void MenuHospital::mostrarMenu() const{
	cout<<"\n ======== MENU HOSPITALES ======="<<endl;
	cout<<"1. Registrar hospital"<<endl;
	cout<<"2. Listar hospitales"<<endl;
	cout<<"3. Buscar hospital"<<endl;
	cout<<"4. Eliminar hospital"<<endl;
	cout<<"5. Buscar por especialidad"<<endl;
	cout<<"6. Mostrar factos de carga"<<endl;
	cout<<"0. Volver al menu principal"<<endl;
	cout<<"Seleccione suna opcion: ";
}

int MenuHospital::leerEntero(string mensaje) const{
	int valor;
	cout<<mensaje;
	while(!(cin>>valor)){
		cout<<"Entrada invalida. Elija una opcion: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return valor;
}

string MenuHospital::leerTexto(string mensaje) const{
	string texto;
	cout<<mensaje;
	getline(cin, texto);
	return texto;
}

vector<Especialidad> MenuHospital::cargarEspecialidadHospital() const{
	vector<Especialidad> especialidades;
	int cant=leerEntero("Cantidad de especialidades del hospital: ");
	for(int i=0;i<cant;i++){
		cout<<"\nEspecialidad "<<i+1<<endl;
		int id=leerEntero("Id de la especialidad: ");
		string nombre=leerTexto("Nombre de la especialidad: ");
		Especialidad especialidad(id, nombre);
		especialidades.push_back(especialidad);
	}
	return especialidades;
}

void MenuHospital::registrarHospital(){
	cout<<"\n ======== REGISTRAR HOSPITAL ======="<<endl;
	string codigo=leerTexto("Codigo del hospital: ");
	string nombre=leerTexto("Nombre: ");
	string ciudad=leerTexto("Ciudad: ");
	int capacidad=leerEntero("Capacidad de camas: ");
	vector<Especialidad> especialidades=cargarEspecialidadHospital();
	int personal=leerEntero("Cantidad de personal medico: ");
	int presupuesto=leerEntero("Presupuesto anual: ");
	
	Hospital hospital(codigo, nombre, ciudad, capacidad, especialidades, personal, presupuesto);
	
	sistema.agregarHospital(hospital);
	sistema.guardarHospitalEnArchivo("datos/hospitales.txt", hospital);
	cout<<"Hospital registrado correctamente"<<endl;	
}

void MenuHospital::listarHospitales(){
	vector<Hospital> hospitales=sistema.obtenerTodosLosHospitales();
	if(hospitales.empty()){
		cout<<"No hay hospitales registrados"<<endl;
		return;
	}
	for(size_t i=0; i<hospitales.size();i++){
		cout<<"\nHospital " <<i+1<<endl;
		hospitales[i].mostrarInformacion(); 
	}
}

void MenuHospital::buscarHospital(){
	cout<<"\n ======== Buscar Hospital ========"<<endl;
	
	string codigo=leerTexto("Ingrese codigo del hospital: ");
	Hospital* hospital=sistema.buscarHospital(codigo);
	if(hospital==NULL){
		cout<<"Hospital no encontrado."<<endl;
		return;
	}
	hospital->mostrarInformacion();
}

void MenuHospital::eliminarHospital(){
	cout<<"\n ======== Eliminar Hospital ========"<<endl;
	
	string codigo=leerTexto("Ingrese codigo del hospital: ");
	sistema.eliminarHospital(codigo);
}

void MenuHospital::buscarPorEspecialidad(){
	cout<<"\n ======== Buscar por especialidad ========"<<endl;
	
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

void MenuHospital::mostrarFactorCarga(){
	cout << "\n ======== FACTOR DE CARGA ========" << endl;
	cout << "Factor de carga: " << sistema.factorCarga() << endl;
}

void MenuHospital::ejecutar(){
	int opcion;
	
	do{
		mostrarMenu();
		while(!(cin>>opcion)){
			cout<<"Entrada invalida. Ingrese una opcion valida: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch(opcion){
			case 1: 
				registrarHospital();
				break;
			case 2:
				listarHospitales();
				break;
			case 3:
				buscarHospital();
				break;
			case 4:
				eliminarHospital();
				break;
			case 5:
				buscarPorEspecialidad();
				break;
			case 6:
				mostrarFactorCarga();
				break;
			case 0:
				cout<<"Volviendo al menu principal..."<<endl;
				break;
			default:
				cout<<"Opcion invalida. Intente de nuevo"<<endl;
				break;
		}
	}
	while(opcion!=0);
}
















