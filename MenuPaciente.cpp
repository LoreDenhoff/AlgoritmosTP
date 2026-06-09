#include <iostream>
#include <limits>
#include "MenuPaciente.h"
#include "Auxiliares.h"
using namespace std;

MenuPaciente::MenuPaciente(SistemaHospitalario& sistema, vector<Paciente>& pacientesRegistrados) : sistema(sistema), pacientesRegistrados(pacientesRegistrados){}
	
void MenuPaciente::mostrarMenu() const{
	cout<<"\n ======== MENU PACIENTE ======="<<endl;
	cout<<"1. Registrar ingreso"<<endl;
	cout<<"2. Pacientes atendidos por rango"<<endl;
	cout<<"3. Cola de prioridad"<<endl;
	cout<<"0. Volver al menu principal"<<endl;
	cout<<"Seleccione suna opcion: ";
}

void MenuPaciente::ingresarPaciente(){ //DEBERIAMOS PASARLE UN HOSPITAL X PARAMETRO?
	cout << "\n ======== INGRESAR PACIENTE A HOSPITAL ========" << endl;
	string codigoHospital = leerTexto("Codigo del hospital: ");
	Hospital* hospital = sistema.buscarHospital(codigoHospital);

	if(hospital == NULL){
		cout <<"Hospital no encontrado." <<endl;
		return;
	}

	string nombre= leerTexto("Nombre del paciente: ");
	string apellido= leerTexto("Apellido del paciente: ");

	int pacienteID= leerEntero("ID del paciente: ");
	int dni= leerEntero("DNI: ");
	float peso= leerFloat("Peso: ");

	cout << "\nPrioridad: " << endl;
	cout << "1. Critico" << endl;
	cout << "2. Alto" << endl;
	cout << "3. Medio" << endl;
	cout << "4. Bajo" << endl;
	cout << "5. Leve" << endl;

	int prioridad= leerEntero("Ingrese prioridad: ");
	int ingresoID= leerEntero("ID  del ingreso: ");
	Fecha fechaIngreso= leerFecha("Fecha de ingrso: ");
	string descripcion= leerTexto("Descripcion del ingreso: "); 

	Paciente paciente(nombre, apellido,	pacienteID,	dni, peso, prioridad);

	Ingreso ingreso(ingresoID, fechaIngreso);
	ingreso.setDescripcion(descripcion);

	paciente.agregarIngreso(ingreso);
	hospital->ingresarPaciente(paciente, ingreso);

	cout << "Paciente ingresado correctamente." << endl;
}

void MenuPaciente::contarPacientesEnRango(){
	cout << "\n======== PACIENTES ATENDIDOS EN RANGO ========" << endl;

	string codigoHospital= leerTexto("Codigo del hospital: ");

	Hospital* hospital= sistema.buscarHospital(codigoHospital);
	if(hospital == NULL){
		cout << "Hospital  no encontrado." << endl;
		return;
	}

	Fecha desde = leerFecha("Fecha desde");
	Fecha hasta = leerFecha("Fecha hasta");

	int cantidad= hospital->pacientesAtendidosEnRango(desde, hasta);

	cout << "Pacientes atendidos en ese rango: " << cantidad << endl;
}

void MenuPaciente::ejecutar(){
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
				ingresarPaciente();
				break;
			case 2:
				contarPacientesEnRango();
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












