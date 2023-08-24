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
	comida =  Comida(20,12);
	tablero = Tablero();
	viborita.setx(2);
	viborita.sety(2);
}



bool Juego::comprobarChoque()
{ 
	if ((viborita.getx() == comida.getx()) &&(viborita.gety() == comida.gety()) )
	{   

		viborita.largodecola++;
		puntaje+=10;
		return true;
	}
	return false;
}
void Juego::cambiarPosicion()
{   
	if (comprobarChoque() == true)
	{   
		comida.setx(rand()%78 + 2);
		comida.sety(rand()%18 + 2);
	}	
}

void Juego::startComida()
{
	textcolor(comida.getcol());
	
	
	if(comida.gettempo()+comida.getpaso()<clock()){
		

		cambiarPosicion();
		comida.borrar();
		
		comida.dibujar();
	    newtempo = comida.gettempo();
		newtempo = clock();
	}
}
bool Juego::GameOver()
{
	if (viborita.getx() == bordeIzq || viborita.getx() == bordeDer || viborita.gety() == bordeSup || viborita.gety() == bordeInf)
	{   textcolor(RED);
		cout <<endl<<endl<<"                          PERDISTE   "<<endl<<endl<<endl;
		return true;		
	}
   if (viborita.chocaContraSi() == true)
	   
	{   textcolor(RED);
		   cout <<endl<<endl<< "                        PERDISTE   "<<endl<<endl<<endl;
		return true;
	}
   return false;
}
void Juego :: mostrarInformacion()
{  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});// para congelar pantalla y parar el flickering
	cout << endl << endl << endl << endl <<endl << endl <<endl << endl <<endl << endl <<endl << endl <<endl << endl <<endl << endl <<endl << endl <<endl << endl << "PUNTAJE: " << puntaje;
	cout << endl << "CONTROLA LA VIBORITA CON LAS FLECHITAS :) ";
	textcolor(GREEN);
	if (puntaje == 2000){cout << endl <<  " ¡¡GANASTE!! "<< endl; ganaste = true;}
	textcolor(BLUE);
}
void Juego::startViboritaYPelotita()
{  
	
	while (!GameOver() && !ganaste)
	{  
		
		tablero.dibujarTablero();		
		viborita.start();
		startComida();
		mostrarInformacion();
		Sleep(60);
	}
	
}
