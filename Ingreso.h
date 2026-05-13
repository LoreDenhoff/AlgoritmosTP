#ifndef INGRESO_H
#define INGRESO_H

#include <iostream>
#include <vector>

using namespace std;

class Ingreso {
    private:
        int ingresoID;
        string fechaIngreso; //// HAY QUE CAMBIAR ESTO compa
        string fechaAlta;

    public:
        Ingreso(int _ingresoID, string _fecha, string _descripcion);
        int getIngresoID();
        string getFechaIngresoDerivacion();
        string getFechaAltaDerivacion();
};

#endif