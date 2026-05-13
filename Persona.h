#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona{
    private:
        string nombre;
        string apellido;
    public:
        Persona(string _nombre, string _apellido){
            nombre= _nombre;
            apellido= _apellido;
        };
        virtual ~Persona(){};
        virtual void mostrarInfo()=0;
        string getNombre();
        string getApellido();
};

#endif