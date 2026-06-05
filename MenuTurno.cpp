#include <iostream>
#include <limits>
#include "MenuTurno.h"
using namespace std;

MenuTurno::MenuTurno(vector<Turno>& turnosRegistrados) : turnosRegistrados(turnosRegistrados){}

void MenuTurno::mostrarMenu() const{
	cout<<"\n ======== MENU TURNO ======="<<endl;
	cout<<"1. Registrar turno"<<endl;
	cout<<"2. Listar turno de un medico"<<endl;
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

void MenuTurno::registrarTurno(){ 
	cout << "\n ======== REGISTRAR TURNO ========" << endl;
	string codigoHospital = leerTexto("Codigo del hospital: ");
	int turnoID = leerEntero("Id del turno: ");
	int pacienteID = leerEntero("Id del paciente: ");
	int medicoID = leerEntero("Id del medico: ");
	Fecha fechaTurno = leerFecha("Fecha del turno: ");
	cout << "Especialidad: ";
	string especialidad;
	getline(cin, especialidad);
	int duracion = leerEntero("Duracion del turno en minutos: ");
	Turno turno(codigoHospital, turnoID, pacienteID, medicoID, fechaTurno, especialidad, duracion);
	turnosRegistrados.push_back(turno); 
	cout<<"Turno registrado correctamente"<<endl;
}

void MenuTurno::listarTurnosMedico(){
	cout << "\n ======== LISTADO DE TURNOS ========" << endl;
	if(turnosRegistrados.empty()){
		cout<<"No hay turnos registrados"<<endl;
		return;
	}
	for(size_t i=0;i<turnosRegistrados.size();i++){
		Fecha fecha=turnosRegistrados[i].getFechaTurno();
		cout<<"\nTurno"<<i+1<<endl;
		cout<<"Fecha : "
			<<fecha.getDia()<<"/"
			<<fecha.getMes()<<"/"
			<<fecha.getAnio()<<endl;
		cout<<"Duracion: "<<turnosRegistrados[i].getDuracion()<<" minutos"<<endl;
		cout<<"Medico: "<<turnosRegistrados[i].getMedico()<<endl;		
	}
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