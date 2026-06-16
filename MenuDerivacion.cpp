#include "MenuDerivacion.h"
#include <iostream>
#include <limits>
using namespace std;

MenuDerivacion::MenuDerivacion(SistemaHospitalario& sistema) : sistema(sistema){}

void MenuDerivacion::mostrarMenu() const{
	cout<<"\n ======== MENU DERIVACION ======="<<endl;
	/*7cout<<"1. Registrar derivacion"<<endl;*/
	cout<<"1. Mostrar derivaciones cargadas"<<endl;
	cout<<"2. Calcular ruta de menor tiempo"<<endl;
	cout<<"0. Volver al menu principal"<<endl;
	cout<<"Seleccione suna opcion: ";
}

void MenuDerivacion::ejecutar(){
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
				mostrarDerivaciones();
				break;
			case 2:
				calcularRutaConMenorTiempo();
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

void MenuDerivacion::mostrarDerivaciones(){
	sistema.mostrarDerivaciones();
}

void MenuDerivacion::calcularRutaConMenorTiempo(){
	string origen;
	string destino;

	cout<<"Ingrese el codigo del hospital de origen: ";
	getline(cin, origen);
	cout<<"Ingrese el codigo del hospital de destino: ";
	getline(cin, destino);

	sistema.calcularRutaDerivacion(origen, destino);
}


