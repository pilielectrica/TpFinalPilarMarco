#ifndef JUEGO_H
#define JUEGO_H
#include "Pelota.h"
#include "Viborita.h"
#include "Pelotita.h"

class Juego : public Pelotita
{
public:
	Juego() : Pelotita(){};
	bool comprobarChoque();
	void cambiarPosicion();
	void alargarViborita();

private:
	Viborita viborita;
	Pelotita pelotita;
};

#endif

