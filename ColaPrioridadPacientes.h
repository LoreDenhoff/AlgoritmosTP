#ifndef COLAPRIORIDADPACIENTES_H
#define COLAPRIORIDADPACIENTES_H

#include <vector>
#include "Paciente.h"
#include "Fecha.h"
using namespace std;

struct NodoEspera{
    Paciente paciente;
    Fecha fechaIngreso;
    NodoEspera(Paciente paciente, Fecha fechaIngreso);
};

class ColaPrioridadPacientes{
    private:
        vector<NodoEspera> heap;
        int padre(int indice) const;
        int hijoIzquierdo(int indice) const;
        int hijoDerecho(int indice) const;
        bool mismaFecha(const Fecha& f1, const Fecha& f2) const;
        bool fechaMasAntigua(const Fecha& f1, const Fecha& f2) const;
        bool tieneMayorPrioridad(const NodoEspera& a, const NodoEspera& b) const;
        void intercambiar(int i, int j);
        void subir(int indice);
        void bajar(int indice);
        int buscarIndicePorDni(int dni) const;

    public:
        ColaPrioridadPacientes();
        void insertar(Paciente paciente, Fecha fechaIngreso);
        bool extraerMasPrioritario(Paciente& pacienteExtraido);
        bool actualizarPrioridad(int dni, int nuevaPrioridad);
        bool estaVacio() const;
        int cantidad() const;
        void mostrarListaDeEspera() const;
};

#endif