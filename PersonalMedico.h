#ifndef PERSONALMEDICO_H
#define PERSONALMEDICO_H
#include <vector>
#include "Persona.h"
using namespace std;

class PersonalMedico: public Persona{
	private:
		int medicoId;
		vector<int> especialidadIds;
		
	public:
		PersonalMedico();
		PersonalMedico(string nombre, string apellido, int medicoId, vector<int> especialidadIds);
		void mostrarInfo() const;
		int getMedicoId() const;
		vector<int> getEspecialidadesIds() const;
		bool tieneEspecialidad(int especialidadId) const;
};

#endif
