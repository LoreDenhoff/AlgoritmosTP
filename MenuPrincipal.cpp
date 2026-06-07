#include <vector>
#include <limits>
#include <iostream>
#include <stdexcept>
#include "MenuPrincipal.h"
#include "MenuHospital.h"
#include "MenuPaciente.h"
#include "MenuTurno.h"
#include "MenuDerivacion.h"
#include "MenuDiagnostico.h"
#include "Especialidad.h"
using namespace std;

MenuPrincipal::MenuPrincipal() : sistema(10){
	sistema.inicializarSistema();
}

void MenuPrincipal::mostrarMenuPrincipal() const{
	cout<<"        ----------------------        "<<endl;
	cout<<"=======| SISTEMA HOSPITALARIO |======="<<endl;
	cout<<"        ----------------------        "<<endl;
	
	cout<<"1. Hospitales"<<endl;
	cout<<"2. Pacientes"<<endl;
	cout<<"3. Turnos"<<endl;
	cout<<"4. Derivaciones"<<endl;
	cout<<"5. Diagnosticos"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Seleccione una opcion: ";
}

int MenuPrincipal::leerOpcion() const{
	int opcion;
	while(!(cin>>opcion)){
		cout<< "Entrada invalida. Ingrese unaopcion: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return opcion;
}

void MenuPrincipal::ejecutar(){
	int opcion;
	do{
		try{
			mostrarMenuPrincipal();
			opcion=leerOpcion();
			
			switch(opcion){
				case 1:{
					MenuHospital menuHospital(sistema);
					menuHospital.ejecutar();
					break;
				}
				case 2:{
					MenuPaciente menuPaciente(sistema, pacientesRegistrados);
					menuPaciente.ejecutar();
					break;
				}
				case 3:{
					MenuTurno menuTurno(sistema.getGestorTurnos(), sistema.getGestorPacientes());
					menuTurno.ejecutar();
					break;
				}
				case 4:{
					MenuDerivacion menuDerivacion;
					menuDerivacion.ejecutar();
					break;
				}
				case 5:{
					MenuDiagnostico menuDiagnostico(diagnosticosRegistrados);
					menuDiagnostico.ejecutar();
					break;
				}
				case 0:{
					cout<<"Saliendo del sistema..."<<endl;
					break;
				}

				default:{
					cout<<"Opcion invalida. Ingrese una opcion valida"<<endl;
					break;
			   }
			}
		}
	
	catch(invalid_argument& error){
		cout<<"Error: "<<error.what()<<endl;
	}
}
	while(opcion!=0);
}



