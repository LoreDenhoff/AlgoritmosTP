#include "GestorDerivaciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<cstdlib>
using namespace std;


GestorDerivaciones::GestorDerivaciones(){};
int GestorDerivaciones::buscarIndiceHospital(string codigo) const{
    for(size_t i= 0; i<hospitales.size();i++){
        if(hospitales[i]==codigo){
            return i;
        }
    }
    return -1;
};

int GestorDerivaciones::agregarHospitalSiNoExiste(string codigo){
    int indice= buscarIndiceHospital(codigo);

    if(indice!=-1){
        return indice;
    }

    hospitales.push_back(codigo);
    adyacencias.push_back(vector<AristaDerivacion>());
    return hospitales.size()-1;
};

void GestorDerivaciones::agregarDerivacion(string origen, string destino, int tiempoMinutos){
    if(origen.empty() || destino.empty()){
        return;
    }
    if(tiempoMinutos<=0){
        return;
    }

    int indiceOrigen= agregarHospitalSiNoExiste(origen);
    int indiceDestino= agregarHospitalSiNoExiste(destino);

    adyacencias[indiceOrigen].push_back(AristaDerivacion(indiceDestino, tiempoMinutos));
};

void GestorDerivaciones::cargarDerivacionesDesdeArchivo(string nombreArchivo){
    ifstream archivo(nombreArchivo.c_str());
    if(!archivo.is_open()){
        cout<< "No se pudo abrir el archivo"<<endl;
        return;
    }
    string linea;

    while(getline(archivo, linea)){
		if(linea.empty()){
			continue;
		}
		if(linea.find("hospital") != string::npos){
			continue;
		}

        stringstream ss(linea);

        string origen;
        string destino;
        string tiempoTexto;

        getline(ss, origen, ';');
        getline(ss, destino, ';');
        getline(ss, tiempoTexto, ';');

        int tiempoMinutos= atoi(tiempoTexto.c_str());
        agregarDerivacion(origen, destino,tiempoMinutos);
    }
    archivo.close();
    cout<< "Derivaciones cargadas correctamente"<<endl;
};

void GestorDerivaciones::mostrarDerivaciones() const{
    if(hospitales.empty()){
        cout<< "No hay derivaciones cargadas"<<endl;
        return;
    }
    for(size_t i=0; i<hospitales.size();i++){
        cout<<hospitales[i]<<": ";

        for(size_t j=0;j<adyacencias[i].size();j++){
            int indiceDestino= adyacencias[i][j].destino;
            int tiempo= adyacencias[i][j].tiempoMinutos;

            cout<<" -> "<<hospitales[indiceDestino];
            cout<<"("<<tiempo<<" min)";
        }
        cout<<endl;
    }
};

int GestorDerivaciones::obtenerNoVistoConMenorDistancia(vector<int> distancias, vector<bool> vistos) const{
    int indiceMenor= -1;
    int menorDistancia=999999;

    for(size_t i=0;i<distancias.size();i++){
        if(!vistos[i] && distancias[i]<menorDistancia){
            menorDistancia= distancias[i];
            indiceMenor= i;
        }
    }
    return indiceMenor;

};

vector<string> GestorDerivaciones::reconstruirRuta(vector<int> padres, int indiceOrigen, int indiceDestino) const{
    vector<string> rutaInvertida;
    vector<string> ruta;

    if(indiceOrigen<0 || indiceDestino<0){
        return ruta;
    }

    if(indiceOrigen>=(int)hospitales.size() || indiceDestino>=(int)hospitales.size()){
        return ruta;
    }

    int actual= indiceDestino;

    while(actual != -1){
        if(actual<0 || actual >= (int)hospitales.size()){
            return vector<string>();
        }

        rutaInvertida.push_back(hospitales[actual]);

        if(actual=indiceOrigen){
            break;
        }

        if(actual>=(int)padres.size()){
            return vector<string>();
        }
        actual= padres[actual];
    }
	
    if(rutaInvertida.empty()){
        return ruta;
    }

    if(rutaInvertida[rutaInvertida.size() - 1] != hospitales[indiceOrigen]){
        return ruta;
    } 

    for(int i=(int)rutaInvertida.size() - 1;i>=0;i--){
        ruta.push_back(rutaInvertida[i]);
    }

    return ruta;
};

RutaDerivacion GestorDerivaciones::calcularRutaConMenorTiempo(string origen, string destino) const{
    RutaDerivacion resultado;

    int indiceOrigen= buscarIndiceHospital(origen);
    int indiceDestino= buscarIndiceHospital(destino);

    if(indiceOrigen==-1 || indiceDestino==-1){
        return resultado;
    }

    int cantidad= hospitales.size();
    int infinito= 999999;

    vector<int> distancias(cantidad, infinito);
    vector<bool> vistos(cantidad, false);
    vector<int> padres(cantidad, -1);

    distancias[indiceOrigen]=0;

    for(int i=0; i<cantidad; i++){
		int actual=obtenerNoVistoConMenorDistancia(distancias, vistos);

		if(actual==-1){
			break;
		}

        if(actual<0 || actual>cantidad){
            break;
        }

        if(distancias[actual]==infinito){
            break;
        }

		vistos[actual]=true;

		if(actual==indiceDestino){
			break;
		}

		for(size_t j=0; j<adyacencias[actual].size(); j++){
			int vecino=adyacencias[actual][j].destino;
			int peso=adyacencias[actual][j].tiempoMinutos;

            if(vecino<0 || vecino>=cantidad){
                continue;
            }
            
			if(!vistos[vecino] && distancias[actual]+peso<distancias[vecino]){
				distancias[vecino]=distancias[actual]+peso;
				padres[vecino]=actual;
			}
		}
	}

	if(distancias[indiceDestino]==infinito){
		return resultado;
	}

	resultado.existe=true;
	resultado.tiempoTotalMinutos=distancias[indiceDestino];
	resultado.recorrido=reconstruirRuta(padres, indiceOrigen, indiceDestino);

	return resultado;
};


string GestorDerivaciones::convertirMinutosAHora(int minutosTotales) const{
	int horas=minutosTotales/60;
	int minutos=minutosTotales%60;

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

void GestorDerivaciones::mostrarRutaConMenorTiempo(string origen, string destino) const{
	RutaDerivacion ruta=calcularRutaConMenorTiempo(origen, destino);

	if(!ruta.existe){
		cout<<"No existe una ruta de derivacion entre "<<origen<<" y "<<destino<<endl;
		return;
	}

	cout<<"Ruta de menor tiempo: ";

	for(size_t i=0; i<ruta.recorrido.size(); i++){
		cout<<ruta.recorrido[i];

		if(i<ruta.recorrido.size()-1){
			cout<<" -> ";
		}
	}

	cout<<endl;
	cout<<"Tiempo total: "<<ruta.tiempoTotalMinutos<<" minutos";
	cout<<" ("<<convertirMinutosAHora(ruta.tiempoTotalMinutos)<<" hs)"<<endl;    
};