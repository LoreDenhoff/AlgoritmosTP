#include <iostream>
#include <limits>
#include "MenuDiagnostico.h"
using namespace std;

MenuDiagnostico::MenuDiagnostico(vector<Diagnostico>& diagnosticosRegistrados) : diagnosticosRegistrados(diagnosticosRegistrados){}

void MenuDiagnostico::mostrarMenu() const{
	cout<<"\n ======== MENU DIAGNOSTICO ======="<<endl;
	cout<<"0. Volver al menu principal"<<endl;
	cout<<"Seleccione suna opcion: ";
}

void MenuDiagnostico::ejecutar(){
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
