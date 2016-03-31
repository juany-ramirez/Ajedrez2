#include "peon.h"
#include "pieza.h"
#include "posicion.h"
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;
using std::string;
using std::stringstream;


Peon::Peon(char color, int x, int y):Pieza(color,x,y){//constructor
	firstMove = true;
}

bool Peon::movimientoValido(Pieza*** tablero, Posicion direccion){
	int diferY = diferenciasY(direccion);
	int diferX = diferenciasX(direccion);
	char actual=this->getColor();

	if((diferX==0 && diferY==1) || (diferY==2 && firstMove && diferX==0)){ //primer movimiento o movimiento hacia adelante
		if(tablero[direccion.getY()][direccion.getX()] == NULL || tablero[direccion.getY()][direccion.getX()]->getColor() != actual)
			return true;
		return false;
	}else if((diferY==1 && diferX==1)){
		if(tablero[direccion.getY()][direccion.getX()]->getColor() != actual) //comer en diagonal
			return true;
		return false;
	}else{
		return false;
	}
	
}

int Peon::diferenciasX(Posicion direccion){
	int difer=abs(posicion.getX()-direccion.getX());
	return difer;
}

int Peon::diferenciasY(Posicion direccion){
	int difer=abs(posicion.getY()-direccion.getY());
	return difer;
}

string Peon::toString()const{
	stringstream ss;
	if (color == 'N'){
		ss << "P";
	}
	else{
		ss << "p";
	}
	return ss.str();
}
