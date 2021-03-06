#pragma once

#include "pieza.h"
#include "posicion.h"
#include <string>

using std::string;

class Peon: public Pieza{
	bool firstMove;
  public: 
	Peon(char color, int x, int y);//constructor
	int diferenciasX(Posicion);
	int diferenciasY(Posicion);
	virtual bool movimientoValido(Pieza*** , Posicion );
	virtual string toString()const;
};
