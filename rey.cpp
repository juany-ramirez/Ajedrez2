#include "pieza.h"
#include "posicion.h"
#include "rey.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::stringstream;


Rey::Rey(char color, int x , int y):Pieza(color,x,y){

}
bool Rey::movimientoValido(Pieza*** tablero, Posicion direccion){

	int diferenciaV, diferenciaH;

	if(this->getColor()=='B'){
		//Verifica que no sean del mismo color
		if (tablero[direccion.getY()][direccion.getX()]==NULL || tablero[direccion.getY()][direccion.getX()]->getColor()=='N'){

			//Busca la diferencia Vertical
			if (direccion.getY()>this->posicion.getY()){
				diferenciaV = direccion.getY() - this->posicion.getY();
			}else if(direccion.getY()<this->posicion.getY()){
				diferenciaV = this->posicion.getY()-direccion.getY();
			}
			//Busca la diferencia Horizontal
			if (direccion.getX()>this->posicion.getX()){
				diferenciaH = direccion.getX() - this->posicion.getX();
			}else if(direccion.getX()<this->posicion.getX()){
				diferenciaH = this->posicion.getX()-direccion.getX();
			}

			//Si la diferencia de las posiciones es mayor a 1
			if(diferenciaH==1 || diferenciaV==1){
				return true;
			}else{
				return false;
			}

			

		}else if (tablero[direccion.getY()][direccion.getX()]->getColor()=='B'){
			return false;	
		}
	}else{
		if (tablero[direccion.getY()][direccion.getX()]==NULL || tablero[direccion.getY()][direccion.getX()]->getColor()=='B'){
			//Busca la diferencia Vertical
			if (direccion.getY()>this->posicion.getY()){
				diferenciaV = direccion.getY() - this->posicion.getY();
			}else if(direccion.getY()<this->posicion.getY()){
				diferenciaV = this->posicion.getY()-direccion.getY();
			}
			//Busca la diferencia Horizontal
			if (direccion.getX()>this->posicion.getX()){
				diferenciaH = direccion.getX() - this->posicion.getX();
			}else if(direccion.getX()<this->posicion.getX()){
				diferenciaH = this->posicion.getX()-direccion.getX();
			}

			//Si la diferencia de las posiciones es mayor a 1
			if(diferenciaH==1 || diferenciaV==1){
				return true;
			}else{
				return false;
			}
		} else	{
			return false;	
		}


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
