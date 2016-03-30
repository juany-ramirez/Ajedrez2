#include "pieza.h" 
#include "reina.h" 
#include <string> 
#include <iostream>
#include <sstream>

using namespace std;

Reina::Reina(char color, int x, int y):Pieza(color, x, y){

}
bool Reina::movimientoValido(Pieza*** tablero, Posicion direccion){
	Alfil a(this->color,this->posicion.getX(),this->posicion.getY());
	Torre t(this->color,this->posicion.getX(),this->posicion.getY());
	if (t.movimientoValido(tablero, direccion)||a.movimientoValido(tablero, direccion))
		return true;
	else
		return false;
}
bool Reina::movimientoHacia(Pieza*** tablero, Posicion direccion){
	if(movimientoValido(tablero,direccion)){
		tablero[posicion.getY()][posicion.getX()] = NULL;
		posicion = direccion;
		tablero[posicion.getY()][posicion.getX()] = this;
		return true;
	}
	else{
		cout << "Movimiento Invalido" << endl;
		return false;
	}
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
