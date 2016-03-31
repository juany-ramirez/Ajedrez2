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
	Alfil alfilValido();
	Torre torreValido();
	virtual bool movimientoValido(Pieza*** , Posicion);
	virtual string toString()const;
};