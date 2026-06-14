#include <iostream>
#include <limits>
#include "MenuDiagnostico.h"
#include "Auxiliares.h"
using namespace std;

MenuDiagnostico::MenuDiagnostico(ArbolDiagnostico& arbolDiagnostico) : arbolDiagnostico(arbolDiagnostico){}

void MenuDiagnostico::mostrarMenu() const{
	cout<<"\n ======== MENU DIAGNOSTICO ======="<<endl;
	cout<<"1. Insertar nuevo diagnostico"<<endl;
	cout<<"2. Incrementar frecuencia por ID"<<endl;
	cout<<"3. Incrementar frecuencia por nombre"<<endl;
	cout<<"4. Listar diagnosticos en orden"<<endl;
	cout<<"5. Mostrar diagnostico mas frecuente"<<endl;
	cout<<"6. Eliminar diagnostico por ID"<<endl;
	cout<<"7. Calcular altura del arbol"<<endl;
	cout<<"8. Detectar si el arbol esta desbalanceado"<<endl;
	cout<<"0. Volver al menu principal"<<endl;
	cout<<"Seleccione una opcion: ";
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
			case 1:{
				int id=leerEntero("Ingrese ID del diagnostico: ");
				string nombre=leerTexto("Ingrese nombre del diagnostico: ");
				int frecuencia=leerEntero("Ingrese frecuencia inicial: ");
				Diagnostico diagnostico(id, nombre, frecuencia);
				arbolDiagnostico.insertar(diagnostico);
				cout<<"Diagnostico cargado correctamente"<<endl;
				break;
			}
			case 2:{
				int id=leerEntero("Ingrese ID del diagnostico: ");
				if(arbolDiagnostico.incrementarFrecuenciaPorId(id)){
					cout<<"Frecuencia incrementada correctamente"<<endl;
				}
				else{
					cout<<"No se encontro diagnostico con ese ID"<<endl;
				}
				break;
			}
			case 3:{
				string nombre=leerTexto("Ingrese nombre del diagnostico: ");
				if(arbolDiagnostico.incrementarFrecuenciaPorNombre(nombre)){
					cout<<"Frecuencia incrementada correctamente"<<endl;
				}
				else{
					cout<<"No se encontro un diagnostico con ese nombre"<<endl;
				}
				break;
			}
			case 4:{
				cout<<"\nDiagnosticos ordenados por frecuencia"<<endl;
				arbolDiagnostico.listarEnOrden();
				break;
			}
			case 5:{
				if(arbolDiagnostico.estaVacio()){
					cout<<"No hay diagnosticos cargados"<<endl;
				}
				else{
					Diagnostico masFrecuente=arbolDiagnostico.obtenerMasFrecuente();
					cout<<"\nDiagnostico mas frecuente: "<<endl;
					masFrecuente.mostrarInformacion();
				}
				break;
			}
			case 6:{
				int id= leerEntero("Ingrese ID del diagnostico a eliminar: ");
				if(arbolDiagnostico.eliminar(id)){
					cout<<"Diagnostico eliminado correctamente"<<endl;
				}
				else{
					cout<<"No se encontro un diagnostico con ese nombre"<<endl;
				}
				break;
			}
			case 7:{
				cout<<"Altura del arbol: "<<arbolDiagnostico.calcularAltura()<<endl;
				break;
			}
			case 8:{
				if(arbolDiagnostico.estaDesbalanceado()){
					cout<<"El arbol esta desbalanceado"<<endl;
				}
				else{
					cout<<"El arbol no esta desbalanceado"<<endl;
				}
				break;
			}
			case 0:{
				cout<<"Volviendo al menu principal..."<<endl;
				break;
			}
			default:{
				cout<<"Opcion invalida. Intente de nuevo"<<endl;
				break;
			}
				
		}
	}
	while(opcion!=0);
}
