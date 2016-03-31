#include "pieza.h" 
#include "reina.h"
#include "alfil.h"
#include "torre.h" 
#include <string> 
#include <iostream>
#include <sstream>

using std::string;
using namespace std;
using std::stringstream;

Reina::Reina(char color, int x, int y):Pieza(color, x, y){}

bool Reina::movimientoValido(Pieza*** tablero, Posicion direccion){
	Alfil a=alfilValido();
	Torre t=torreValido();
	if (t.movimientoValido(tablero, direccion)||a.movimientoValido(tablero, direccion))
		return true;
	else
		return false;
}

Alfil Reina::alfilValido(){//laa reina tiene los movimientos del alfil
	Alfil alfil(this->color,this->posicion.getX(),this->posicion.getY());
	return alfil;
}

Torre Reina::torreValido(){//la reina tiene los movimientos de la torre
	Torre torre(this->color,this->posicion.getX(),this->posicion.getY());
	return torre;
}

string Reina::toString()const{
	stringstream ss;
	if (color == 'N'){
		ss << "Q";
	}
	else{
		ss << "q";
	}
	return ss.str();
}
