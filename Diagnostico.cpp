#include "Diagnostico.h"

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
