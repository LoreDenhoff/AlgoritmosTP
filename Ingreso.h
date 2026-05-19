#ifndef INGRESO_H
#define INGRESO_H

#include <string>
#include"Fecha.h"

using namespace std;

class Ingreso {
    private:
        int ingresoId;
        Fecha fechaIngreso; 
        Fecha fechaAlta;
        bool tieneFechaAlta; //revisar
        string descripcion;

    public:
        Ingreso(int ingresoId, Fecha fechaIngreso);
        int getIngresoId() const;
        Fecha getFechaIngresoDerivacion() const;
        bool getTieneFechaAlta() const;
        string getDescripcion() const;
        Fecha getFechaAltaDerivacion() const;
        
        void setFechaAlta(Fecha fechaAlta);
        void setDescripcion(string descripcion);
};

#endif
