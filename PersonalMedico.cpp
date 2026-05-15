#include "PersonalMedico.h"
#include "Persona.h"

PersonalMedico::PersonalMedico(string nombre, string apellido, int medicoID):Persona(nombre, apellido){
    this->medicoID= medicoID;
};

int PersonalMedico::getMedicoID(){
    return medicoID;
};