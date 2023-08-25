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
	
	
	
public:
	void borrar();
	virtual void dibujar();//virtual para modificar el método en viborita
	void mover();
	Pelota(int velocidad,int color);
	virtual void start();//virtual para modificar el método en viborita
	char figura = 3;
	int getx ();
	int gety();
	void setx(int posx);
	void sety(int posy);
	int getcol();
	clock_t gettempo();
	clock_t getpaso();
	clock_t newtempo;
	Pelota(){};
};

#endif

