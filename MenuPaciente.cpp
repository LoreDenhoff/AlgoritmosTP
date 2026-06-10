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
	cout<<"3. Hospitales con sobrecarga"<<endl;
	cout<<"4. Mostrar lista de espera"<<endl;
	cout<<"5. Atender paciente mas prioritario"<<endl;
	cout<<"6. Actualizar prioridad del paciente"<<endl;
	cout<<"0. Volver al menu principal"<<endl;
	cout<<"Seleccione suna opcion: ";
}

void MenuPaciente::ingresarPaciente(){ 
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
	if(prioridad < 1 || prioridad > 5){
		cout << "Prioridad invalida. Debe estar entre 1 y 5." << endl;
		return;
	}
	int ingresoID= leerEntero("ID  del ingreso: ");
	Fecha fechaIngreso= leerFecha("Fecha de ingrso: ");
	string descripcion= leerTexto("Descripcion del ingreso: "); 

	Paciente paciente(nombre, apellido,	pacienteID,	dni, peso, prioridad);

	Ingreso ingreso(ingresoID, fechaIngreso);
	ingreso.setDescripcion(descripcion);
	paciente.agregarIngreso(ingreso);
	hospital->ingresarPaciente(paciente, ingreso);

	sistema.getGestorPacientes().agregarPaciente(paciente);
	sistema.getGestorPacientes().insertarEnListaDeEspera(paciente, fechaIngreso);

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

void MenuPaciente::sobrecargaHospitales(){
	cout << "\n======== HISPITALES CON SOBRECARGA ========" << endl;
	int x=leerEntero("Cantidad de ingresos permitidos: ");
	cout<<"\nIngrese rango de fecha"<<endl;
	Fecha desde=leerFecha("Fecha desde: ");
	Fecha hasta=leerFecha("Fecha hasta: ");
	
	vector<Hospital> hospitalesSobrecargados=sistema.hospitalesConSobrecarga(x, desde, hasta);
	
	if(hospitalesSobrecargados.empty()){
		cout<<"No se encontraron hospitales con sobrecarga"<<endl;
		return;
	}
	cout<<"\nHospitales con sobrecarga detectados:"<<endl;
	
	for(size_t i=0; i<hospitalesSobrecargados.size(); i++){
		cout<<"\n----------------------------------"<<endl;
		hospitalesSobrecargados[i].mostrarInformacion();
		int ingresosEnRango=hospitalesSobrecargados[i].pacientesAtendidosEnRango(desde, hasta);
		cout<<"Ingresos en el rango evaluado"<<ingresosEnRango<<endl;
		if(hospitalesSobrecargados[i].tieneSobrecarga()){
			cout<<"Motivo: ocupacion superior al 90%"<<endl;
		}
		if(ingresosEnRango>x){
			cout<<"Motivo: mas de "<<x<<"ingresos"<<endl;
		}
	}
}

void MenuPaciente::mostrarListaDeEspera(){
	sistema.getGestorPacientes().mostrarListaDeEspera();
};

void MenuPaciente::aterderPacienteMasPrioritario(){
	sistema.getGestorPacientes().atenderPacienteMasPrioritario();
};

void MenuPaciente::ActualizarPrioridadPaciente(){
	cout << "\n============= ACTUALIZAR PRIORIDAD =============" << endl;

	int dni= leerEntero("DNI del paciente: ");
	
	cout << "\nNueva prioridad: " << endl;
	cout << "1. Critico" << endl;
	cout << "2. Alto" << endl;
	cout << "3. Medio" << endl;
	cout << "4. Bajo" << endl;
	cout << "5. Leve" << endl;

	int nuevaPrioridad= leerEntero("Ingrese en NUMERO la nueva prioridad: ");

	sistema.getGestorPacientes().actualizarPrioridadPaciente(dni , nuevaPrioridad);
	
};

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
			case 3:
				sobrecargaHospitales();
				break;
			case 4:
				mostrarListaDeEspera();
				break;
			case 5:
				aterderPacienteMasPrioritario();
				break;
			case 6:
				ActualizarPrioridadPaciente();
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












