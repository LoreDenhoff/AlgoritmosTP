#include <iostream>
#include <vector>
#include "Hospital.h"
#include "Paciente.h"
#include "Ingreso.h"
#include "Fecha.h"
using namespace std;

int main() {
    // Crear fechas
    Fecha f1(10, 3, 2025);
    Fecha f2(15, 3, 2025);

    // Crear ingreso
    Ingreso ingreso1(1, f1);

    // Crear paciente
    Paciente p("Juan", "Pérez", 1001, 30123456, 72.5, 2);

    // Agregar ingreso al paciente
    p.agregarIngreso(ingreso1);

    // Probar getters
    cout << "Paciente ID: " << p.getPacienteID() << endl;
    cout << "DNI: " << p.getDni() << endl;
    cout << "Peso: " << p.getPesoKg() << " kg" << endl;

    /* Mostrar ingresos
    for (const auto& ingre : p.getIngresos()) {
        cout << "Ingreso ID: " << ingre.getIngresoID() << endl;
        cout << "Fecha ingreso: " 
             << ingre.getFechaIngresoDerivacion().getDia() << "/"
             << ingre.getFechaIngresoDerivacion().getMes() << "/"
             << ingre.getFechaIngresoDerivacion().getAnio() << endl;
    }*/


    return 0;
}

