#ifndef VIBORITA_H
#define VIBORITA_H
#include <iostream>
#include <conio2.h>
#include <ctime>

#include "Pelota.h"
using namespace std;

class Viborita : public Pelota
{
public: 
	Viborita(int vel, int col) : Pelota (vel, col){};
	void cambiarDireccion();
	void dibujar();
	void start();
	void guardarPosicion();
	void setlargodecola(int larcol);
	Viborita(){};
	int largodecola = 6;
	bool chocaContraSi();
	
private:
	int posicionCuerpo[200][2];
	
	int indiceParaMovimiento = 1;

};
#endif

