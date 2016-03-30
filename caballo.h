#pragma once 
#include "pieza.h"
#include "posicion.h"

class Caballo: public Pieza{
	public:
		Caballo(char color, int x , int y);
		virtual bool movimientoValido(Pieza*** ,Posicion );
		virtual string toString()const;

};