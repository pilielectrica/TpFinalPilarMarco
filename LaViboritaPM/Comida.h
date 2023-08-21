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
	/*void setViborita(Viborita* pViborita);*/
//	bool comprobarchoque();
  /*  void cambiarposicion();*/
	/*void start();*/
	Comida(){};
	
	
private:

};

#endif

