#include <iostream>
#include <conio2.h>
#include <ctime>
#include <deque>
#ifndef PELOTA_H
#define PELOTA_H
using namespace std;

class Pelota 
{
protected:	
	clock_t tempo;
	clock_t paso;
	int direccionX;
	int direccionY;
	int col;
	int x,y;
	void borrar();
	void dibujar();
	void mover();
	void setx(int posx);
	void sety(int posy);
	/*	int veceschoque = 0;*/
public:
	
	Pelota(int velocidad,int color);
	virtual void start();
	void cambiarDireccion(int dx, int dy);
	string figura = "O";
	int getx ();
	int gety();
	
};

#endif

