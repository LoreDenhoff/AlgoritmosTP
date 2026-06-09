#ifndef GESTORPACIENTES_H
#define GESTORPACIENTES_H
#include <vector>
#include <string>
#include "Paciente.h"
#include "Fecha.h"
#include "GestorHospitales.h"

using namespace std;

class GestorPacientes {
    private:
        vector<Paciente> pacientes;
        
    public:
        GestorPacientes();

        void agregarPaciente(Paciente paciente);
        Paciente* buscarPacientePorId(int pacienteID);
        Paciente* buscarPacientePorDni(int dni);

        vector<Paciente> obtenerTodosLosPacientes() const;

        void cargarPacientesDesdeArchivo(string nombreArchivo, GestorHospitales & gestorHospitales);
        void mostrarTodosLosPacientes() const;
};

#endif 
