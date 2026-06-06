#ifndef GESTORPACIENTES_H
#define GESTORPACIENTES_H
#include <vector>
#include <string>
#include "Paciente.h"
#include "Fecha.h"

using namespace std;

class GestorPacientes {
    private:
        vector<Paciente> pacientes;
        Fecha convertirTextoAFecha( string textoAFecha) const;

    public:
        GestorPacientes();

        void agregarPaciente(Paciente paciente);
        Paciente* buscarPacientePorId(int pacienteID);
        Paciente* buscarPacientePorDni(int dni);

        vector<Paciente> obtenerTodosLosPacientes() const;

        void cargarPacientesDesdeArchivo(string nombreArchivo);
        void mostrarTodosLosPacientes() const;
};

#endif 