#include "Juego.h"
#include <ctime>
#include <conio2.h>
#include <windows.h>
#include <time.h>

const int bordeSup = 1;
const int bordeIzq = 1;
const int bordeDer = 80;
const int bordeInf = 20;


Juego::Juego()
{
	viborita =  Viborita(25,14);
	comida =  Comida(20,1);
	tablero = Tablero();
}



bool Juego::comprobarChoque()
{ 
	if ((viborita.getx() == comida.getx()) &&(viborita.gety() == comida.gety()) )
	{   

		viborita.largodecola++;
		return true;
	}
	return false;
}
void Juego::cambiarPosicion()
{   
	if (comprobarChoque() == true)
	{   
		comida.setx(rand()%77 + 1);
		comida.sety(rand()%17 + 1);
	}	
}

void Juego::startComida()
{
	textcolor(comida.getcol());
	
	
	if(comida.gettempo()+comida.getpaso()<clock()){
		comida.borrar();
		cambiarPosicion();
		comida.dibujar();
	    newtempo = comida.gettempo();
		newtempo = clock();
	}
}
bool Juego::GameOver()
{
	if (viborita.getx() == bordeIzq || viborita.getx() == bordeDer || viborita.gety() == bordeSup || viborita.gety() == bordeInf)
	{   textcolor(RED);
		cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "                               PERDISTE   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		return true;		
	}
   if (viborita.chocaContraSi() == true)
	{
		return true;
	}
   return false;
}
void Juego::alargarViborita()
{

	
}


void Juego::startViboritaYPelotita()
{  
	
	
	while (!GameOver())
	{  
		
		tablero.dibujarTablero();		
		viborita.start();
		startComida();
		Sleep(80);
	}
	
}
