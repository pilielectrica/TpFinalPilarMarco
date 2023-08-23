#include "Viborita.h"
#include <iostream>
#include <conio2.h>
#include <windows.h>
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

//void Viborita :: start()
//{
//	textcolor(col);
//		
//	if(tempo+paso<clock())
//	{
//		borrar();
//		mover();
//		cambiarDireccion();
//		dibujar();
//		tempo=clock();	
//	}
//}
