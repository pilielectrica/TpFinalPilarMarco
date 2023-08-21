#ifndef PELOTA_H
#define PELOTA_H
#include <iostream>
#include <conio2.h>
#include <ctime>
#include <string>


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
	
	Pelota(){};
	
	/*	int veceschoque = 0;*/
public:
	void borrar();
	void dibujar();
	void mover();
	Pelota(int velocidad,int color);
	virtual void start();
	string figura = "O";
	int getx ();
	int gety();
	void setx(int posx);
	void sety(int posy);
	int getcol();
	clock_t gettempo();
	clock_t getpaso();
	clock_t newtempo;
};

#endif

