#include "Tiempo.h"
#include <sstream>
#include <cstdlib>
using namespace std;

Tiempo::Tiempo(){
    horas= 0;
    minutos= 0;
};

Tiempo::Tiempo(int horas, int minutos){
    this->horas=horas;
    this->minutos=minutos;
    normalizar();
};

Tiempo::Tiempo(string textoTiempo){
    horas=0;
    minutos=0;

    size_t posicion= textoTiempo.find(":");

    if(posicion==string::npos){
        horas=0;
        minutos=atoi(textoTiempo.c_str());
        normalizar();
        return;
    }
    string horasTexto= textoTiempo.substr(0, posicion);
    string minutosTexto= textoTiempo.substr(0, posicion+1);

    horas= atoi(horasTexto.c_str());
    minutos= atoi(minutosTexto.c_str());

    normalizar();
};

void Tiempo::normalizar(){
    if(minutos>=60){
        horas+= minutos/60;
        minutos= minutos%60;
    }
    if(minutos<0){
        minutos= 0;
    }
    if(horas<0){
        horas= 0;
    }
}

int Tiempo::getHoras() const{
    return horas;
};

int Tiempo::getMinutos() const{
    return minutos;
};

int Tiempo::aMinutosTotales() const{
    return horas*60+minutos;
};

string Tiempo::aTexto() const{
    stringstream ss;

    if(horas<10){
        ss<<"0";
    }
    ss<<horas<<":";

    if(minutos<10){
        ss<<"0";
    }
    ss<<minutos;
    return ss.str();
};

bool Tiempo::esMenorQue(const Tiempo& otroTiempo) const{
    return aMinutosTotales()<otroTiempo.aMinutosTotales();
};

bool Tiempo::esMayorQue(const Tiempo& otroTiempo) const{
    return aMinutosTotales()>otroTiempo.aMinutosTotales();
};

bool Tiempo::esIgualQue(const Tiempo& otroTiempo) const{
    return aMinutosTotales()==otroTiempo.aMinutosTotales();
};

Tiempo Tiempo::sumar(const Tiempo& otroTiempo) const{
    int total= aMinutosTotales() + otroTiempo.aMinutosTotales();
    return Tiempo::desdeMinutosTotales(total);
};

Tiempo Tiempo::desdeMinutosTotales(int minutosTotales){
    int h= minutosTotales/60;
    int m= minutosTotales%60;
};

Tiempo Tiempo::infinito(){
    return Tiempo(9999, 59);
};