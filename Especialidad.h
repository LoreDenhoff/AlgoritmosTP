#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#include <string>

using namespace std;

class Especialidad {
    private:
        int especialidadID; //para las relaciones
        string nombre;

    public:
        Especialidad(string nombre);
        string getEspecialidadNombre() const;
        //void setNombre(string nombre);
};

#endif







