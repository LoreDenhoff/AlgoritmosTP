#include <iostream>
#include <limits>
#include "MenuDerivacion.h"
using namespace std;

MenuDerivacion::MenuDerivacion(){}

void MenuDerivacion::mostrarMenu() const{
	cout<<"\n ======== MENU DERIVACION ======="<<endl;
	cout<<"1. Registrar derivacion"<<endl;
	cout<<"2. Calcular tiempo"<<endl;
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
