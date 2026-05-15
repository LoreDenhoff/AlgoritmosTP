#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include <string>

using namespace std;

class Diagnostico {
    private:
        string nombre;
        int frecuencia;

    public:
        Diagnostico(string nombre, int frecuencia);
        string getDiagnosticoNombre() const;
        int getDiagnosticoFrecuencia() const;
};

#endif
