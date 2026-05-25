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
	int turnoID=leerEntero("Id del turno: ");
	Fecha fechaTurno=leerFecha("Fecha del turno: ");
	int duracion=leerEntero("Duracion del turno en minutos: ");
	Turno turno(turnoID, fechaTurno, duracion);
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














