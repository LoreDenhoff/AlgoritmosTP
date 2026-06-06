#ifndef NODOHOSPITAL_H
#define NODOHOSPITAL_H
#include "Hospital.h"

class NodoHospital{
	private:
		Hospital hospital;
		NodoHospital* izquierda;
		NodoHospital* derecha;
		
	public:
		NodoHospital(const Hospital& hospital);
		Hospital& getHospital();
		const Hospital& getHospital() const;
		NodoHospital* getIzquierda() const;
		NodoHospital* getDerecha() const;
		void setIzquierda(NodoHospital* izquierda);
		void setDerecha(NodoHospital* derecha);	
};
#endif
