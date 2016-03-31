#include "pieza.h"
#include "posicion.h"
#include "rey.h"
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::stringstream;
using std::string;

Rey::Rey(char color, int x , int y):Pieza(color,x,y){}

bool Rey::movimientoValido(Pieza*** tablero, Posicion direccion){
	int diferenciaV, diferenciaH;
	char actual, opuesto;
	if(this->getColor()=='B'){
		actual='B';
		opuesto='N';
	}else{
		actual='N';
		opuesto='B';
	}

	if (tablero[direccion.getY()][direccion.getX()]==NULL || tablero[direccion.getY()][direccion.getX()]->getColor()==opuesto){
		if((direccion.getY()==this->posicion.getY()-1) && (direccion.getX()==this->posicion.getX()-1)){
			return true;
		}else if((this->posicion.getX()==direccion.getX()) && (direccion.getY()==this->posicion.getY()-1)){
			return true;
		}else if((direccion.getY()==this->posicion.getY()-1) && (direccion.getX()==this->posicion.getX()+1)){
			return true;
		}else if((this->posicion.getY()==direccion.getY()) && (direccion.getX()==this->posicion.getX()-1)){
			return true;
		}else if((this->posicion.getY()==direccion.getY()) && (direccion.getX()==this->posicion.getX()+1)){
			return true;
		}else if((direccion.getY()==this->posicion.getY()+1) && (direccion.getX()==this->posicion.getX()-1)){
			return true;
		}else if((direccion.getY()==this->posicion.getY()+1) && (direccion.getX()==this->posicion.getX())){
			return true;
		}else if((direccion.getY()==this->posicion.getY()+1) && (direccion.getX()==this->posicion.getX()+1)){
			return true;
		}		
	}else if (tablero[direccion.getY()][direccion.getX()]->getColor()==actual){
		return false;	
	}
}

string Rey::toString()const{
	stringstream ss;
	if (color == 'N'){
		ss << "R";
	}
	else{
		ss << "r";
	}
	return ss.str();
}
