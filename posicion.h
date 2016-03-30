#pragma once
#include <string>

using std::string;

class Posicion{
	private:
		int x; //row
		int y; //column
	public:
		Posicion(int = 0,int = 0);
		string toString()const;
		const Posicion& operator=(const Posicion&);
		const int getX()const;
		const int getY()const;
		int setX(int);
		int setY(int);
};
