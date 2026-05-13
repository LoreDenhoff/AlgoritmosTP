#include "PersonalMedico.h"
#include "Persona.h"

PersonalMedico::PersonalMedico(string _nombre, string _apellido, int _medicoID):Persona(_nombre, _apellido){
    medicoID= _medicoID;
};

int PersonalMedico::getMedicoID(){
    return medicoID;
};