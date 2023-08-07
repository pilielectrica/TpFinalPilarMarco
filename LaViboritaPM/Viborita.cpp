#include "Viborita.h"
#include <iostream>
#include <conio2.h>
#include <ctime>
#include <deque>
#include "Pelota.h"
using namespace std;

void Viborita :: cambiarDireccion ()
{
	if (_kbhit())
	{
		int tecla = _getch();
		
		switch(tecla)
		{
		case 72: //arriba
			direccionX = 0;
			direccionY = -1;
			break;	
		case 75: //izquierda
			direccionX = -1;
			direccionY = 0;
			break;
		case 77: //derecha
			direccionX = 1;
			direccionY = 0;
			break;
		case 80: //abajo
			direccionX = 0;
			direccionY = 1;
			
			
		}
	}
}
void Viborita::alargarViborita()
{
	segmentos.push_back(make_pair(getx(), gety())); // Add a new segment to the end of the Viborita
}
void Viborita::mover() 
{
	if (!segmentos.empty()) {
		int lastX = segmentos.back().first;
		int lastY = segmentos.back().second;
		segmentos.pop_back();
		segmentos.push_front(make_pair(getx(), gety()));
		setx(lastX);
		sety(lastY);
	}	
	
	Pelota::mover(); // Call the base class mover() if there are no segments
	
}
void Viborita :: start()
{
	textcolor(col);
	
	
	if(tempo+paso<clock()){
		borrar();	
		mover();
		cambiarDireccion();
		dibujar();
		tempo=clock();
	}
}
