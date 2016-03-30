#pragma once 
#include "pieza.h"
#include "posicion.h"

class Rey: public Pieza{
	public:
		Rey(char color, int x , int y);
		virtual bool movimientoValido(Pieza*** , Posicion );
		virtual string toString()const;

};