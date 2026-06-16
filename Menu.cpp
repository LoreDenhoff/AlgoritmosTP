#include "Menu.h"
#include "Hospital.h"
#include "Paciente.h"
#include "Ingreso.h"
#include "Especialidad.h"
#include "Fecha.h"
#include "MenuDerivacion.h"
#include <limits>
#include <iostream>
#include <stdexcept>
using namespace std;

Menu::Menu():sistema(10){
	//carga de datos
	vector<Especialidad> especialidades=sistema.cargarEspecialidadesDesdeArchivo("datos/especialidades.txt");
	sistema.cargarHospitalesDesdeArchivo("datos/hospitales.txt", especialidades);
	sistema.cargarDerivacionesDesdeArchivo("datos/derivaciones.txt");
}

void Menu::mostrarMenu() const{
	cout<<"        ----------------------        "<<endl;
	cout<<"=======| SISTEMA HOSPITALARIO |======="<<endl;
	cout<<"        ----------------------        "<<endl;
	
	cout<<"1. Registrar hospital"<<endl;
	cout<<"2. Listar hospitales"<<endl;
	cout<<"3. Buscar hospital"<<endl;
	cout<<"4. Eliminar hospital"<<endl;
	cout<<"5. Buscar hospital por especialidad"<<endl;
	cout<<"6. Ingresar paciente"<<endl;
	cout<<"7. Pacientes atendidos por rango"<<endl;
	cout<<"8. Mostrar factor de carga"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Seleccione una opcion: "<<endl;
	cout<<"\n";
}

