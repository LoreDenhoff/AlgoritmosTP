#ifndef PACIENTE_H
#define PACIENTE_H

#include<vector>
#include<string>
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
        Paciente(string nombre, string apellido, int pacienteID, int dni, 
            float pesoKg, int prioridad);
        void mostrarInfo();
        int getPacienteID() const;
        int getDni() const;
        float getPesoKg() const;
        int getPrioridad() const;
        void agregarIngreso(const Ingreso& nuevoIngreso);
        vector<Ingreso> getIngresos() const;
};


#endif
