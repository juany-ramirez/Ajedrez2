# include "posicion.h"
# include <sstream>
# include <string>

using namespace std;
using std::stringstream;
using std::string;

Posicion::Posicion(int x,int y){
	if((x>=0&&x<=7) && (y>=0&&y<=7)){ //validacion out of bounds
		this->x = x;
		this->y = y;
	}
}

string Posicion::toString()const{
	stringstream str;
	str << "("<<x<<","<<y<<")";
}

const Posicion& Posicion::operator=(const Posicion&pos){ //sobrecarga de operador de asignacion
	this->x = pos.getX();
	this->y = pos.getY();
}

const int Posicion::getX()const{
	return x;
}

const int Posicion::getY()const{
	return y;
}

int	Posicion::setX(int x){
	if((x>=0&&x<=7)){ //validacion out of bounds
		this->x = x;
	}
}

int Posicion::setY(int y){
	if((y>=0&&y<=7)){ //validacion out of bounds
		this->y = y;
	}
}