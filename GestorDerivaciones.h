#ifndef GESTORDERIVACIONES_H
#define GESTORDERIVACIONES_H

#include <string>
#include <vector>
using namespace std;

struct AristaDerivacion{
    int destino;
    int tiempoMinutos;

    AristaDerivacion(int destino, int tiempoMinutos){
        this->destino= destino;
        this->tiempoMinutos= tiempoMinutos;

    }
};

struct RutaDerivacion{
    bool existe;
    int tiempoTotalMinutos;
    vector<string> recorrido;

    RutaDerivacion(){
        existe= false;
        tiempoTotalMinutos= 0;
    }
};

class GestorDerivaciones{
    private:
        vector<string> hospitales;
        vector<vector<AristaDerivacion>> adyacencias;

        int buscarIndiceHospital(string codigo) const;
        int agregarHospitalSiNoExiste(string codigo);
        int obtenerNoVistoConMenorDistancia(vector<int> distancias, vector<bool> vistos) const;
        vector<string> reconstruirRuta(vector<int> padres,int indiceOrigen, int indiceDestino) const;
        string convertirMinutosAHora(int minutosTotales) const;

    public:
        GestorDerivaciones();

        void cargarDerivacionesDesdeArchivo(string nombreArchivo);
        void agregarDerivacion(string origen, string destino, int tiempoMinutos);
        void mostrarDerivaciones() const;

        RutaDerivacion calcularRutaConMenorTiempo(string origen, string destino) const;
        void mostrarRutaConMenorTiempo(string origen, string destino) const;
};
#endif