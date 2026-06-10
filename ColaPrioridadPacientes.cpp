#include "ColaPrioridadPacientes.h"
#include <iostream>

using namespace std;

NodoEspera::NodoEspera(Paciente pacienteRecibido, Fecha fechaIngresoRecibida) 
 : paciente(pacienteRecibido), fechaIngreso(fechaIngresoRecibida) {}

ColaPrioridadPacientes::ColaPrioridadPacientes() {};

int ColaPrioridadPacientes::padre(int indice) const{
    return (indice - 1) / 2;
};

int ColaPrioridadPacientes::hijoIzquierdo(int indice) const{
    return 2 * indice + 1;
};

int ColaPrioridadPacientes::hijoDerecho(int indice) const{
    return 2 * indice + 2;
};

bool ColaPrioridadPacientes::mismaFecha(const Fecha &f1, const Fecha &f2) const{
    return f1.getDia() == f2.getDia() && f1.getMes() == f2.getMes() && f1.getAnio() == f2.getAnio();
};

bool ColaPrioridadPacientes::fechaMasAntigua(const Fecha &f1, const Fecha &f2) const {
    return f1.menorIgualQue(f2) && !mismaFecha(f1, f2);
};

bool ColaPrioridadPacientes::tieneMayorPrioridad(const NodoEspera &a, const NodoEspera &b) const {
    int prioridadA= static_cast<int>(a.paciente.getPrioridad());
    int prioridadB= static_cast<int>(b.paciente.getPrioridad());

    if(prioridadA < prioridadB){
        return true;
    }
    if(prioridadA > prioridadB){
        return false;
    }

    //si tienen la misma prioridad se fija la fecha mas antigua
    if(fechaMasAntigua(a.fechaIngreso, b.fechaIngreso)){
        return true;
    }
    if(fechaMasAntigua(b.fechaIngreso, a.fechaIngreso)){
        return false;
    }
    
    return a.paciente.getDni() < b.paciente.getDni();
};

void ColaPrioridadPacientes::intercambiar(int i, int j) {
    NodoEspera aux= heap[i];
    heap[i]=heap[j];
    heap[j]=aux;
};

void ColaPrioridadPacientes::subir(int indice) {
    while(indice > 0 && tieneMayorPrioridad(heap[indice], heap[padre(indice)])) {
        intercambiar(indice, padre(indice));
        indice= padre(indice);
    }
};

void ColaPrioridadPacientes::bajar(int indice) {
    int tamanio= heap.size();

    while(true){
        int izq= hijoIzquierdo(indice);
        int der= hijoDerecho(indice);
        int menor= indice;

        if(izq < tamanio && tieneMayorPrioridad(heap[izq], heap[menor])){
            menor= izq;
        }

        if(der < tamanio && tieneMayorPrioridad(heap[der], heap[menor])){
            menor= der;
        }

        if(menor==indice){
            break;
        }

        intercambiar(indice, menor);
        indice= menor;
    }
};

int ColaPrioridadPacientes::buscarIndicePorDni(int dni) const {
    for(size_t i=0;i<heap.size();i++){
        if(heap[i].paciente.getDni() == dni){
            return i;
        }
    }
    return -1;
};

void ColaPrioridadPacientes::insertar(Paciente paciente, Fecha fechaIngreso){
    NodoEspera nuevoNodo(paciente, fechaIngreso);
    heap.push_back(nuevoNodo);
    subir(heap.size() -1);
};

bool ColaPrioridadPacientes::extraerMasPrioritario(Paciente& pacienteExtraido){
    if(heap.empty()){
        return false;
    }

    pacienteExtraido= heap[0].paciente;

    heap[0]= heap[heap.size()-1];
    heap.pop_back();

    if(!heap.empty()){
        bajar(0);
    }
    return true;
};

bool ColaPrioridadPacientes::actualizarPrioridad(int dni, int nuevaPrioridad){
    int indice= buscarIndicePorDni(dni);

    if(indice==-1){
        return false;
    }

    int prioridadAnterior= static_cast<int>(heap[indice].paciente.getPrioridad());

    heap[indice].paciente.setPrioridad(nuevaPrioridad);

    if(nuevaPrioridad < prioridadAnterior){
        subir(indice);
    }else{
        bajar(indice);
    }
    return true;
};

bool ColaPrioridadPacientes::estaVacio() const{
    return heap.empty();
};

int ColaPrioridadPacientes::cantidad() const{
    return heap.size();
};

void ColaPrioridadPacientes::mostrarListaDeEspera() const{
    if(heap.empty()){
        cout << "La lista de espera esta vacia" << endl;
        return;
    }

    cout << "\n============ LISTA DE ESPERA ============" << endl;

    for(size_t i= 0; i< heap.size();i++){
        cout << "\nPrioridad: " << static_cast<int>(heap[i].paciente.getPrioridad()) << endl;
        cout << "Fecha de ingreso: "
             << heap[i].fechaIngreso.getDia() << "/"
             << heap[i].fechaIngreso.getMes() << "/"
             << heap[i].fechaIngreso.getAnio() << endl;

        heap[i].paciente.mostrarInfo();
    }
    cout << "------------------------------------" << endl;
};
