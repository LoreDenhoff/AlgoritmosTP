#ifndef TABLAHASHHOSPITALES_H
#define TABLAHASHHOSPITALES_H
#include "Hospital.h"
#include <vector>
#include <iostream>
using namespace std;

class TablaHashHospitales{
    private:
        vector<vector<Hospital*> > tablaHash;
        int capacidadTabla;
        int cantHospitales;

        int funcionHash(string codigo) const;

    public:
        TablaHashHospitales(int capacidadTabla);
        void agregarHospital(Hospital* hospital);
        void eliminarHospital(string codigo);
        Hospital* buscarHospital(string codigo);
        void mostrarHospital(string codigo) const;
        vector<Hospital> obtenerTodosLosHospitales() const;
        double factorCarga() const;
};

#endif 
