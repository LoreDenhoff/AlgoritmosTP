#include <iostream>
#include <limits>
#include "MenuTurno.h"
using namespace std;

MenuTurno::MenuTurno(
	GestorTurnos& gestorTurnos, 
	GestorPacientes& gestorPacientes, 
	GestorHospitales& gestorHospitales,
	GestorPersonalMedico& gestorPersonalMedico,
	GestorEspecialidades& gestorEspecialidades) : gestorTurnos(gestorTurnos), 
	gestorPacientes(gestorPacientes), 
	gestorHospitales(gestorHospitales),
	gestorPersonalMedico (gestorPersonalMedico),
	gestorEspecialidades (gestorEspecialidades){}

void MenuTurno::mostrarMenu() const{
	cout<<"\n ======== MENU TURNO ======="<<endl;
	cout<<"1. Registrar turno"<<endl;
	cout<<"2. Listar turno de un medico"<<endl;
	cout<<"3. Buscar turnos de un paciente por DNI"<<endl;
	cout<<"0. Volver al menu principal"<<endl;
	cout<<"Seleccione suna opcion: ";
}

int MenuTurno::leerEntero(string mensaje) const{
	int valor;
	cout<<mensaje;
	while(!(cin>>valor)){
		cout<<"Entrada invalida. Elija una opcion: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return valor;
}

string MenuTurno:: leerTexto(string mensaje) const{
	string texto;
	cout<<mensaje;
	getline(cin, texto);
	return texto;
}

Fecha MenuTurno::leerFecha(string mensaje) const{
	int dia;
	int mes;
	int anio;
	cout<<mensaje<<endl;
	
	dia=leerEntero("Dia: ");
	mes=leerEntero("Mes: ");
	anio=leerEntero("Anio: ");
	return Fecha(dia, mes, anio);
}

int MenuTurno::leerIdValido(string mensaje, string tipo) const{
	int id;
	while(true){
		id=leerEntero(mensaje);
		if(tipo=="paciente"){
			Paciente* paciente=gestorPacientes.buscarPacientePorId(id);
			if(paciente!=NULL){
				return id;
			}
			cout<<"Paciente no encontrado. Intente nuevamente"<<endl;
		}
	/*	if(tipo=="medico"){
			PersonalMedico* medico=gestorMedicos.buscarMedicoPorId(id);
			if(medico!=NULL){
				return id;
			}
			cout<<"Medico no encontrado. Intente nuevamente"<<endl;
		}*/
	}
}

void MenuTurno::mostrarHospitalesDisponibles() const{
	vector<Hospital> hospitales=gestorHospitales.obtenerTodosLosHospitales();
	if(hospitales.empty()){
		cout<<"No hay hospitales cargados en el sistema"<<endl;
		return;
	}
	cout<<"\n Hospitales disponibles"<<endl;
	for(size_t i=0; i<hospitales.size(); i++){
		cout<<hospitales[i].getHospitalId()
			<<" - "
			<<hospitales[i].getNombre()
			<<endl;
	}
}

string MenuTurno::leerCodigoHospitalValido() const{
	char respuesta;
	cout<<"Desea ver los hospitales disponibles? (s/n): ";
	cin>>respuesta;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	if(respuesta=='s' || respuesta=='S'){
		mostrarHospitalesDisponibles();
	}
	string codigoHospital;
	while(true){
		codigoHospital=leerTexto("Codigo del hospital: ");
		Hospital* hospital=gestorHospitales.buscarHospital(codigoHospital);
		if(hospital != NULL){
			return codigoHospital;
		}
		
		cout<<"Codigo invalido. Intente de nuevo"<<endl;
	}
}

void MenuTurno::mostrarEspecialidadesDisponibles() const{
	vector<Especialidad> especialidades=gestorEspecialidades.obtenerTodas();
	if(especialidades.empty()){
		cout<<"No hay especialidades cargdas en el sistema"<<endl;
		return;
	}
	cout<<"\nEspecialidades disponibles:"<<endl;
	for(size_t i=0; i<especialidades.size(); i++){
		cout<<especialidades[i].getEspecialidadId()
			<<" - "
			<<especialidades[i].getEspecialidadNombre()
			<<endl;
	}
}

int MenuTurno::leerEspecialidadValida() const{
	char respuesta;
	cout<<"Desea ver las especialidades disponibles? (s/n): ";
	cin>>respuesta;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if(respuesta=='s'||respuesta=='S'){
		mostrarEspecialidadesDisponibles();
	}
	int especialidadId;
	while(true){
		especialidadId=leerEntero("Id de la especialidad: ");
		vector<Especialidad> especialidades=gestorEspecialidades.obtenerTodas();
		for(size_t i=0; i<especialidades.size(); i++){
			if(especialidades[i].getEspecialidadId()==especialidadId){
				return especialidadId;
			}
		}
		cout<<"Especialidad Invalida. Intente nuevamente"<<endl;
	}
}

string MenuTurno::obtenerNombreEspecialidad(int especialidadId) const{
	vector<Especialidad> especialidades=gestorEspecialidades.obtenerTodas();
	for(size_t i=0; i<especialidades.size(); i++){
		if(especialidades[i].getEspecialidadId()==especialidadId){
			return especialidades[i].getEspecialidadNombre();
		}
	}
	return "sin especialidad";
}

void MenuTurno::mostrarMedicosPorEspecialidad(int especialidadId) const{
	vector<PersonalMedico> medicos=gestorPersonalMedico.buscarMedicosPorEspecialidad(especialidadId);
	if(medicos.empty()){
		cout<<"No hay medicos cargados para esa especialidad"<<endl;
		return;
	}
	cout<<"\n Medicos disponibles para la especialidad: "<<endl;
	for(size_t i=0; i<medicos.size(); i++){
		cout<<medicos[i].getMedicoId()
			<<" - "
			<<medicos[i].getNombre()
			<<" "
			<<medicos[i].getApellido()
			<<endl;
	}
}

int MenuTurno::leerMedicoPorEspecialidad(int especialidadId) const{
	vector<PersonalMedico> medicos=gestorPersonalMedico.buscarMedicosPorEspecialidad(especialidadId);
	if(medicos.empty()){
		cout<<"No hay medicos disponibles para esa especialidad"<<endl;
		return -1;
	}
	mostrarMedicosPorEspecialidad(especialidadId);
	int medicoId;
	while(true){
		medicoId=leerEntero("Id del medico: ");
		if(gestorPersonalMedico.medicoTieneEspecialidad(medicoId, especialidadId)){
			return medicoId;
		}
		cout<<"El medico ingresado no corresponde a esa especialidad. Intente de nuevo"<<endl;
	}
}

void MenuTurno::registrarTurno(){ 
	cout << "\n ======== REGISTRAR TURNO ========" << endl;
	string codigoHospital = leerCodigoHospitalValido();
	int turnoID = leerEntero("Id del turno: ");
	int pacienteID = leerIdValido("Id del paciente: ","paciente");
	int especialidadId=leerEspecialidadValida();
	int medicoId = leerMedicoPorEspecialidad(especialidadId);
	if(medicoId==-1){
		cout<<"No se puede registrar el turno no hay medicos para esa especialidad"<<endl;
		return;
	}
	string especialidad=obtenerNombreEspecialidad(especialidadId);
	Fecha fechaTurno=leerFecha("Fecha: ");
	int duracion = leerEntero("Duracion del turno en minutos: ");
	Turno turno(codigoHospital, turnoID, pacienteID, medicoId, fechaTurno, especialidad, duracion);
	gestorTurnos.agregarTurno(turno); 
	gestorTurnos.guardarTurnoEnArchivo("datos/turnos.txt", turno);
	cout<<"Turno registrado correctamente"<<endl;
}

void MenuTurno::listarTurnosMedico(){
	cout << "\n ======== TURNOS DE MEDICO ========" << endl;
	int medicoId=leerEntero("Ingrese ID del medico: " );
	vector<Turno> turnos=gestorTurnos.buscarTurnosPorMedicoId(medicoId);
	if(turnos.empty()){
		cout<<"No se econtraron turnos"<<endl;
		return;
	}
	gestorTurnos.mostrarTurnos(turnos);
}

void MenuTurno::listarTurnosPacientePorDni(){
	cout << "\n ======== TURNO DE PACIENTE ========" << endl;
	int dni=leerEntero("Ingrese DNI del paciente: ");
	
	vector<Turno> turnos=gestorTurnos.buscarTurnosPorDni(dni, gestorPacientes);
	if(turnos.empty()){
		cout<<"No se encontraron turnos"<<endl;
		return;
	}
	gestorTurnos.mostrarTurnos(turnos);
}

void MenuTurno::ejecutar(){
	int opcion;
	do{
		mostrarMenu();
		while(!(cin>>opcion)){
			cout<<"Entrada invalida. Ingrese una opcion valida: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch(opcion){
			case 1: 
				registrarTurno();
				break;
			case 2:
				listarTurnosMedico();
				break;
			case 3:
				listarTurnosPacientePorDni();
				break;
			case 0:
				cout<<"Volviendo al menu principal..."<<endl;
				break;
			default:
				cout<<"Opcion invalida. Intente de nuevo"<<endl;
				break;
		}
	}
	while(opcion!=0);
}
