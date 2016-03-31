#include "alfil.h"
#include "pieza.h"
#include "posicion.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <string>

using std::stringstream;
using std::cout;
using std::string;

Alfil::Alfil(char color,int X,int Y):Pieza(color,X,Y){}

bool Alfil::movimientoValido(Pieza***tablero, Posicion direccion){
	int y,x;
	char actual=this->getColor();

	if ((this->posicion.getX()== direccion.getX()) || (this->posicion.getY()== direccion.getY())){
		//verifica que no se mueva a los lados ni verticalmente
		return false;
	}

	if (abs(this->posicion.getY()-direccion.getY())==abs(this->posicion.getX()-direccion.getX())){//verifica si se mueve en diagonal
			if(this->posicion.getY() > direccion.getY() && this->posicion.getX()>direccion.getX()){
				y=this->posicion.getY()-1;
				x=this->posicion.getX()-1;
				
				while(true){
					if (tablero[y][x] == NULL){
						y--;
						x--;

					} else if (tablero[y][x]!=NULL && tablero[y][x]->getColor()==actual
						){
						return false;
					}
					if(x == direccion.getX() || y==direccion.getY()){
						break;
					}
				}
				return true;

			}else if(this->posicion.getY() > direccion.getY() && this->posicion.getX()<direccion.getX()){	
				y=this->posicion.getY()-1;
				x=this->posicion.getX()+1;
			
				while(true){	
					if (tablero[y][x] == NULL){
						y--;
						x++;
					} else if (tablero[y][x]!=NULL && tablero[y][x]->getColor()==actual){
						return false;
					}
					if(x == direccion.getX() || y==direccion.getY()){
						break;
					}
				}

				return true;

			}else if(this->posicion.getY() < direccion.getY() && this->posicion.getX()>direccion.getX()){
				y=this->posicion.getY()+1;
				x=this->posicion.getX()-1;

				while(true){
					if (tablero[y][x] == NULL){
						y++;
						x--;
					} else if (tablero[y][x]!=NULL && tablero[y][x]->getColor()==actual){
						return false;
					}
					if(x == direccion.getX() || y==direccion.getY()){
						break;
					}
				}

				return true;

			}else if(this->posicion.getY() < direccion.getY() && this->posicion.getX()<direccion.getX()){				
				y=this->posicion.getY()+1;
				x=this->posicion.getX()+1;
				
				while(true){					
					if (tablero[y][x] == NULL){
						y++;
						x++;
					} else if (tablero[y][x]!=NULL && tablero[y][x]->getColor()==actual){
						return false;
					}
					if(x == direccion.getX() || y==direccion.getY()){
						break;
					}
				}

				return true;
			}
		
	}else{
		return false;
	}
}

string Alfil::toString()const{
	stringstream ss;
	if (color == 'N'){
		ss << "A";
	}
	else{
		ss << "a";
	}
	return ss.str();
}


