#include "PersonalMedico.h"
#include "Persona.h"
#include <iostream>
using namespace std;

PersonalMedico::PersonalMedico(string nombre, string apellido, int medicoId,int especialidadId):
    Persona(nombre, apellido),medicoId(medicoId),especialidadId(especialidadId){};
    //esta forma de crear el constructor es mas limpia, no hace falta usar el this-> para cada atributo 
    //y ademas se llama al constructor de la clase base (Persona) para inicializar los atributos heredados (nombre y apellido).
    // HABRIA QUE VER SI CONVIENE HACER TODOS ASI(PERO TRANKI)

void PersonalMedico::mostrarInfo(){ //este hay que hacerlo para que PERSONA sea abstracta, esta en paciente tambien
    cout << "Nombre: " << getNombre() << endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "Medico ID: " << medicoId << endl;
    cout << "Especialidad ID: " << especialidadId << endl;
};
int PersonalMedico::getMedicoId() const{
    return medicoId;
};
int PersonalMedico::getEspecialidadId() const{
    return especialidadId;
};
