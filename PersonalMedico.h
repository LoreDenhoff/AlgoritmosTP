#ifndef PERSONALMEDICO_H
#define PERSONALMEDICO_H
#include "Persona.h"

using namespace std;

class PersonalMedico: public Persona{
    private:
        int medicoID;

        public:
        PersonalMedico(string nombre, string apellido, int medicoID);
        int getMedicoID();
};


#endif