#include "Ingreso.h"


Ingreso::Ingreso(int ingresoID, Fecha fecha){
    this->ingresoID= ingresoID;
    this->fechaIngreso= fecha;    
};

int Ingreso::getIngresoID() const{
    return ingresoID;
};

Fecha Ingreso::getFechaIngresoDerivacion() const{
    return fechaIngreso;
};

Fecha Ingreso:: getFechaAltaDerivacion() const{
    return fechaAlta;
};