#include "peon.h"
#include "pieza.h"
#include "posicion.h"
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

Peon::Peon(char color, int x, int y):Pieza(color,x,y){//constructor
	firstMove = true;
}
bool Peon::movimientoValido(Pieza*** tablero, Posicion direccion){
	int diffY = abs(posicion.getY()-direccion.getY());
	if(color == 'N'){
		int diffX = posicion.getX()-direccion.getX();
		if((diffY==1&&diffX==0) || (diffY==2&&firstMove&&diffX==0)){ //primer movimiento o movimiento hacia adelante
			if(tablero[direccion.getY()][direccion.getX()] == NULL)
				return true;
			return false;
		}
		else if((diffY==1&&diffX==1)){
			if(tablero[direccion.getY()][direccion.getX()]->getColor() != color) //comer en diagonal
				return true;
			return false;
		}
		else{
			return false;
		}
	} else if(color == 'B'){
		int diffX = direccion.getX()-posicion.getX();
		if((diffY==1&&diffX==0) || (diffY==2&&firstMove&&diffX==0)){ //primer movimiento o movimiento hacia adelante
			if(tablero[direccion.getY()][direccion.getX()] == NULL)
				return true;
			return false;
		}
		else if((diffY==1&&diffX==1)){
			if(tablero[direccion.getY()][direccion.getX()]->getColor() != color) //comer en diagonal
				return true;
			return false;
		}
		else{
			return false;
		}
	}
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
