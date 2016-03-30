#pragma once

#include "pieza.h"
#include "posicion.h"
#include <string>

using std::string;

class Torre: public Pieza{
  public: 
	Torre(char color, int x, int y);//constructor
	virtual bool movimientoValido(Pieza***, Posicion);
	virtual string toString()const;
};