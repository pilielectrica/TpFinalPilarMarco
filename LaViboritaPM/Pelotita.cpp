#include "Pelotita.h"
#include <iostream>
#include <conio2.h>
#include <ctime>
#include <deque>

using namespace std;

void Pelotita::setViborita(Viborita* pViborita) 
{
	posicionViborita = pViborita;
}

bool Pelotita::comprobarchoque()
{
	if ((posicionViborita->getx() == getx()) &&(posicionViborita->gety() == gety()) )
	{
		return true;
	}
	return false;
}
void Pelotita::cambiarposicion()
{
	if (comprobarchoque() == true)
	{setx(rand()%80 + 1);
	sety(rand()%20 + 1);
	};
}
void Pelotita::start(){
	textcolor(col);
	
	
	if(tempo+paso<clock()){
		borrar();
		if (comprobarchoque())
		{
	    posicionViborita->alargarViborita();
		cambiarposicion();
		}
		dibujar();
		tempo=clock();
	}
}
