#ifndef PERSONALMEDICO_H
#define PERSONALMEDICO_H
//#include <vector>
#include "Persona.h"
#include "Especialidad.h"

using namespace std;

class PersonalMedico: public Persona{
    private:
        int medicoId;
        int especialidadId; //podria ser un vector? vector<Especialidad> especialidad;
    //x si tienen muchas especialidades?
        public:
        PersonalMedico(string nombre, string apellido, int medicoId, int especialidadId);
        void mostrarInfo();
        int getMedicoId() const;
        int getEspecialidadId() const; //CAMBIE de tipo especialidad a int IDpara evitar dependencia
};//antes la ver especialidad era de tipo ESPECIALIDAD -> despues string (XD) -> creo que conviene conectar todo con id


#endif
