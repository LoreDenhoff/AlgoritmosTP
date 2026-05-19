#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include <string>

using namespace std;

class Diagnostico {
    private:
        int diagnosticoId; //para las relaciones - despues vemos donde
        string nombre;
        int frecuencia;

    public:
        Diagnostico(int diagnosticoId, string nombre, int frecuencia);
        string getDiagnosticoNombre() const;
        int getDiagnosticoFrecuencia() const;
};

#endif
