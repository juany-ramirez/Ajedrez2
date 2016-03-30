#include "alfil.h"
#include "pieza.h"
#include "posicion.h"
#include <cmath>
#include <sstream>
#include <iostream>
using std::stringstream;
using std::cout;


Alfil::Alfil(char color,int X,int Y):Pieza(color,X,Y){
	//Se llama al constructor de la clase Pieza
}
bool Alfil::movimientoValido(Pieza***tablero, Posicion direccion){

	int contadorY,contadorX;

	if ((this->posicion.getX()== direccion.getX()) || (this->posicion.getY()== direccion.getY())){
		//verifica que no se mueva a los lados ni verticalmente
		return false;
	}


	if (fabs(this->posicion.getY()-direccion.getY())==fabs(this->posicion.getX()-direccion.getX())){
		
		if (this->getColor() == 'B'){
			if(this->posicion.getY() > direccion.getY() && this->posicion.getX()>direccion.getX()){
				//si la posicion esta en un punto bajo y se quiere mover a la izquierda
				contadorY=this->posicion.getY();
				contadorX=this->posicion.getY();
				

				while(true){
					if (tablero[contadorY][contadorX] == NULL){
						contadorY--;
						contadorX--;

					} else if (tablero[contadorY][contadorX]!=NULL && tablero[contadorY][contadorX]->getColor()=='B'){
						return false;
					}
					if(contadorX == direccion.getX() || contadorY==direccion.getY()){
						break;
					}


				}
				return true;



			}else if(this->posicion.getY() > direccion.getY() && this->posicion.getX()<direccion.getX()){
				//si la posicion esta en un punto bajo y se quiere mover a la derecha
				contadorY=this->posicion.getY();
				contadorX=this->posicion.getY();
				

				while(true){
					
					if (tablero[contadorY][contadorX] == NULL){
						contadorY--;
						contadorX++;

					} else if (tablero[contadorY][contadorX]!=NULL && tablero[contadorY][contadorX]->getColor()=='B'){
						return false;
					}
					if(contadorX == direccion.getX() || contadorY==direccion.getY()){
						break;
					}
				}
				return true;

			}else if(this->posicion.getY() < direccion.getY() && this->posicion.getX()>direccion.getX()){
				//si la posicion esta en un punto alto y se quiere mover a la izquierda
				contadorY=this->posicion.getY();
				contadorX=this->posicion.getY();
				

				while(true){
					
					if (tablero[contadorY][contadorX] == NULL){
						contadorY++;
						contadorX--;

					} else if (tablero[contadorY][contadorX]!=NULL && tablero[contadorY][contadorX]->getColor()=='B'){
						return false;
					}
					if(contadorX == direccion.getX() || contadorY==direccion.getY()){
						break;
					}
				}
				return true;

			}else if(this->posicion.getY() < direccion.getY() && this->posicion.getX()<direccion.getX()){
				// si la posicion esta en un punto alto y se quiere mover a la derecha
				contadorY=this->posicion.getY();
				contadorX=this->posicion.getY();
				

				while(true){
					
					if (tablero[contadorY][contadorX] == NULL){
						contadorY++;
						contadorX++;

					} else if (tablero[contadorY][contadorX]!=NULL && tablero[contadorY][contadorX]->getColor()=='B'){
						return false;
					}
					if(contadorX == direccion.getX() || contadorY==direccion.getY()){
						break;
					}

				}
				return true;
			}
		} else {
			//si el color de esta pieza es Negro

			if(this->posicion.getY() > direccion.getY() && this->posicion.getX()>direccion.getX()){
				//si la posicion esta en un punto bajo y se quiere mover a la izquierda
				contadorY=this->posicion.getY();
				contadorX=this->posicion.getY();
				


				while(true){
					
					if (tablero[contadorY][contadorX] == NULL){
						contadorY--;
						contadorX--;

					} else if (tablero[contadorY][contadorX]!=NULL && tablero[contadorY][contadorX]->getColor()=='N'){
						return false;
					}
					if(contadorX == direccion.getX() || contadorY==direccion.getY()){
						break;
					}

				}
				return true;



			}else if(this->posicion.getY() > direccion.getY() && this->posicion.getX()<direccion.getX()){
				//si la posicion esta en un punto bajo y se quiere mover a la derecha
				contadorY=this->posicion.getY();
				contadorX=this->posicion.getY();

				
				while(true){

					if (tablero[contadorY][contadorX] == NULL){
						contadorY--;
						contadorX++;

					} else if (tablero[contadorY][contadorX]!=NULL && tablero[contadorY][contadorX]->getColor()=='N'){
						return false;
					}
					if(contadorX == direccion.getX() || contadorY==direccion.getY()){
						break;
					}

				}
				
				return true;

			}else if(this->posicion.getY() < direccion.getY() && this->posicion.getX()>direccion.getX()){
				//si la posicion esta en un punto alto y se quiere mover a la izquierda
				contadorY=this->posicion.getY();
				contadorX=this->posicion.getY();

				

				while(true){
					
					if (tablero[contadorY][contadorX] == NULL){
						contadorY++;
						contadorX--;

					} else if (tablero[contadorY][contadorX]!=NULL && tablero[contadorY][contadorX]->getColor()=='N'){
						return false;
					}
					if(contadorX == direccion.getX() || contadorY==direccion.getY()){
						break;
					}

				}
				
				return true;

			}else if(this->posicion.getY() < direccion.getY() && this->posicion.getX()<direccion.getX()){
				// si la posicion esta en un punto alto y se quiere mover a la derecha
				contadorY=this->posicion.getY();
				contadorX=this->posicion.getY();
				

				while(true){
					
					if (tablero[contadorY][contadorX] == NULL){
						contadorY++;
						contadorX++;

					} else if (tablero[contadorY][contadorX]!=NULL && tablero[contadorY][contadorX]->getColor()=='N'){
						return false;
					}
					if(contadorX == direccion.getX() || contadorY==direccion.getY()){
						break;
					}

				}
				return true;
			}

		}
		
	}else{
		return false;
	}

}

bool Alfil::movimientoHacia(Pieza*** tablero, Posicion direccion){
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


