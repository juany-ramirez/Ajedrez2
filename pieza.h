#pragma once
#include <string>
#include "posicion.h"

using namespace std;

class Pieza{
 protected:
	char color;
	Posicion posicion;
 public:
 	Pieza(char color = 'B', int x = 0, int y = 0);
	char getColor()const;
	Posicion getPosicion()const;
	void setColor(char);
	void setPosicion(Posicion);
	virtual bool movimientoValido(Pieza*** , Posicion )=0;
	virtual string toString()const;
};