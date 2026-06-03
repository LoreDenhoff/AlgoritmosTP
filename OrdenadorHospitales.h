#ifndef ORDENADORHOSPITALES_H
#define ORDENADORHOSPITALES_H
#include <vector>
#include "Hospital.h"
using namespace std;

class OrdenadorHospitales{
	private:
		static void merge(vector<Hospital> & hospitales, int inicio, int medio, int fin, int criterio);
		static void mergeSort(vector<Hospital> & hospitales, int inicio, int fin,int criterio);
	
	public:
		static void ordenar(vector<Hospital> & hospitales, int criterio);
};

#endif
