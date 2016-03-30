#include "pieza.h" 
#include "torre.h" 
#include <string> 
#include <iostream>
#include <sstream>

using namespace std;

Torre::Torre(char color, int x, int y):Pieza(color, x, y){
}
bool Torre::movimientoValido(Pieza*** tablero, Posicion direccion){
	if (((posicion.getX() == direccion.getX()) && (posicion.getY() != direccion.getY()))){ //si se mueve verticalmente
		if(posicion.getY() < direccion.getY()){ //si se mueve hacia abajo
			for (int row = posicion.getY()+1; row < direccion.getY(); ++row){
				if (tablero[row][posicion.getX()] != NULL){//si se encuentra una pieza entre origin y direccion
					return false;
				}
			}
			if (tablero[direccion.getY()][posicion.getX()] == NULL || tablero[direccion.getY()][posicion.getX()]->getColor() != color){
				//si direccion est vacio o tiene una pieza enemiga
				return true;
			}
			else {
				return false;
			}
		}
		else if(posicion.getY() > direccion.getY()){//si se mueve hacia arriba
			for (int row = posicion.getY()-1; row > direccion.getY(); --row){
				if (tablero[row][posicion.getX()] != NULL){
					return false;
				}
			}
			if (tablero[direccion.getY()][posicion.getX()] == NULL || tablero[direccion.getY()][posicion.getX()]->getColor() != color){
				//SI direccion ESTA VACIO O TIENE UNA PIEZA ENEMIGA
				return true;
			}
			else {
				return false;
			}
		}
	}
	else if (((posicion.getX() != direccion.getX()) && (posicion.getY() == direccion.getY()))){//si se mueve horizontalmente
		if(posicion.getX() < direccion.getX()){ //si se mueve hacia la derecha
			for (int cols = posicion.getX()+1; cols < direccion.getX(); ++cols){
				if (tablero[posicion.getY()][cols] != NULL){//si se encuentra una pieza entre origin y direccion
					return false;
				}
			}
			if (tablero[direccion.getY()][direccion.getX()] == NULL || tablero[direccion.getY()][direccion.getX()]->getColor() != color){
				//si direccion est vacio o tiene una pieza enemiga
				return true;
			}
			else {
				return false;
			}
		}
		else if(posicion.getX() > direccion.getX()){ //si se mueve hacia la izquierda
			for (int cols = posicion.getX()-1; cols > direccion.getX(); --cols){
				if (tablero[posicion.getY()][cols] != NULL){//si se encuentra una pieza entre origin y direccion
					return false;
				}
			}
			if (tablero[direccion.getY()][direccion.getX()] == NULL || tablero[direccion.getY()][direccion.getX()]->getColor() != color){
				//si direccion est vacio o tiene una pieza enemiga
				return true;
			}
			else {
				return false;
			}
		}
	}
}

string Torre::toString()const{
	stringstream ss;
	if (color == 'N'){
		ss << "T";
	}
	else{
		ss << "t";
	}
	return ss.str();
}