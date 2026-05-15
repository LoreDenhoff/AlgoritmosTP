#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#include <string>

using namespace std;

class Especialidad {
    private:
        string nombre;

    public:
        Especialidad(string nombre);
        string getEspecialidadNombre() const;
        //void setNombre(string nombre);
};

#endif







