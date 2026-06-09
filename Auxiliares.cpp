#include "Auxiliares.h"
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
using namespace std;

Fecha convertirTextoAFecha(string textoFecha){
    if(textoFecha.length() != 8) {
        return Fecha();
    }

    int anio= atoi(textoFecha.substr(0,4).c_str());
    int mes= atoi(textoFecha.substr(4,2).c_str());
    int dia= atoi(textoFecha.substr(6,2).c_str());
    return Fecha(dia, mes, anio);   
}

int leerEntero(string mensaje){
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

float leerFloat(string mensaje){
	float valor;
	cout<<mensaje;
	while(!(cin>>valor)){
		cout<<"Entrada invalida. Elija una opcion: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return valor;
}

string leerTexto(string mensaje){
	string texto;
	cout<<mensaje;
	getline(cin, texto);
	return texto;
}

int leerOpcion(){
	int opcion;
	while(!(cin>>opcion)){
		cout<< "Entrada invalida. Ingrese unaopcion: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return opcion;
}

Fecha leerFecha(string mensaje){
	int dia;
	int mes;
	int anio;
	cout<<mensaje<<endl;
	
	dia=leerEntero("Dia: ");
	mes=leerEntero("Mes: ");
	anio=leerEntero("Anio: ");
	return Fecha(dia, mes, anio);
}
