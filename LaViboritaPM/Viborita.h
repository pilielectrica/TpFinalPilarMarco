#ifndef VIBORITA_H
#define VIBORITA_H
#include <iostream>
#include <conio2.h>
#include <ctime>
#include <deque>

#include "Pelota.h"
using namespace std;

class Viborita : public Pelota
{
public: 
	Viborita(int vel, int col) : Pelota (vel, col){};
	void cambiarDireccion();
	void start();
	Viborita();
	private:


#endif

