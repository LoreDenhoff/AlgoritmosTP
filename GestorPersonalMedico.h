#ifndef GESTORPERSONALMEDICO_H
#define GESTORPERSONALMEDICO_H
#include <vector>
#include <string>
#include "PersonalMedico.h"
#include "TablaHashIndices.h"
using namespace std;

class GestorPersonalMedico{
	private:
		vector<PersonalMedico> medicos;
		TablaHashIndices indicePorMedico;
		TablaHashIndices indicePorEspecialidad;
		vector<int> convertirEspecialidadTexto(string texto) const;
		
	public:
		GestorPersonalMedico();
		
		void agregarMedico(PersonalMedico medico);
		void cargarMedicosDesdeArchivo(string nombreArchivo);
		PersonalMedico* buscarMedicoPorId(int medicoId);
		vector<PersonalMedico> buscarMedicosPorEspecialidad(int especialidadId) const;
		vector<PersonalMedico> obtenerTodosLosMedicos() const;
		bool existeMedico(int medicoId);
		bool medicoTieneEspecialidad(int medicoId, int especialidad);
};

#endif

