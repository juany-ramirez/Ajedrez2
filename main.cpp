#include <iostream>
#include <string>
#include "posicion.h"
#include "pieza.h"
#include "rey.h"
#include "reina.h"
#include "caballo.h"
#include "alfil.h"
#include "torre.h"
#include "peon.h"
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

Pieza*** crearTablero();
void eliminarTablero(Pieza***);
void crearPiezas(Pieza***);
int coordenadaConsonante(char);
bool jaqueMate(Pieza***);
void impresionTablero(Pieza***);
void guardarTablero (Pieza*** tablero);
void abrirTablero(Pieza*** tablero);

int main(int argc, char const *argv[]){
	
	Pieza*** tablero = NULL;
	char jugadorNum= '1';
	bool primerPeonGuardado = false;
	int contadorJugadas=1;
	int x,y,x1,y1;
	
	tablero = crearTablero();

	int turnoJugador=1;
	bool condicionGuardado = true;
	string cambioPieza;
	bool valid;

	char coordenadas[4];

	while(!jaqueMate(tablero)){

		cout<< endl<< endl<<"\t\t\t\t\t\t\t JUGADOR     " << turnoJugador<< endl;
		if(turnoJugador==1)
			cout<< "\t\t\t\t\t\t    ***PIEZAS EN MINUSCULA"<< endl << endl;
		else
			cout<< "\t\t\t\t\t\t    ***PIEZAS EN MAYUSCULA"<< endl << endl;

		impresionTablero(tablero);

		cout<<endl<<"Ingresar coordenadas (Ejemplo - B1B3):\t";
		cin>> coordenadas;

		x = coordenadas[1]-'0';
		y = coordenadaConsonante(coordenadas[0]);
		
		x1 = coordenadas[3]-'0';
		y1 =coordenadaConsonante(coordenadas[2]);

		
		Posicion direccion(x1,y1);
		if(((tablero[y][x]->getColor()=='B' && turnoJugador==1) ||
			(tablero[y][x]->getColor()=='N' && turnoJugador==2)) && tablero[y][x] != NULL) {
			if(tablero[y][x]->movimientoValido(tablero,direccion)){
				tablero[y1][x1] = tablero[y][x];
				tablero[y][x] = NULL;
			}
			else{
				cout << "Movimiento Invalido" << endl;
			}
		}else{
			cout<<"\t\t\tPieza no valida \n";
		}

		if(contadorJugadas%2){			//Turno Jugador 2
			turnoJugador = 1;
			jugadorNum= '1';
		}else{						//Turno Jugador 1
			turnoJugador = 2;
			jugadorNum= '2';
		}

	}

	eliminarTablero(tablero);
	return 0;
}


bool jaqueMate(Pieza*** tablero){
	int cont=0;
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if( dynamic_cast<Rey*>(tablero[i][j]) != NULL){
				cont++;
			}
		}
	}
	if (cont==1)
	{
		return true;
	}
	return false;
}


void eliminarTablero(Pieza*** tablero){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			delete tablero[i][j];
		}		
	}
	for(int i=0;i<8;i++){
		delete[] tablero[i];
	}
	delete[] tablero;
}

Pieza*** crearTablero(){
	Pieza*** tablero = new Pieza**[8];
	for(int i=0;i<8;i++){
		tablero[i]= new Pieza*[8];		
	}
	for(int i=0 ; i<8 ; i++){
		for(int j=0 ; j<8 ; j++){
			tablero[i][j] = NULL;
		}
	}
	crearPiezas(tablero);
	return tablero;
}

void crearPiezas(Pieza*** tablero){
	tablero[0][0] = new Torre('B',0,0);
	tablero[0][7] = new Torre('B',7,0);
	tablero[0][1] = new Caballo('B',1,0);
	tablero[0][6] = new Caballo('B',6,0);
	tablero[0][2] = new Alfil('B',2,0);
	tablero[0][5] = new Alfil('B',5,0);
	tablero[0][3] = new Rey('B',3,0);
	tablero[0][4] = new Reina('B',4,0);
	for (int i = 0; i < 8; ++i){
		tablero[1][i] = new Peon('B',i,1);
	}
	tablero[7][0] = new Torre('N',0,7);
	tablero[7][7] = new Torre('N',7,7);
	tablero[7][1] = new Caballo('N',1,7);
	tablero[7][6] = new Caballo('N',6,7);
	tablero[7][2] = new Alfil('N',2,7);
	tablero[7][5] = new Alfil('N',5,7);
	tablero[7][3] = new Rey('N',3,7);
	tablero[7][4] = new Reina('N',4,7);
	for (int i = 0; i < 8; ++i){
		tablero[6][i] = new Peon('N',i,6);
	}
}

int coordenadaConsonante(char coordenada){
	int fila=0;
	if(coordenada == 'a' || coordenada == 'A')
		return 0;
	if(coordenada == 'b' || coordenada == 'B')
		return 1;
	if(coordenada == 'c' || coordenada == 'C')
		return 2;
	if(coordenada == 'd' || coordenada == 'D')
		return 3;
	if(coordenada == 'e' || coordenada == 'E')
		return 4;
	if(coordenada == 'f' || coordenada == 'F')
		return 5;
	if(coordenada == 'g' || coordenada == 'G')
		return 6;
	if(coordenada == 'h' || coordenada == 'H')
		return 7;
}

void impresionTablero(Pieza*** tablero){//imprimir tablero
	char letras[] = "ABCDEFGH";
	int numeros[] = {1,2,3,4,5,6,7,8};
	cout << "---------------------------------------------------------------------------------------------------------------------------------"<< endl;
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j)	{
			if(tablero[i][j] != NULL)
				cout << "\t" << tablero[i][j]->toString() << "\t|";
			else
				cout << "\t \t|";
		}
		cout << letras[i] << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------"<< endl;
	}
	for (int i = 0; i < 8; ++i)	{
		cout<< "\t" << numeros[i] << "\t";
	}
	cout << endl;
}