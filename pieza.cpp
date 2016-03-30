#include <string>
#include "posicion.h"
#include "pieza.h"

using namespace std;

Pieza::Pieza(char color, int x, int y){
	this->color = color;
	this->posicion = Posicion(x,y);
}
char Pieza::getColor()const{
	return color;
}
Posicion Pieza::getPosicion()const{
	return posicion;
}
void Pieza::setColor(char color){
	this->color = color;
}
void Pieza::setPosicion(Posicion posicion){
	this->posicion = posicion;
}
string Pieza::toString()const{
	string retval = "";
	return retval;
}