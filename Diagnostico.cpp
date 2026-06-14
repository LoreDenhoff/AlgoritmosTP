#include "Diagnostico.h"
#include <iostream>
using namespace std;

Diagnostico::Diagnostico(){
	this->diagnosticoId=0;
	this->nombre="";
	this->frecuencia=0;
}

Diagnostico::Diagnostico(int diagnosticoId, string nombre, int frecuencia){
	this->diagnosticoId=diagnosticoId;
    this->nombre= nombre;
    this->frecuencia= frecuencia;
};

int Diagnostico::getDiagnosticoId() const{
	return diagnosticoId;
}
string Diagnostico::getDiagnosticoNombre() const{
    return nombre;
};
int Diagnostico::getDiagnosticoFrecuencia() const{
    return frecuencia;
};

void Diagnostico::setDiagnosticoFrecuencia(int frecuencia){
	this->frecuencia=frecuencia;
}

void Diagnostico::incrementarFrecuencia(){
	this->frecuencia++;
}

void Diagnostico::mostrarInformacion() const{
	cout<<"ID: "<<diagnosticoId<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Frecuencia: "<<frecuencia<<endl;
}
