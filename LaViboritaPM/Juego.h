#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <conio2.h>
#include "Viborita.h"
#include "Pelotita.h"




class Juego
{
public:
	Juego(){};
	bool comprobarChoque();
	void cambiarPosicion();
	void alargarViborita();
	void startViboritaYPelotita();

private:
	Viborita viborita;
	Pelotita pelotita;
};

#endif

