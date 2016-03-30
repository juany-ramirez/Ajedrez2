partida.exe:	main.o posicion.o pieza.o rey.o reina.o torre.o alfil.o caballo.o peon.o
	g++ main.o posicion.o pieza.o rey.o reina.o torre.o alfil.o caballo.o peon.o -o partida 
	
main.o:	main.cpp posicion.h pieza.h rey.h reina.h torre.h alfil.h caballo.h peon.h
	g++ -c main.cpp

posicion.o:	posicion.cpp posicion.h
	g++ -c posicion.cpp

pieza.o:	pieza.cpp pieza.h posicion.h
	g++ -c pieza.cpp

rey.o:	rey.cpp rey.h pieza.h posicion.h
	g++ -c rey.cpp

reina.o:	reina.cpp reina.h pieza.h posicion.h torre.h alfil.h
	g++ -c reina.cpp

torre.o:	torre.cpp torre.h pieza.h posicion.h
	g++ -c torre.cpp

alfil.o:	alfil.cpp alfil.h pieza.h posicion.h
	g++ -c alfil.cpp

caballo.o:	caballo.cpp caballo.h pieza.h posicion.h
	g++ -c caballo.cpp

peon.o:	peon.cpp peon.h pieza.h posicion.h
	g++ -c peon.cpp

clean:
	rm *.o partida
