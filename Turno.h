#ifndef TURNO_H
#define TURNO_H
#include "Fecha.h"
#include "PersonalMedico.h"

class Turno{
    private:
        int turnoID;
        Fecha fechaTurno;
        int duracion;

        PersonalMedico* medico;

    public:
        Turno(int turnoID, Fecha fechaTurno, int duracion);
        Fecha getFechaTurno() const;
        int getDuracion() const;
        void asignarMedico(PersonalMedico* unMedico);
        string getMedico() const;
        
};
#endif


