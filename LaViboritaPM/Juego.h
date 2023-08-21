#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <conio2.h>
#include <ctime>
#include "Viborita.h"
#include "Comida.h"
#include "Tablero.h"




class Juego
{
public:
	Juego();
	bool comprobarChoque();
	void cambiarPosicion();
	void alargarViborita();
	void startViboritaYPelotita();
	void startComida();

private:
	Viborita viborita;
	Comida comida;
	
	Tablero tablero;
	clock_t newtempo;
};

#endif

