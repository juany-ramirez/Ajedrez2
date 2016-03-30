#pragma once
#include "torre.h"
#include "pieza.h"
#include "alfil.h"
#include "posicion.h"
#include <string>

using std::string;

class Reina: public Pieza{
  public: 
	Reina(char color, int x, int y);//constructor
	virtual bool movimientoValido(Pieza*** , Posicion);
	virtual bool movimientoHacia(Pieza*** , Posicion);
	virtual string toString()const;
};