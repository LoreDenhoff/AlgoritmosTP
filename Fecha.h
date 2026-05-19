#ifndef FECHA_H
#define FECHA_H

class Fecha{
	private:
		int dia;
		int mes;
		int anio;
		
		//metodos en privado porque son internos de la clase para calcular si la fecha válida
		bool esBisiesto(int anio) const;
		int diasMes(int mes, int anio) const;
		bool fechaValida(int dia, int mes, int anio) const;
		
	public:
		Fecha();
		Fecha(int dia, int mes, int anio);
		
		int getDia() const;
		int getMes() const; 
		int getAnio() const;
		
		bool menorIgualQue(const Fecha& otraFecha) const;
		bool mayorIgualQue(const Fecha& otraFecha) const;
};

#endif
