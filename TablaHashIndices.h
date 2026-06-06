#ifndef TABLAHASHINDICE_H
#define TABLAHASHINDICE_H
#include <vector>
using namespace std;

class EntradaIndice{
	public:
		int clave;
		vector<int> valores;
		EntradaIndice(int clave);
};

class TablaHashIndices{
	private:
		vector<vector<EntradaIndice> > tabla;
		int capacidad;
		int funcionHash(int clave)const;
	
	public:
		TablaHashIndices(int capacidad);
		void insertar(int clave, int valor);
		bool buscar(int clave, vector<int>& resultado) const;
};
#endif
