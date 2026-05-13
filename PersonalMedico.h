#ifndef PERSONALMEDICO_H
#define PERSONALMEDICO_H
#include "Persona.h"

using namespace std;

class PersonalMedico: public Persona{
    private:
        int medicoID;

        public:
        PersonalMedico(string _nombre, string _apellido, int _medicoID);
        int getMedicoID();
};


#endif