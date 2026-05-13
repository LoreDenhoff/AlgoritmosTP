#ifndef PACIENTE_H
#define PACIENTE_H

#include "Prioridad.h"
#include "Persona.h"
#include "Ingreso.h"

using namespace std;

class Paciente: public Persona{
    private:
        int pacienteID;
        int dni;
        float pesoKg;
        Prioridad prioridad;
        vector<Ingreso> ingresos;

        public:
        Paciente(string _nombre, string _apellido, int _pacienteID, int _dni, 
            float _pesoKg, int _prioridad);
        int getPacienteID();
        int getDni();
        float getPesoKg();
        int getPrioridad();
        void agregarIngreso(const Ingreso& nuevoIngreso);
        vector<Ingreso> getIngresos();
};


#endif