#include <iostream>
#include <conio2.h>
#include <ctime>
#include <deque>
#ifndef VIBORITA_H
#define VIBORITA_H
#include "Pelota.h"
using namespace std;

class Viborita : public Pelota
{
public: 
	Viborita(int vel, int col) : Pelota (vel, col){};
	void cambiarDireccion();
	Viborita();
	void start();
	

};

#endif

