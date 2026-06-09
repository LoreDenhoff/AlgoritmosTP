#ifndef AUXILIARES_H
#define AUXILIARES_H
#include <string>
#include "Fecha.h"
using namespace std;

Fecha convertirTextoAFecha( string textoAFecha);
int leerEntero(string mensaje);
float leerFloat(string mensaje);
string leerTexto(string mensaje);
int leerOpcion();
Fecha leerFecha(string mensaje);

#endif
