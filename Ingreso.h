#ifndef INGRESO_H
#define INGRESO_H

#include <iostream>
#include <vector>
#include "Fecha.h"

using namespace std;

class Ingreso {
    private:
        int ingresoID;
        Fecha fechaIngreso; 
        Fecha fechaAlta;
        string descripcion;

    public:
        Ingreso(int ingresoID, Fecha fecha);
        int getIngresoID() const;
        //fecha alta
        Fecha getFechaIngresoDerivacion() const;
        Fecha getFechaAltaDerivacion() const;
};

#endif