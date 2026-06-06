#include "TablaHashHospitales.h"
#include <iostream>
using namespace std;

TablaHashHospitales::TablaHashHospitales(int capacidadTabla){
	this->capacidadTabla=capacidadTabla;
	this->cantHospitales=0;
	tablaHash.resize(capacidadTabla);	
}

int TablaHashHospitales::funcionHash(string codigo) const{
    int suma = 0;
    for (size_t i = 0; i < codigo.length(); i++){
        suma += codigo[i] * (i + 1);
    }
    return suma % capacidadTabla;
}

void TablaHashHospitales::agregarHospital(Hospital* hospital){
	if(hospital==NULL){
		return;
	}
    int indiceHash = funcionHash(hospital->getHospitalId());

    for (size_t i = 0; i < tablaHash[indiceHash].size(); i++){
        if (tablaHash[indiceHash][i]->getHospitalId() == hospital->getHospitalId()){
            cout << "Hospital ya registrado" << endl;
            return;
        }
    }
    tablaHash[indiceHash].push_back(hospital);
    cantHospitales++;
}

// falta derivar a otro hospital
// LLEVARME
void TablaHashHospitales::eliminarHospital(string codigo){
    int indiceHash = funcionHash(codigo);

    for (size_t i = 0; i < tablaHash[indiceHash].size(); i++){
        if (tablaHash[indiceHash][i]->getHospitalId() == codigo){
            tablaHash[indiceHash].erase(tablaHash[indiceHash].begin() + i);
            cantHospitales--;
            cout << "Hospital eliminado correctamente" << endl;
            return;
        }
    }
}

Hospital* TablaHashHospitales::buscarHospital(string codigo){
    int indiceHash = funcionHash(codigo);

    for (size_t i = 0; i < tablaHash[indiceHash].size(); i++){
        if (tablaHash[indiceHash][i]->getHospitalId() == codigo){
            return tablaHash[indiceHash][i];
        }
    }
    return NULL;
}

void TablaHashHospitales::mostrarHospital(string codigo) const{
    int indiceHash = funcionHash(codigo);

    for (size_t i = 0; i < tablaHash[indiceHash].size(); i++){
        if (tablaHash[indiceHash][i]->getHospitalId() == codigo){
            tablaHash[indiceHash][i]->mostrarInformacion();
            return;
        }
    }
    cout << "Hospital no encontrado" << endl;
}

vector<Hospital> TablaHashHospitales::obtenerTodosLosHospitales() const{
    vector<Hospital> hospitales;

    for (size_t i = 0; i < tablaHash.size(); i++){
        for (size_t j = 0; j < tablaHash[i].size(); j++){
            hospitales.push_back(*(tablaHash[i][j]));
        }
    }
    return hospitales;
}

double TablaHashHospitales::factorCarga() const{
	if(capacidadTabla==0){
		return 0;
	}
    return (double)cantHospitales / capacidadTabla;
}
