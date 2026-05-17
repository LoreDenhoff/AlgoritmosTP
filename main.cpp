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
    Ingreso ingreso1(1, f1, "	ll");

    // Crear paciente
    Paciente p("Juan", "Pérez", 1001, 30123456, 72.5, 2);

    // Agregar ingreso al paciente
    p.agregarIngreso(ingreso1);

    // Probar getters
    cout << "Paciente ID: " << p.getPacienteID() << endl;
    cout << "DNI: " << p.getDni() << endl;
    cout << "Peso: " << p.getPesoKg() << " kg" << endl;

    // Mostrar ingresos
    for (const auto& ing : p.getIngresos()) {
        cout << "Ingreso ID: " << ing.getIngresoID() << endl;
        cout << "Fecha ingreso: " 
             << ing.getFechaIngresoDerivacion().getDia() << "/"
             << ing.getFechaIngresoDerivacion().getMes() << "/"
             << ing.getFechaIngresoDerivacion().getAnio() << endl;
    }


    return 0;
}

