#ifndef JUEGO_H
#define JUEGO_H
#include "Viborita.h"
#include <iostream>
#include <conio2.h>

class Pelotita;

class Juego
{
public:
	Juego();
	bool comprobarChoque();
	void cambiarPosicion();
	void alargarViborita();
	void startViboritaYPelotita();

private:
	Viborita viborita;
	Pelotita* pelotita;
};

#endif