int Menu::leerEntero(string mensaje) const{
	int valor;
	cout<<mensaje;
	
	while(!(cin>>valor)){
		cout<<"Entrada invalida. Ingrese un numero: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	return valor;
}

float Menu::leerFloat(string mensaje) const{
	float valor;
	cout<<mensaje;
	
	while(!(cin>>valor)){
		cout<<"Entrada invalida. Ingrese un numero: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	return valor;
}

string Menu::leerTexto(string mensaje) const{
	string texto;
	cout<<mensaje;
	getline(cin, texto);
	
	return texto;
}

Fecha Menu::leerFecha(string mensaje) const{
	int dia;
	int mes;
	int anio;
	cout<<mensaje<<endl;
	
	dia=leerEntero("Dia: ");
	mes=leerEntero("Mes: ");
	anio=leerEntero("Anio: ");
	
	return Fecha(dia, mes, anio);
}
//Se usa cuando registras un hospital nuevo
vector<Especialidad> Menu::cargarEspecialidadHospital() const{
	vector<Especialidad> especialidades;
	int cant=leerEntero("Cantidad de especialidades del hospital: ");
	
	for(int i=0; i<cant;i++){
		cout<<"\nEspecialidad "<<i+1<<endl;
		int id=leerEntero("Id de especialidad: ");
		string nombre=leerTexto("Nombre de la especialidad: ");
		
		Especialidad especialidad(id, nombre);
		especialidades.push_back(especialidad);
	}
	return especialidades;
}

void Menu::registrarHospital(){
	cout<<"\n ======Registrar Hospital ======"<<endl;
	
	string codigo=leerTexto("Codigo del hospital: ");
	string nombre=leerTexto("Nombre: ");
	string ciudad=leerTexto("Ciudad: ");
	int capacidad=leerEntero("Capacidad de camas: ");
	int personal=leerEntero("Cantidad de personal medico: ");
	int presupuesto=leerEntero("Presupuesto anual: ");
	
	vector<Especialidad> especialidades=cargarEspecialidadHospital();
	
	Hospital hospital(
		codigo,
		nombre,
		ciudad,
		capacidad,
		especialidades,
		personal,
		presupuesto
		
	);
	sistema.agregarHospital(hospital);
	sistema.guardarHospitalEnArchivo("datos/hospitales.txt", hospital);
	cout<<"Hospital registrado correctamente"<<endl;
}

void Menu::listarHospitales(){
	cout<<"\n ======Listado de Hospitales ======"<<endl;
	
	vector<Hospital> hospitales=sistema.obtenerTodosLosHospitales();
	if(hospitales.empty()){
		cout<<"No hay hospitales registrados"<<endl;
		return;
	}
	for(size_t i=0; i<hospitales.size();i++){
		cout<<"\nHospital " <<i+1<<endl;
		hospitales[i].mostrarInformacion(); 
	}
}

void Menu::buscarHospital(){
	cout<<"\n ======Buscar Hospital ======"<<endl;
	
	string codigo=leerTexto("Ingrese codigo del hospital: ");
	Hospital * hospital=sistema.buscarHospital(codigo);
	if(hospital==NULL){
		cout<<"Hospital no encontrado."<<endl;
		return;
	}
	hospital->mostrarInformacion();
}

void Menu::eliminarHospital(){
	cout<<"\n ======Eliminar Hospital ======"<<endl;
	
	string codigo=leerTexto("Ingrese codigo del hospital: ");
	sistema.eliminarHospital(codigo);
}

void Menu::buscarPorEspecialidad(){
	cout<<"\n ======Buscar por especialidad ======"<<endl;
	
	string especialidad=leerTexto("Ingrese nombre de especialidad: ");
	vector<Hospital> hospitales=sistema.buscarPorEspecialidad(especialidad);
	if(hospitales.empty()){
		cout<<"No se encontraron hospitales con esa especialidad"<<endl;
		return;
	}
	cout<<"\nHospitales encontrados: "<<endl;
	for(size_t i=0;i<hospitales.size();i++){
		cout<<"\nHospital "<<i+1<<endl;
		hospitales[i].mostrarInformacion();
	}
}

void Menu::ingresarPaciente(){ //DEBERIAMOS PASARLE UN HOSPITAL X PARAMETRO?
	cout << "\n === INGRESAR PACIENTE A HOSPITAL ===" << endl;
	string codigoHospital = leerTexto("Codigo del hospital: ");
	Hospital* hospital = sistema.buscarHospital(codigoHospital);

	if(hospital == NULL){
		cout <<"Hospital no encontrado." <<endl;
		return;
	}

	string nombre= leerTexto("Nombre del paciente: ");
	string apellido= leerTexto("Apellido del paciente: ");

	int pacienteID= leerEntero("ID del paciente: ");
	int dni= leerEntero("DNI: ");
	float peso= leerFloat("Peso: ");

	cout << "\nPrioridad: " << endl;
	cout << "1. Critico" << endl;
	cout << "2. Alto" << endl;
	cout << "3. Medio" << endl;
	cout << "4. Bajo" << endl;
	cout << "5. Leve" << endl;

	int prioridad= leerEntero("Ingrese prioridad: ");
	int ingresoID= leerEntero("ID  del ingreso: ");
	Fecha fechaIngreso= leerFecha("Fecha de ingrso: ");
	string descripcion= leerTexto("Descripcion del ingreso: "); 

	Paciente paciente(
		nombre,
		apellido,
		pacienteID,
		dni,
		peso,
		prioridad
	);

	Ingreso ingreso(ingresoID, fechaIngreso);
	ingreso.setDescripcion(descripcion);

	paciente.agregarIngreso(ingreso);
	hospital->ingresarPaciente(paciente, ingreso);

	cout << "Paciente ingresado correctamente." << endl;
}

void Menu::contarPacientesEnRango(){
	cout << "\n=== PACIENTES ATENDIDOS EN RANGO ===" << endl;

	string codigoHospital= leerTexto("Codigo del hospital: ");

	Hospital* hospital= sistema.buscarHospital(codigoHospital);
	if(hospital == NULL){
		cout << "Hospital  no encontrado." << endl;
		return;
	}

	Fecha desde = leerFecha("Fecha desde");
	Fecha hasta = leerFecha("Fecha hasta");

	int cantidad= hospital->pacientesAtendidosEnRango(desde, hasta);

	cout << "Pacientes atendidos en ese rango: " << cantidad << endl;

}

void Menu::mostrarFactorCarga(){
	cout << "\n === FACTOR DE CARGA ===" << endl;
	cout << "Factor de carga: " << sistema.factorCarga() << endl;
}
/*
void Menu::mostrarDerivacion(){
	cout<<"\n ====== DERIVACIONES CARGADAS ======"<<endl;
	sistema.mostrarDerivaciones();
}

void Menu::calcularRutaDerivacion(){
	cout<<"\n ====== RUTA DE DERIVACION DE MENOR TIEMPO ======"<<endl;

	string origen= leerTexto("Codigo del hospital origen: ");
	string destino= leerTexto("Codigo del hospital destino: ");

	sistema.calcularRutaDerivacion(origen, destino);
}*/

void Menu::ejecutar(){
	int opcion;

	do{
		try{
			mostrarMenu();
			while(!(cin >> opcion)){
				cout << "Entrada invalida. Ingrese una opcion numerica: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			switch(opcion){
				case 1:
					registrarHospital();
					break;
				case 2:
					listarHospitales();
					break;
				case 3:
					buscarHospital();
					break;
				case 4:
					eliminarHospital();
					break;
				case 5:
					buscarPorEspecialidad();
					break;
				case 6:
					ingresarPaciente();
					break;
				case 7:
					contarPacientesEnRango();
					break;
				case 8:
					mostrarFactorCarga();
					break;
				/*case 9:
					mostrarDerivacion();
					break;
				case 10:
					calcularRutaDerivacion();
					break;*/
				case 0:
					cout << "Saliendo del sistema..." << endl;
					break;
				default:
					cout << "Opcion invalida. Intente nuevamente." << endl;
					break;
				
			}
		}catch(invalid_argument& error){
			cout << "Error: " <<error.what() << endl;
		}
	}while(opcion != 0);
}









