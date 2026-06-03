#include "OrdenadorHospitales.h"
#include<iostream>
using namespace std;


void OrdenadorHospitales::ordenar(vector<Hospital> & hospitales, int criterio){
	if(hospitales.size()>1){
		mergeSort(hospitales, 0, hospitales.size()-1, criterio);
	}
}

void OrdenadorHospitales::mergeSort(vector<Hospital> & hospitales, int inicio, int fin, int criterio){
	if(inicio<fin){
		int medio=inicio+(fin-inicio)/2;
		
		mergeSort(hospitales, inicio, medio, criterio);
		mergeSort(hospitales, medio +1, fin, criterio);
		merge(hospitales, inicio, medio, fin, criterio);
	}
}

void OrdenadorHospitales::merge(vector<Hospital> & hospitales, int inicio, int medio, int fin, int criterio){
	vector<Hospital> izquierda;
	vector<Hospital> derecha;
	
	for(int i=inicio; i<=medio; i++){
		izquierda.push_back(hospitales[i]);
	}
	for(int i=medio+1; i<=fin; i++){
		derecha.push_back(hospitales[i]);
	}
	int i=0;
	int j=0;
	int k=inicio;
	
	while(i<izquierda.size() && j<derecha.size()){
		bool ordenado=false;
		
		switch(criterio){
			case 1:
				ordenado=izquierda[i].getCapacidadCamas() <= derecha[j].getCapacidadCamas();
				break;
			case 2:
				ordenado=izquierda[i].getPersonalMedico() <= derecha[j].getPersonalMedico();
				break;	
			case 3:
				ordenado=izquierda[i].getPresupuestoAnual() <= derecha[j].getPresupuestoAnual();
				break;
			default:
				cout<<"Opcion invalida"<<endl;
				return;
		}
	if(ordenado){
		hospitales[k]=izquierda[i];
		i++;
	}
	else{
		hospitales[k]=derecha[j];
		j++;
	}
	k++;
	}
	while(i<izquierda.size()){
		hospitales[k]=izquierda[i];
		i++;
		k++;
	}
	while(i<derecha.size()){
		hospitales[k]=izquierda[j];
		j++;
		k++;
	}
}
