#pragma once
#include "pieza.h"
#include "posicion.h"

class Alfil: public Pieza{
	public:
		Alfil(char,int,int);
		virtual bool movimientoValido(Pieza***, Posicion );
		virtual bool movimientoHacia(Pieza*** , Posicion );
		virtual string toString()const;

};
