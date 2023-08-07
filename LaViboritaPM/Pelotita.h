#ifndef PELOTITA_H
#define PELOTITA_H
#include "Pelota.h"
#include <iostream>
#include <conio2.h>
#include <ctime>
#include <deque>
#include "Viborita.h"

using namespace std;


class Pelotita : public Pelota 
{
public:
	Pelotita(int vel, int col) : Pelota (vel, col){};
	void setViborita(Viborita* pViborita);
	bool comprobarchoque();
	void cambiarposicion();
	void start();
	
private:
	Viborita* posicionViborita;
};

#endif

