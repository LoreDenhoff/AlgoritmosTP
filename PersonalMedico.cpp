#include "PersonalMedico.h"
#include "Persona.h"
#include <iostream>
using namespace std;

PersonalMedico::PersonalMedico(): Persona("",""){this->medicoId=0;}

PersonalMedico::PersonalMedico(string nombre, string apellido, int medicoId, vector<int> especialidadIds):
    Persona(nombre, apellido){
    	this->medicoId=medicoId;
    	this->especialidadIds=especialidadIds;
	}
	
void PersonalMedico::mostrarInfo() const{
	cout<<"ID medico: "<<medicoId<<endl;
	cout<<"Nombre: "<<getNombre()<<endl;
	cout<<"Apellido: "<<getApellido()<<endl;
	cout<<"Especialidades ID:  ";
	
	for(size_t i=0; i<especialidadIds.size(); i++){
		cout<<especialidadIds[i];
		if(i<especialidadIds.size()-1){
			cout<<", ";
		}
	}
	cout<<endl;
}

int PersonalMedico::getMedicoId() const{
	return medicoId;
}

vector<int> PersonalMedico::getEspecialidadesIds() const{
	return especialidadIds;
}

bool PersonalMedico::tieneEspecialidad(int especialidadId) const{
	for(size_t i=0; i<especialidadIds.size(); i++){
		if(especialidadIds[i]==especialidadId){
			return true;
		}
	}
	return false;
}




















