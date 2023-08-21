#include "Juego.h"
#include <ctime>

Juego::Juego()
{
	viborita =  Viborita(20,14);
	comida =  Comida(30,1);
	tablero = Tablero();
}



bool Juego::comprobarChoque()
{ 
	if ((viborita.getx() == comida.getx()) &&(viborita.gety() == comida.gety()) )
	{
		return true;
	}
	return false;
}
void Juego::cambiarPosicion()
{
	if (comprobarChoque() == true)
	{
		comida.setx(rand()%80 + 2);
		comida.sety(rand()%20 + 2);
	}	
}

void Juego::startComida(){
	textcolor(comida.getcol());
	
	
	if(comida.gettempo()+comida.getpaso()<clock()){
		comida.borrar();
		cambiarPosicion();
		comida.dibujar();
	    newtempo = comida.gettempo();
		newtempo = clock();
	}
}

void Juego::startViboritaYPelotita()
{  
	
	
	while (true)
	{   
		tablero.dibujarTablero();
		viborita.start();
		startComida();
	}
	
}
