#ifndef PELOTITA_H
#define PELOTITA_H
#include "Pelota.h"
#include <iostream>
#include <conio2.h>
#include <ctime>

using namespace std;


class Comida :  public Pelota
{
	
public:
	Comida(int vel, int col) : Pelota (vel, col){};
	Comida(){};	
	
private:
	

};

#endif

