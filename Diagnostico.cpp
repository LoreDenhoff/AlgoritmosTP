#include "Diagnostico.h"

Diagnostico::Diagnostico(string nombre, int frecuencia){
    this->nombre= nombre;
    this->frecuencia= frecuencia;
};
string Diagnostico::getDiagnosticoNombre() const{
    return this->nombre;
};
int Diagnostico::getDiagnosticoFrecuencia() const{
    return this->frecuencia;
};