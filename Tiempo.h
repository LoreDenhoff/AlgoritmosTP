#ifndef TIEMPO_H
#define TIEMPO_H
#include <string>
using namespace std;

class Tiempo{
    private:
        int horas;
        int minutos;
        void normalizar();

    public:
        Tiempo();
        Tiempo(int horas, int minutos);
        Tiempo(string textoTiempo);

        int getHoras() const;
        int getMinutos() const;

        int aMinutosTotales() const;
        string aTexto() const;

        bool esMenorQue(const Tiempo& otroTiempo) const;
        bool esMayorQue(const Tiempo& otroTiempo) const;
        bool esIgualQue(const Tiempo& otroTiempo) const;
        Tiempo sumar(const Tiempo& otroTiempo) const;

        static Tiempo desdeMinutosTotales(int minutosTotales);
        static Tiempo infinito();
};

#endif