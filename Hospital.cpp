#include "Hospital.h"

Hospital::Hospital(){
	hospitalId="";
	nombre="";
	ciudad="";
	capacidadCamas=0;
	personalMedico=0;
	presupuestoAnual=0;
}

Hospital::Hospital(string hospitalId, string nombre, string ciudad, int capacidadCamas,	int personalMedico, int presupuestoAnual, vector<Especialidad> especialidades
)
