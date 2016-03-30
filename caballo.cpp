#include <string>
#include <iostream>
#include <sstream>
#include "caballo.h"
#include "pieza.h" 

using namespace std;

Caballo::Caballo(char color, int x , int y):Pieza(color, x, y){
}//constructor
bool Caballo::movimientoValido(Pieza*** tablero, Posicion direccion){
	if (posicion.getX()+2 == direccion.getX() && posicion.getY()+1 == direccion.getY() && (tablero[direccion.getY()][direccion.getX()] == NULL|| tablero[direccion.getY()][direccion.getX()]->getColor() != color))//x+2, y+1
		return true;
	else if(posicion.getX()+2 == direccion.getX() && posicion.getY()-1 == direccion.getY() && (tablero[direccion.getY()][direccion.getX()] == NULL|| tablero[direccion.getY()][direccion.getX()]->getColor() != color))//x+2, y-1
		return true;
	else if(posicion.getX()-2 == direccion.getX() && posicion.getY()+1 == direccion.getY() && (tablero[direccion.getY()][direccion.getX()] == NULL|| tablero[direccion.getY()][direccion.getX()]->getColor() != color))//x-2, y+1
		return true;
	else if(posicion.getX()-2 == direccion.getX() && posicion.getY()-1 == direccion.getY() && (tablero[direccion.getY()][direccion.getX()] == NULL|| tablero[direccion.getY()][direccion.getX()]->getColor() != color))//x-2, y-1
		return true;
	else if(posicion.getX()+1 == direccion.getX() && posicion.getY()+2 == direccion.getY() && (tablero[direccion.getY()][direccion.getX()] == NULL|| tablero[direccion.getY()][direccion.getX()]->getColor() != color))//x+1 y+2
		return true;
	else if(posicion.getX()-1 == direccion.getX() && posicion.getY()+2 == direccion.getY() && (tablero[direccion.getY()][direccion.getX()] == NULL|| tablero[direccion.getY()][direccion.getX()]->getColor() != color))//x-1, y+2
		return true;
	else if(posicion.getX()+1 == direccion.getX() && posicion.getY()-2 == direccion.getY() && (tablero[direccion.getY()][direccion.getX()] == NULL|| tablero[direccion.getY()][direccion.getX()]->getColor() != color))//x+1 y-2
		return true;
	else if(posicion.getX()-1 == direccion.getX() && posicion.getY()-2 == direccion.getY() && (tablero[direccion.getY()][direccion.getX()] == NULL|| tablero[direccion.getY()][direccion.getX()]->getColor() != color))//x-1, y-2
		return true;
	else
		return false;
}//si el moviemiento es valido


string Caballo::toString()const{
	stringstream ss;
	if (color == 'N'){
		ss << "C";
	}
	else{
		ss << "c";
	}
	return ss.str();
}
