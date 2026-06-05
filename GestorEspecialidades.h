#ifndef GESTORESPECIALIDADES_H
#define GESTORESPECIALIDADES_H
#include <vector>
#include <string>
#include "Especialidad.h"
using namespace std;

class GestorEspecialidades{
	private:
		vector<Especialidad> especialidades;
		
	public:
		GestorEspecialidades();
		
		void cargarEspecialidadDesdeArchivo(string nombreArchivo);
		Especialidad buscarEspecialidadPorId(int id) const;
		vector<Especialidad> obtenerTodas() const;
		void mostrarEspecialidades() const;
};
#endif

