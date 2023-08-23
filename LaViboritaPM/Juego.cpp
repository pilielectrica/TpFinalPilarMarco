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
		largodecola++;
		return true;
	}
	return false;
}
void Juego::cambiarPosicion()
{   
	if (comprobarChoque() == true)
	{   
		comida.setx(rand()%79 + 2);
		comida.sety(rand()%19 + 2);
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
//	for (int i = 0; i < largodecola; i++)
//	{
//	     if (poscolaX[i] == viborita.getx() && poscolaY[i] == viborita.gety())
//	     {
//		cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "                               PERDISTE   "<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
//		  return true;
//	     }
//	}
}
void Juego::alargarViborita()
{
	poscolanteriorX = poscolaX[0];
	poscolanteriorY = poscolaY[0];
	
	poscolaX[0] = viborita.getx();
	poscolaY[0] = viborita.gety();
	
	for (int i = 1; i < largodecola; i++)
	{
		poscolanteriorX2 = poscolaX[i];
		poscolanteriorY2 = poscolaY[i];
		
		poscolaX[i] = poscolanteriorX;
		poscolaY[i] = poscolanteriorY;
		
		poscolanteriorX = poscolanteriorX2;
		poscolanteriorY = poscolanteriorY2;
	}
}
void Juego::dibujarCola()
{   for (int i = 0; i < 80; i++)
{   for (int j = 0; i < 20; j++)
{   
	for (int k = 0; k < largodecola; k++)
	{	bool imprimircola = false;
	   if(poscolaX[k] == j && poscolaY[k] == i)
	    {
		  cout << "o";
		  imprimircola = true;
	    }
		if (!imprimircola)
	    {
		  cout << " ";
	    }
	}
}
}
}
void Juego :: startViborita()
{
	textcolor(viborita.getcol());
	
	if(viborita.gettempo()+viborita.getpaso()<clock())
	{   
		viborita.borrar();
		viborita.mover();
		viborita.cambiarDireccion();		
		viborita.dibujar();
		alargarViborita();
		dibujarCola();
		
		int newtempo2 = viborita.gettempo();
		newtempo2 = clock();	
	}
}
void Juego::startViboritaYPelotita()
{  
	
	
	while (!GameOver())
	{  
		
		tablero.dibujarTablero();		
		startViborita();
		startComida();
		Sleep(80);
	}
	
}
