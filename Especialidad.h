#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#include <string>

using namespace std;

class Especialidad {
    private:
        int especialidadId; //para las relaciones
        string nombre;

    public:
    	Especialidad();
        Especialidad(int especialidadesIds, string nombre);
        
        int getEspecialidadId() const;
        string getEspecialidadNombre() const;
        //void setNombre(string nombre);
};

#endif







