#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include <string>
using namespace std;

class Diagnostico {
    private:
        int diagnosticoId; 
        string nombre;
        int frecuencia;

    public:
    	Diagnostico();
        Diagnostico(int diagnosticoId, string nombre, int frecuencia);
        int getDiagnosticoId() const;
        string getDiagnosticoNombre() const;
        int getDiagnosticoFrecuencia() const;
        
        void setDiagnosticoFrecuencia(int frecuencia);
        void incrementarFrecuencia();
        void mostrarInformacion() const;
};

#endif
