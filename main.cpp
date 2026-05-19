#include <iostream>
#include <vector>
#include <stdexcept>
#include "Hospital.h"
#include "Paciente.h"
#include "Ingreso.h"
#include "Fecha.h"
#include "Especialidad.h"

using namespace std;

int main() {
    try{
    	cout<<"========= PRUEBA DE FECHAS==========="<<endl;
    	Fecha f1(10,3,2025);
    	Fecha f2(15,3,2025);
    	cout<<"fecha 1"
    		<<f1.getDia()<<"/"
    		<<f1.getMes()<<"/"
    		<<f1.getAnio()<<endl;
			cout<<"fecha 2"
    		<<f2.getDia()<<"/"
    		<<f2.getMes()<<"/"
    		<<f2.getAnio()<<endl;
		
		if(f1.menorIgualQue(f2)){
			cout<<"fecha 1 es menor"<<endl;
		}
		if(f2.mayorIgualQue(f1)){
			cout<<"fecha 2 es menor"<<endl;
		}
		
		cout<<"========= PRUEBA DE INGRESO==========="<<endl;
		Ingreso ingreso1(1,f1);
		ingreso1.setDescripcion("Ingreso por guardia");
		ingreso1.setFechaAlta(f2);
		
		cout<<"Ingreso id: "<<ingreso1.getIngresoId()<<endl;
		
		cout<<"Fecha ingreso "
			<<ingreso1.getFechaIngresoDerivacion().getDia()<<"/"	
			<<ingreso1.getFechaIngresoDerivacion().getMes()<<"/"	
			<<ingreso1.getFechaIngresoDerivacion().getAnio()<<endl;
			
		cout<<"Tiene fecha de alta "
			<<ingreso1.getTieneFechaAlta()<<endl;
			
		cout<<"Fecha alta "
			<<ingreso1.getFechaAltaDerivacion().getDia()<<"/"	
			<<ingreso1.getFechaAltaDerivacion().getMes()<<"/"	
			<<ingreso1.getFechaAltaDerivacion().getAnio()<<endl;
			
		cout<<"Descripcion "<<ingreso1.getDescripcion()<<endl;
		cout<<endl;
		
		cout<<"========= PRUEBA DE INGRESO==========="<<endl;
		Paciente p("Juan", "Perez", 1001, 30123456,72.5,2);
		
		p.agregarIngreso(ingreso1);
		
		cout<<"Paciente id: "<<p.getPacienteID()<<endl;
		cout<<"Nombre: "<<p.getNombre()<<endl;
		cout<<"Apellido: "<<p.getApellido()<<endl;
		cout<<"DNI : "<<p.getDni()<<endl;
		cout<<"Peso: "<<p.getPesoKg()<<endl;
		cout<<"Prioridad: "<<p.getPrioridad()<<endl;
		cout<<endl;
		
		cout<<"Ingreso del paciente"<<endl;
		vector<Ingreso> ingresosPaciente=p.getIngresos();
		for(int i=0; i<ingresosPaciente.size(); i++){
			cout<<"Ingreso id: "<<ingresosPaciente[i].getIngresoId()<<endl;
		cout<<"Fecha ingreso "
			<<ingresosPaciente[i].getFechaIngresoDerivacion().getDia()<<"/"	
			<<ingresosPaciente[i].getFechaIngresoDerivacion().getMes()<<"/"	
			<<ingresosPaciente[i].getFechaIngresoDerivacion().getAnio()<<endl;	
		
		cout<<"Descripcion: "<<ingresosPaciente[i].getDescripcion()<<endl;
		}
		cout<<endl;
		
		cout<<"========= PRUEBA DE ESPECIALIDAD==========="<<endl;
		Especialidad e1(1, "Cardiologia");
		Especialidad e2(2, "Traumatoligia");
		
		vector<Especialidad> especialidades;
		especialidades.push_back(e1);
		especialidades.push_back(e2);
		
		cout<<"Especialidad 1: "<<e1.getEspecialidadNombre()<<endl;
		cout<<"Especialidad 1: "<<e2.getEspecialidadNombre()<<endl;
		cout<<endl;
		
		cout<<"========= PRUEBA DE HOSPITAL==========="<<endl;
		Hospital hospital1("H001", "hOSPITAL CENTRAL", "Hurlingham", 2, 10, 5000000, especialidades);
		hospital1.mostrarInformacion();
		cout<<endl;
		
		cout<<"El hospital ofrece Cardiologia?"<<endl;
		if(hospital1.ofreceEspecialidad("Cardiologia")){
			cout<<"Si"<<endl;
		}else{
			cout<<"No"<<endl;
		}
		cout<<endl;
		
		
		cout<<"Ingresando paciente"<<endl;
		hospital1.ingresarPaciente(p, ingreso1);
		cout<<endl;
		
		hospital1.mostrarInformacion();
		cout<<endl;
		
		
		
		
		
	}catch(invalid_argument& error){
		cout<<"error"<<error.what()<<endl;
	}
	
	


    return 0;
}

