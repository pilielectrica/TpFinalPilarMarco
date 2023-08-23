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
	bool GameOver();
	void dibujarCola();
	void startViborita();

private:
	Viborita viborita;
	Comida comida;	
	Tablero tablero;
	clock_t newtempo;
	int poscolanteriorX;
	int poscolanteriorY;
	int poscolanteriorX2;
	int poscolanteriorY2;
	int poscolaX[100];
	int poscolaY[100];
	int largodecola;
};

#endif

