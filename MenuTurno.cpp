#include <iostream>
#include <limits>
#include "MenuTurno.h"
using namespace std;

MenuTurno::MenuTurno(GestorTurnos& gestorTurnos, GestorPacientes& gestorPacientes, GestorHospitales& gestorHospitales) : gestorTurnos(gestorTurnos), gestorPacientes(gestorPacientes), gestorHospitales(gestorHospitales){}

void MenuTurno::mostrarMenu() const{
	cout<<"\n ======== MENU TURNO ======="<<endl;
	cout<<"1. Registrar turno"<<endl;
	cout<<"2. Listar turno de un medico"<<endl;
	cout<<"3. Buscar turnos de un paciente por DNI"<<endl;
	cout<<"0. Volver al menu principal"<<endl;
	cout<<"Seleccione suna opcion: ";
}

int MenuTurno::leerEntero(string mensaje) const{
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

string MenuTurno:: leerTexto(string mensaje) const{
	string texto;
	cout<<mensaje;
	getline(cin, texto);
	return texto;
}

Fecha MenuTurno::leerFecha(string mensaje) const{
	int dia;
	int mes;
	int anio;
	cout<<mensaje<<endl;
	
	dia=leerEntero("Dia: ");
	mes=leerEntero("Mes: ");
	anio=leerEntero("Anio: ");
	return Fecha(dia, mes, anio);
}

void MenuTurno::mostrarHospitalesDisponibles() const{
	vector<Hospital> hospitales=gestorHospitales.obtenerTodosLosHospitales();
	if(hospitales.empty()){
		cout<<"No hay hospitales cargados en el sistema"<<endl;
		return;
	}
	cout<<"\n Hospitales disponibles"<<endl;
	for(size_t i=0; i<hospitales.size(); i++){
		cout<<hospitales[i].getHospitalId()
			<<" - "
			<<hospitales[i].getNombre()
			<<endl;
	}
}

string MenuTurno::leerCodigoHospitalValido() const{
	char respuesta;
	cout<<"Desea ver los hospitales disponibles? (s/n): ";
	cin>>respuesta;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	if(respuesta=='s' || respuesta=='S'){
		mostrarHospitalesDisponibles();
	}
	string codigoHospital;
	while(true){
		codigoHospital=leerTexto("Codigo del hospital: ");
		Hospital* hospital=gestorHospitales.buscarHospital(codigoHospital);
		if(hospital != NULL){
			return codigoHospital;
		}
		
		cout<<"Codigo invalido. Intente de nuevo"<<endl;
	}
}

void MenuTurno::registrarTurno(){ 
	cout << "\n ======== REGISTRAR TURNO ========" << endl;
	string codigoHospital = leerCodigoHospitalValido();
	int turnoID = leerEntero("Id del turno: ");
	int pacienteID = leerEntero("Id del paciente: ");
	int medicoID = leerEntero("Id del medico: ");
	Fecha fechaTurno = leerFecha("Fecha del turno: ");
	cout << "Especialidad: ";
	string especialidad;
	getline(cin, especialidad);
	int duracion = leerEntero("Duracion del turno en minutos: ");
	Turno turno(codigoHospital, turnoID, pacienteID, medicoID, fechaTurno, especialidad, duracion);
	gestorTurnos.agregarTurno(turno); 
	gestorTurnos.guardarTurnoEnArchivo("datos/turnos.txt", turno);
	cout<<"Turno registrado correctamente"<<endl;
}

void MenuTurno::listarTurnosMedico(){
	cout << "\n ======== TURNOS DE MEDICO ========" << endl;
	int medicoId=leerEntero("Ingrese ID del medico: " );
	vector<Turno> turnos=gestorTurnos.buscarTurnosPorMedicoId(medicoId);
	if(turnos.empty()){
		cout<<"No se econtraron turnos"<<endl;
		return;
	}
	gestorTurnos.mostrarTurnos(turnos);
}

void MenuTurno::listarTurnosPacientePorDni(){
	cout << "\n ======== TURNO DE PACIENTE ========" << endl;
	int dni=leerEntero("Ingrese DNI del paciente: ");
	
	vector<Turno> turnos=gestorTurnos.buscarTurnosPorDni(dni, gestorPacientes);
	if(turnos.empty()){
		cout<<"No se encontraron turnos"<<endl;
		return;
	}
	gestorTurnos.mostrarTurnos(turnos);
}

void MenuTurno::ejecutar(){
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
				registrarTurno();
				break;
			case 2:
				listarTurnosMedico();
				break;
			case 3:
				listarTurnosPacientePorDni();
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
